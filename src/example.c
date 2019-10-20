#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mnemonics.h"

void printHex(unsigned char *bytes, size_t len) {
    for (size_t i = 0; i < len; i++) {
        printf("%02x", bytes[i]);
    }
    printf("\n");
}

int main(void) {

    init_mnemonics();
    printf("Hello world!\n");

    
    return EXIT_SUCCESS;
}
