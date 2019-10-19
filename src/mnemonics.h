#ifndef MNEMONICS_H
#define MNEMONICS_H


#include <stdlib.h>


struct dictionary {
    unsigned char *words[2048];
};

/**
@string input string of 2048 delimiter separated words
@string_l length of string in bytes (chars)
@delim single character delimiter. One in {'\n', ',' , ';' , ' ' } (newline, single whitespace, comma, semicolon).
@delim_l delimeter length (without '\0')
@dict pointer to variable that will hold the new dictionary (function will allocate new structure)

@return 0 IF success ELSE negative error code
*/
int parse_dict_from_string(const unsigned char *string, size_t string_l, const unsigned char *delim, size_t delim_l, struct dictionary **dict);

/**
@string path to input  file of 2048 delimiter separated words
@string_l length of path string  in bytes (chars)
@delim single character delimiter. One in {'\n', ',' , ';' , ' ' } (newline, single whitespace, comma, semicolon).
@delim_l delimeter length (without '\0')
@dict pointer to variable that will hold the new dictionary (function will allocate new structure)

@return 0 IF success ELSE negative error code
*/
int parse_dict_from_file(const unsigned char *path, size_t path_l, const unsigned char *delim, size_t delim_l, struct dictionary **dict);

/**
@dict initialized dictionary used to generate mnemonics
@bytes buffer containing bytes used to generate mnemonics, must be multiple of 11 bits
@bytes_l size of input buffer
@output address that will recieve newly allocated delim separated mnemonics
@output_l address that will recieve size of the output
@delim delimiter to be used to separate words in output. One in {'\n', ',' , ';' , ' ' } (newline, single whitespace, comma, semicolon).
@delim_l delimeter length (without '\0')

@return 0 IF success ELSE negative error code
*/
int to_mnemonic(const struct dictionary *dict, const unsigned char *bytes, size_t bytes_l, const unsigned char *delim, size_t delim_l, unsigned char *output, size_t *output_l);

/**
@dict initialized dictionary used to generate mnemonics
@mnemonic buffer containing bytes used to generate mnemonics, must be multiple of 11 bits
@mnemonic_l size of the mnemonic string
@delim delimiter used to separate words in mnemonic. One in {'\n', ',' , ';' , ' ' } (newline, single whitespace, comma, semicolon).
@delim_l delimeter length (without '\0')
@output address that will recieve newly allocated bytes output
@output_l address that will recieve size of output

@return 0 IF success ELSE negative error code
*/
int from_mnemonic(const struct dictionary *dict, unsigned char *mnemonic, size_t *mnemonic_l, const unsigned char *delim, size_t delim_l, unsigned char *output, size_t *output_l);

#endif //MNEMONICS_H
