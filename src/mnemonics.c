#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <openssl/evp.h>
#include <openssl/sha.h>

#include "mnemonics.h"

int init_mnemonics(void) {
    OpenSSL_add_all_algorithms();
    return 0;
}

int append_sha256_bytes(unsigned char *bytes, size_t entropy_l) {

    unsigned char hash[32];
    EVP_MD_CTX *ctx;
    if ((ctx = EVP_MD_CTX_create()) == NULL) return -1;
    if (EVP_DigestInit(ctx, EVP_sha256()) != 1) return -1;
    if (EVP_DigestUpdate(ctx, bytes, entropy_l) != 1) return -1;
    if (EVP_DigestFinal(ctx, hash, NULL) != 1) return -1;

    EVP_MD_CTX_destroy(ctx);

    memcpy(bytes + entropy_l, hash, 1);

    return 0;
}

int entropy_to_mnemonic(const struct dictionary *dictionary,
                        const unsigned char *entropy,
                        size_t entropy_l,
                        unsigned char **output) {

    if (entropy_l % 4 != 0) {
        return -1;
    }

    const struct dictionary *dict = dictionary;

    if (dictionary == NULL) {
        dict = default_EN_dictionary();
    }

    unsigned char *bytes = malloc(entropy_l + 1);
    memcpy(bytes, entropy, entropy_l);

    if (append_sha256_bytes(bytes, entropy_l) != 0) {
        return -1;
    }

    size_t capacity = 256;
    size_t len = 0;
    unsigned char* out = malloc(capacity);

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
            out = realloc(out, capacity);
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
    if ((ctx = EVP_MD_CTX_create()) == NULL) return -1;
    if (EVP_DigestInit(ctx, EVP_sha512()) != 1) return -1;
    if (EVP_DigestUpdate(ctx, message, message_l) != 1) return -1;
    if (EVP_DigestFinal(ctx, out, NULL) != 1) return -1;

    EVP_MD_CTX_destroy(ctx);
    return 0;
}

void array_128_pad(unsigned char array[128], unsigned char pad) {
    for (uint8_t i = 0; i < 128; i++) {
        array[i] ^= pad;
    }
}

int hmac_sha512(const unsigned char *key, size_t key_l,
                const unsigned char *message, size_t message_l,
                unsigned char *out) {

    unsigned char key_ipad[128];
    unsigned char key_opad[128];

    if (key_l <= 128) {
        memcpy(key_ipad, key, key_l);
        memset(key_ipad + key_l, 0, 128 - key_l);
    } else {
        sha512(key, key_l, key_ipad);
    }
    memcpy(key_opad, key_ipad, 128);


    array_128_pad(key_ipad, 0x36);
    array_128_pad(key_opad, 0x5c);

    unsigned char *digest_inner = malloc(message_l + 128);
    unsigned char *digest_outer = malloc(192);

    memcpy(digest_inner, key_ipad, 128);
    memcpy(digest_inner + 128, message, message_l);

    sha512(digest_inner, message_l + 128, digest_outer + 128);
    memcpy(digest_outer, key_opad, 128);

    sha512(digest_outer, 192, out);

    free(digest_inner);
    free(digest_outer);
    return 0;
}

void array_64_xor(uint8_t dst[64], uint8_t src[64]) {
    for (uint8_t i = 0; i < 64; i++) {
        dst[i] ^= src[i];
    }
}

int pbkdf2_hmac_sha512_2048(const unsigned char *input, size_t input_l,
                            const unsigned char *salt, size_t salt_l,
                            unsigned char *out) {

    unsigned char dk[64];
    unsigned char u[64];
    unsigned char *salt_and_int = malloc(salt_l + 4);
    memcpy(salt_and_int, salt, salt_l);
    memcpy(salt_and_int + salt_l, "\x00\x00\x00\x01", 4);

    hmac_sha512(input, input_l, salt_and_int, salt_l + 4, dk);
    free(salt_and_int);

    memcpy(u, dk, 64);

    for (uint16_t i = 0; i < 2047; i++) {
        hmac_sha512(input, input_l, u, 64, u);
        array_64_xor(dk, u);
    }

    memcpy(out, dk, 64);

    return 0;
}

int mnemonic_to_seed(const unsigned char *mnemonic,
                     size_t mnemonic_l,
                     const unsigned char *passphrase,
                     size_t passphrase_l,
                     unsigned char **seed) {

    unsigned char *salt = malloc(passphrase_l + 8);
    memcpy(salt, "mnemonic", 8);
    memcpy(salt + 8, passphrase, passphrase_l);
    unsigned char *out = malloc(64);

    pbkdf2_hmac_sha512_2048(mnemonic, mnemonic_l, salt, passphrase_l + 8, out);

    free(salt);
    *seed = out;
    return 0;
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
    const unsigned char *x = *((const unsigned char* const*) a);
    const unsigned char *y = *((const unsigned char* const*) b);
    while (x[i] != ' ' && x[i] != '\0' &&
           y[i] != ' ' && y[i] != '\0') {
        i++;
    }
    return strncmp((const char*) x, (const char*) y, i);
}

int mnemonic_to_entropy(const struct dictionary *dictionary,
                        const unsigned char *mnemonic,
                        size_t mnemonic_l,
                        unsigned char **entropy,
                        size_t *entropy_l) {

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

    for (size_t i = 0; i < *entropy_l; i++) {
        size_t bits = 8 * i;
        uint32_t joint = ((uint32_t) indexes[bits / 11]) << 11;
        joint ^= (uint32_t) indexes[bits / 11 + 1];
        joint <<= 10 + bits % 11;
        joint >>= 32 - 8;
        out[i] = (uint8_t) joint;
    }

    *entropy = out;
    return 0;
}
