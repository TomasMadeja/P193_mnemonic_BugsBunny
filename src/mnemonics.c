#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <openssl/evp.h>

#include "errorcodes.h"
#include "mnemonics.h"

#define SHA2_BLOCK_SIZE 128
#define SHA512_DIGEST_SIZE 64


int init_mnemonics(void) {
    OpenSSL_add_all_algorithms();
    return EC_OK;
}

int append_sha256_bytes(unsigned char *bytes, size_t entropy_l) {

    #define SHA256_DIGEST_SIZE 32

    unsigned char hash[SHA256_DIGEST_SIZE];
    EVP_MD_CTX *ctx;
    if ((ctx = EVP_MD_CTX_create()) == NULL) return EC_OPENSSL_ERROR;
    if (EVP_DigestInit(ctx, EVP_sha256()) != 1) return EC_OPENSSL_ERROR;
    if (EVP_DigestUpdate(ctx, bytes, entropy_l) != 1) return EC_OPENSSL_ERROR;
    if (EVP_DigestFinal(ctx, hash, NULL) != 1) return EC_OPENSSL_ERROR;

    EVP_MD_CTX_destroy(ctx);

    bytes[entropy_l] = hash[0];

    return EC_OK;
}

int entropy_to_mnemonic(const struct dictionary *dictionary,
                        const unsigned char *entropy,
                        size_t entropy_l,
                        unsigned char **output) {

    if (entropy == NULL) {
        return EC_NULL_POINTER;
    }
    if (entropy_l % 4 != 0) {
        return EC_ENTROPY_LENGTH_NOT_MULTIPLE_OF_4;
    }

    if (entropy_l < 16 || entropy_l > 32) {
        return EC_ENTROPY_LENGTH_NOT_WITHIN_16_32;
    }

    const struct dictionary *dict = dictionary;

    if (dictionary == NULL) {
        dict = default_EN_dictionary();
    }

    unsigned char *bytes = malloc(entropy_l + 1);
    if (bytes == NULL) {
        return EC_ALLOCATION_ERROR;
    }

    memcpy(bytes, entropy, entropy_l);

    if (append_sha256_bytes(bytes, entropy_l) != 0) {
        return EC_OPENSSL_ERROR;
    }

    size_t capacity = 256;
    size_t len = 0;
    unsigned char* out = malloc(capacity);
    if (out == NULL) {
        free(bytes);
        return EC_ALLOCATION_ERROR;
    }

    size_t bits = 0;
    while (bits < entropy_l * 8 + entropy_l * 8 / 32) {

        out[len] = ' ';
        len++;
        if (bits == 0) {
            len--;
        }

        size_t position = bits / 8;
        uint32_t joint = ((uint32_t) bytes[position]) << 24;
        joint ^= ((uint32_t) bytes[position + 1]) << 16;
        joint ^= ((uint32_t) bytes[position + 2]) << 8;
        joint <<= bits % 8;
        joint >>= 32 - 11;

        if (len + strlen((char*) (dict->words[joint])) + 1 >= capacity) {
            capacity *= 2;
            unsigned char *temp = realloc(out, capacity);
            if (temp == NULL) {
                free(bytes);
                free(out);
                return EC_ALLOCATION_ERROR;
            }
            out = temp;
        }
        sprintf((char*) out + len, "%s", dict->words[joint]);
        len += strlen((char*) (dict->words[joint]));

        bits += 11;
    }

    *output = out;
    free(bytes);

    return (int) len;
}

int sha512(const unsigned char *message, size_t message_l, unsigned char *out) {

    EVP_MD_CTX *ctx;
    if ((ctx = EVP_MD_CTX_create()) == NULL) return EC_OPENSSL_ERROR;
    if (EVP_DigestInit(ctx, EVP_sha512()) != 1) return EC_OPENSSL_ERROR;
    if (EVP_DigestUpdate(ctx, message, message_l) != 1) return EC_OPENSSL_ERROR;
    if (EVP_DigestFinal(ctx, out, NULL) != 1) return EC_OPENSSL_ERROR;

    EVP_MD_CTX_destroy(ctx);
    return EC_OK;
}

void array_128_pad(unsigned char array[128], unsigned char pad) {
    for (uint8_t i = 0; i < 128; i++) {
        array[i] ^= pad;
    }
}

int hmac_sha512(const unsigned char *key, size_t key_l,
                const unsigned char *message, size_t message_l,
                unsigned char *out) {

    #define IPAD 0x36
    #define OPAD 0x5c

    unsigned char key_ipad[SHA2_BLOCK_SIZE];
    unsigned char key_opad[SHA2_BLOCK_SIZE];

    int ret = 0;

    if (key_l <= SHA2_BLOCK_SIZE) {
        memcpy(key_ipad, key, key_l);
        memset(key_ipad + key_l, 0, SHA2_BLOCK_SIZE - key_l);
    } else {
        ret = sha512(key, key_l, key_ipad);
        if (ret != EC_OK) {
            return ret;
        }
    }
    memcpy(key_opad, key_ipad, SHA2_BLOCK_SIZE);


    array_128_pad(key_ipad, IPAD);
    array_128_pad(key_opad, OPAD);

    unsigned char *digest_inner = malloc(message_l + SHA2_BLOCK_SIZE);
    if (digest_inner == NULL) {
        return EC_ALLOCATION_ERROR;
    }
    unsigned char *digest_outer = malloc(SHA2_BLOCK_SIZE + SHA512_DIGEST_SIZE);
    if (digest_outer == NULL) {
        free(digest_inner);
        return EC_ALLOCATION_ERROR;
    }

    memcpy(digest_inner, key_ipad, SHA2_BLOCK_SIZE);
    memcpy(digest_inner + SHA2_BLOCK_SIZE, message, message_l);

    ret = sha512(digest_inner, message_l + SHA2_BLOCK_SIZE, digest_outer + SHA2_BLOCK_SIZE);
    if (ret != EC_OK) {
        free(digest_inner);
        free(digest_outer);
        return ret;
    }

    memcpy(digest_outer, key_opad, SHA2_BLOCK_SIZE);

    ret = sha512(digest_outer, SHA2_BLOCK_SIZE + SHA512_DIGEST_SIZE, out);

    free(digest_inner);
    free(digest_outer);
    return ret;
}

