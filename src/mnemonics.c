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

    unsigned char hash[SHA_DIGEST_LENGTH];
    unsigned int size = SHA_DIGEST_LENGTH;
    EVP_MD_CTX *ctx;
    if ((ctx = EVP_MD_CTX_create()) == NULL) return 1;
    if (EVP_DigestInit_ex(ctx, EVP_sha256(), NULL) != 1) return 1;
    if (EVP_DigestUpdate(ctx, bytes, entropy_l) != 1) return 1;
    if (EVP_DigestFinal_ex(ctx, hash, &size) != 1) return 1;

    memcpy(bytes + entropy_l, hash, 1);

    return 0;
}

int entropy_to_mnemonic(const struct dictionary *dictionary,
                        const unsigned char *entropy,
                        size_t entropy_l,
                        unsigned char **output) {

    const struct dictionary *dict = dictionary;

    if (dictionary == NULL) {
        dict = default_EN_dictionary();
    }

    unsigned char *bytes = malloc(entropy_l + 1);
    memcpy(bytes, entropy, entropy_l);

    if (append_sha256_bytes(bytes, entropy_l) != 0) {
        return 1;
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

    if (PKCS5_PBKDF2_HMAC((const char*) mnemonic, (int) mnemonic_l,
                          salt, (int) passphrase_l + 8, 2048,
                          EVP_sha512(), 64, out) != 1) {
        return 1;
    }

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
