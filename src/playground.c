#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mnemonics.h"
#include "errorcodes.h"

void printHex(unsigned char *bytes, size_t len) {
    for (size_t i = 0; i < len; i++) {
        printf("%02x", bytes[i]);
    }
    printf("\n");
}

int main(void) {

    #define TEST_VECTOR_LEN 32
    unsigned char input_entropy[TEST_VECTOR_LEN] = {
            0xf5,0x85,0xc1,0x1a,0xec,0x52,0x0d,0xb5,0x7d,0xd3,0x53,0xc6,0x95,0x54,0xb2,0x1a,0x89,0xb2,0x0f,0xb0,0x65,0x09,0x66,0xfa,0x0a,0x9d,0x6f,0x74,0xfd,0x98,0x9d,0x8f
};

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

    int ret = 0;
    if ((ret = check_phrase_seed(mnemonic, strlen((char*) mnemonic),
                          (unsigned char*) "TREZOR", 6,
                          seed)) == EC_OK) {
        printf("OK\n");
    } else {
        printf("NOK\n");
        parse_error(stdout, ret);
    }

    free(mnemonic);
    free(seed);
    free(check_entropy);

    return EXIT_SUCCESS;
}
