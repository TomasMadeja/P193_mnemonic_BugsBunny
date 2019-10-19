#ifndef MNEMONICS_H
#define MNEMONICS_H


#include <stdlib.h>


struct dictionary {
    unsigned char *words[2048];
};

/**
@dict initialized dictionary used to generate mnemonics
@bytes buffer containing entropy bytes used to generate mnemonics
@bytes_l size of input buffer, must be multiple of 4 bytes
@output address that will recieve newly allocated delim separated mnemonics
@output_l address that will recieve size of the output
@delim delimiter to be used to separate words in output.
  One in {'\n', ',' , ';' , ' ' } (newline, comma, semicolon, space).
@delim_l delimeter length (without '\0')

@return 0 IF success ELSE negative error code
*/
int to_mnemonic(const struct dictionary *dict,
                const unsigned char *bytes, size_t bytes_l,
                const unsigned char *delim, size_t delim_l,
                unsigned char *output, size_t *output_l);

/**
@dict initialized dictionary used to generate mnemonics
@mnemonic buffer containing bytes used to generate mnemonics, must be multiple of 11 bits
@mnemonic_l size of the mnemonic string
@delim delimiter used to separate words in mnemonic. One in {'\n', ',' , ';' , ' ' } (newline, single whitespace, comma, semicolon).
@delim_l delimeter length (without '\0')
@seed_output address that will recieve newly allocated bytes output
@seed_output_l address that will recieve size of output
@entropy_output set to NULL to not generate entropy
@entropy_output_l

@return 0 IF success ELSE negative error code
*/
int from_mnemonic(const struct dictionary *dict,
                  unsigned char *mnemonic, size_t *mnemonic_l,
                  const unsigned char *delim, size_t delim_l,
                  const unsigned char *passphrase,
                  unsigned char *seed_output, size_t *seed_output_l,
                  unsigned char *entropy_output, size_t *entropy_output_l);

#endif //MNEMONICS_H
