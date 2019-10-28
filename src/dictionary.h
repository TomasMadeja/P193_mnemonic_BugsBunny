#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdlib.h>


struct dictionary {
    unsigned char *words[2048];
};


/**
 * @brief parse_dict_from_file
 * File must contain exactly 2048 lines ended with newline character
 * Each line must consist of maximum 20 english alphabet letters plus newline
 * @param file File to read from
 * @param dict struct dict to initialize
 * @return 0 on success, negative error code otherwise
 */
int parse_dict_from_file(char *path, struct dictionary *dict);

/**
 * @brief free_dict
 * @param dict Dictionary to free
 * @return 0 on success, negative error code otherwise
 */
int free_dict(struct dictionary *dict);

/**
 * @brief Sets up the default dictionary if needed and returns pointer to it
 * @return pointer to default EN dictionary
 */
struct dictionary *default_EN_dictionary(void);


#endif //DICTIONARY_H
