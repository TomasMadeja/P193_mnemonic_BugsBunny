#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "mnemonics.h"

int append_sha256_bytes(unsigned char *bytes, size_t entropy_l) {
    //TODO
    memset(bytes + entropy_l, bytes[0], entropy_l / 32);
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

    unsigned char *bytes = malloc(entropy_l + entropy_l / 32);
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
