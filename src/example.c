#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mnemonics.h"

void printHex(unsigned char *bytes, size_t len) {
    for (size_t i = 0; i < len; i++) {
        printf("%02x", bytes[i]);
    }
}

int main(void) {

    /* Defining an example input entropy */
    #define TEST_VECTOR_LEN 24
    unsigned char input_entropy[TEST_VECTOR_LEN] =
        "\x66\x10\xb2\x59\x67\xcd\xcc\xa9"
        "\xd5\x98\x75\xf5\xcb\x50\xb0\xea"
        "\x75\x43\x33\x11\x86\x9e\x93\x0b";

    /* Initializing the API. */
    init_mnemonics();


    /* ENTROPY -> MNEMONIC */

    unsigned char *mnemonic;

    /* Converting entropy to a mnemonic phrase using the default dictionary. */
    entropy_to_mnemonic(NULL, input_entropy, TEST_VECTOR_LEN, &mnemonic);

    /* Printing the mnemonic phrase. */
    printf("ENTROPY -> MNEMONIC\n");
    printf("The mnemonic phrase for the entropy ");
    printHex(input_entropy, TEST_VECTOR_LEN);
    printf(" is:\n%s\n\n", mnemonic);


    /* MNEMONIC -> SEED */

    unsigned char *seed;

    /* Converting the mnemonic phrase to seed. */
    mnemonic_to_seed(mnemonic, strlen((char*) mnemonic),
                     (unsigned char*) "TREZOR", 6, &seed);

    /* Printing the seed. */
    printf("MNEMONIC -> SEED\n");
    printf("The seed for the mnemonic phrase\n%s\nis:\n", mnemonic);
    printHex(seed, 64);
    printf("\n\n");


    /* MNEMONIC - ENTROPY CHECK */

    unsigned char *check_entropy;
    size_t check_entropy_size;
    int return_code;

    /* Checking if the given mnemonic is the correct one for the input
     * entropy using the default dictionary. */
    return_code = mnemonic_to_entropy(NULL,
                        mnemonic, strlen((char*) mnemonic),
                        &check_entropy, &check_entropy_size);

    /* Printing out the result. */
    printf("MNEMONIC - ENTROPY CHECK\n");
    if (return_code == 0) {
        printf("The given mnemonic-entropy pair is correct.\n\n");
    } else {
        printf("Something went wrong. Error code: %d\n\n", return_code);
    }
    

    /* Free the allocated variables. */
    free(mnemonic);
    free(seed);
    free(check_entropy);

    return EXIT_SUCCESS;
}
