#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <openssl/evp.h>
#include <openssl/sha.h>

#include "mnemonics.h"


#define UNUSED(x) (void)(x)

/*void printHex(unsigned char *bytes, size_t len) {
    for (size_t i = 0; i < len; i++) {
        printf("%02x ", bytes[i]);
    }
    printf("\n");
}*/

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

uint32_t pow2(uint8_t exp) {
    uint32_t res = 0x1;
    return res << exp;
}

int to_mnemonic(const struct dictionary *dict,
                const unsigned char *entropy, size_t entropy_l,
                const unsigned char *delim, size_t delim_l,
                unsigned char **output) {

    UNUSED(delim_l);

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

        out[len] = *delim;
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

    return 0;
}
