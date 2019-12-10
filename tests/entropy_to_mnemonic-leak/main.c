#include "../../src/mnemonics.h"
#include "../../src/errorcodes.h"
#include <stdio.h>

int main()
{
    // prepare a entropy, does not really matter as long
    // as it is a valid input into entropy_to_mnemonic function
    unsigned char entropy[] = {
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00
    };
    size_t entropy_len = 16;
    unsigned char *output;

    // call the function containing the leak
    entropy_to_mnemonic(
            NULL,
            entropy,
            entropy_len,
            &output
    );
    return 0;
}