void array_64_xor(uint8_t dst[64], uint8_t src[64]) {
    for (uint8_t i = 0; i < 64; i++) {
        dst[i] ^= src[i];
    }
}

int pbkdf2_hmac_sha512_2048(const unsigned char *input, size_t input_l,
                            const unsigned char *salt, size_t salt_l,
                            unsigned char *out) {

    #define BIG_ENDIAN_ZERO "\x00\x00\x00\x01"
    #define ROUNDS 2048

    unsigned char dk[SHA512_DIGEST_SIZE];
    unsigned char u[SHA512_DIGEST_SIZE];
    unsigned char *salt_and_int = malloc(salt_l + 4);
    if (salt_and_int == NULL) {
        return EC_ALLOCATION_ERROR;
    }

    memcpy(salt_and_int, salt, salt_l);
    memcpy(salt_and_int + salt_l, BIG_ENDIAN_ZERO, 4);

    int ret = 0;

    ret = hmac_sha512(input, input_l, salt_and_int, salt_l + 4, dk);
    free(salt_and_int);

    if (ret != 0) {
        return ret;
    }

    memcpy(u, dk, SHA512_DIGEST_SIZE);

    for (uint16_t i = 0; i < ROUNDS - 1; i++) {
        ret = hmac_sha512(input, input_l, u, SHA512_DIGEST_SIZE, u);
        if (ret != 0) {
            return ret;
        }
        array_64_xor(dk, u);
    }

    memcpy(out, dk, SHA512_DIGEST_SIZE);

    return EC_OK;
}

int mnemonic_to_seed(const unsigned char *mnemonic,
                     size_t mnemonic_l,
                     const unsigned char *passphrase,
                     size_t passphrase_l,
                     unsigned char **seed) {

    if (mnemonic == NULL) {
        return EC_NULL_POINTER;
    }

    const unsigned char *pass = passphrase;
    size_t pass_l = passphrase_l;

    if (passphrase == NULL) {
        pass = (const unsigned char*) "";
        pass_l = 0;
    }

    unsigned char *salt = malloc(pass_l + 8);
    if (salt == NULL) {
        return EC_ALLOCATION_ERROR;
    }

    memcpy(salt, "mnemonic", 8);
    memcpy(salt + 8, pass, pass_l);

    unsigned char *out = malloc(SHA512_DIGEST_SIZE);
    if (out == NULL) {
        free(salt);
        return EC_ALLOCATION_ERROR;
    }

    int ret = pbkdf2_hmac_sha512_2048(mnemonic, mnemonic_l, salt, passphrase_l + 8, out);

    free(salt);

    if (ret != 0) {
        free(out);
        return ret;
    }

    *seed = out;
    return EC_OK;
}

uint8_t next_word_size(const unsigned char *string) {
    uint8_t i = 0;
    for (; string[i] != 255; i++) {
        if (string[i] == ' ' || string[i] == '\0') {
            return i;
        }
    }
    return 0;
}

int strcmp_to_space(const void *a, const void *b) {
    size_t i = 0;
    size_t j = 0;
    const unsigned char *x = *((const unsigned char* const*) a);
    const unsigned char *y = *((const unsigned char* const*) b);
    while (x[i] != '\0' && x[i] != ' ') {
        i++;
    }
    while (y[j] != '\0' && y[j] != ' ') {
        j++;
    }
    if (j > i) {
        i = j;
    }
    return strncmp((const char*) x, (const char*) y, i);
}

int mnemonic_to_entropy(const struct dictionary *dictionary,
                        const unsigned char *mnemonic,
                        size_t mnemonic_l,
                        unsigned char **entropy,
                        size_t *entropy_l) {

    if (mnemonic == NULL) {
        return EC_NULL_POINTER;
    }

    const struct dictionary *dict = dictionary;

    if (dictionary == NULL) {
        dict = default_EN_dictionary();
    }

    uint8_t word_count = 1;
    for (size_t i = 0; i < mnemonic_l; i++) {
        if (mnemonic[i] == ' ') {
            word_count++;
        }
    }
    *entropy_l = (word_count * 11 - 1) / 8;

    size_t position = 0;
    uint16_t indexes[25];
    indexes[word_count] = 0x0;

    for (uint8_t i = 0; i < word_count; i++) {
        uint8_t word_len = next_word_size(mnemonic + position);
        const unsigned char *key = mnemonic + position;
        unsigned char **result = bsearch(&key, dict->words, 2048,
                                         sizeof (unsigned char *),
                                         strcmp_to_space);

        indexes[i] =  (uint16_t) (result - dict->words);
        position += word_len + 1;
    }

    unsigned char *out = malloc(*entropy_l);
    if (out == NULL) {
        return EC_ALLOCATION_ERROR;
    }

    for (size_t i = 0; i < *entropy_l; i++) {
        size_t bits = 8 * i;
        uint32_t joint = ((uint32_t) indexes[bits / 11]) << 11;
        joint ^= (uint32_t) indexes[bits / 11 + 1];
        joint <<= 10 + bits % 11;
        joint >>= 32 - 8;
        out[i] = (uint8_t) joint;
    }

    *entropy = out;
    return EC_OK;
}
