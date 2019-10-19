#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mnemonics.h"


int main(void) {
    unsigned char bytes[16] = "\xc0\xba\x5a\x8e\x91\x41\x11\x21\x0f\x2b\xd1\x31\xf3\xd5\xe0\x8d";

    struct dictionary dict[1];
    default_EN_dictionary(dict);
    unsigned char *out;
    entropy_to_mnemonic(dict, bytes, 16, &out);

    printf("%s\n", out);
    
    return EXIT_SUCCESS;
}
