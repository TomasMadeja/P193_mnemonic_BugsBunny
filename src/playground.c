#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#include "mnemonics.h"

void printHex(unsigned char *bytes, size_t len) {
    for (size_t i = 0; i < len; i++) {
        printf("%02x", bytes[i]);
    }
    printf("\n");
}

int main(void) {

    #define TEST_VECTOR_LEN 24
    unsigned char input_entropy[TEST_VECTOR_LEN] =
            "\x66\x10\xb2\x59\x67\xcd\xcc\xa9"
            "\xd5\x98\x75\xf5\xcb\x50\xb0\xea"
            "\x75\x43\x33\x11\x86\x9e\x93\x0b";

    unsigned char *mnemonic;
    unsigned char *seed;
    unsigned char *check_entropy;
    size_t check_entropy_size;

    init_mnemonics();
    entropy_to_mnemonic(NULL, input_entropy, TEST_VECTOR_LEN, &mnemonic);
    mnemonic_to_seed(mnemonic, strlen((char*) mnemonic),
                     (unsigned char*) "TREZOR", 6, &seed);
    mnemonic_to_entropy(NULL,
                        mnemonic, strlen((char*) mnemonic),
                        &check_entropy, &check_entropy_size);

    printHex(input_entropy, TEST_VECTOR_LEN);
    printf("%s\n", mnemonic);
    printHex(seed, 64);
    printHex(check_entropy, check_entropy_size);

    free(mnemonic);
    free(seed);
    free(check_entropy);
    
    return EXIT_SUCCESS;
}
