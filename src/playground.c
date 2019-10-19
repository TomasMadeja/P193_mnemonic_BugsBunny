#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#include "mnemonics.h"

void printHex(unsigned char *bytes, size_t len) {
    for (size_t i = 0; i < len; i++) {
        printf("%02x ", bytes[i]);
    }
    printf("\n");
}

int main(void) {

    OpenSSL_add_all_algorithms();

    unsigned char bytes[16] = "\xc0\xba\x5a\x8e\x91\x41\x11\x21\x0f\x2b\xd1\x31\xf3\xd5\xe0\x8d";

    struct dictionary dict[1];
    default_EN_dictionary(dict);
    unsigned char *mne;
    unsigned char *seed;
    entropy_to_mnemonic(dict, bytes, 16, &mne);
    mnemonic_to_seed(mne, strlen((char*) mne), (unsigned char*)"TREZOR", 6, &seed);
    printf("%s\n", mne);
    printHex(seed, 64);

    
    return EXIT_SUCCESS;
}
