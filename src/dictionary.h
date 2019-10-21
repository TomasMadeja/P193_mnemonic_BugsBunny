#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdlib.h>


struct dictionary {
    unsigned char *words[2048];
};


/*
@string input string of 2048 delimiter separated words
        IF NULL, function will create DEFAULT ENGLISH dictionary
@string_l length of string in bytes (chars)
@delim single character delimiter. 
    One in {'\n', ',' , ';' , ' ' } (newline, single whitespace, comma, semicolon).
@delim_l delimeter length (without '\0')
@dict pointer to variable that will hold the new dictionary (function will allocate new structure)

@return 0 IF success ELSE negative error code
*/
int parse_dict_from_string(
    const unsigned char *string, size_t string_l, 
    const unsigned char *delim, size_t delim_l, 
    struct dictionary *dict
);

/*
@string path to input  file of 2048 delimiter separated words, 
@string_l length of path string  in bytes (chars)
@delim single character delimiter. 
    One in {'\n', ',' , ';' , ' ' } (newline, single whitespace, comma, semicolon).
@delim_l delimeter length (without '\0')
@dict pointer to variable that will hold the new dictionary (function will allocate new structure)

@return 0 IF success ELSE negative error code
*/
int parse_dict_from_file(
    const unsigned char *path, size_t path_l,
    const unsigned char *delim, size_t delim_l, 
    struct dictionary *dict
);

/**
 * @brief Sets up the default dictionary if needed and returns pointer to it
 * @return pointer to default EN dictionary
 */
struct dictionary *default_EN_dictionary(void);


#endif //DICTIONARY_H
