#ifndef ERRORCODES_H
#define ERRORCODES_H

#include <stdio.h>


/**
 * @brief parse_error Prints information about the error to file
 * @param file        File to print information to.
 *                    Defaults to stderr in case of NULL pointer.
 * @param error_code  Error code to parse
 * @return 0 on success, negative error code otherwise
 */
int parse_error(FILE *file, int error_code);


#define EC_OK 0

#define EC_NOT_IMPLEMENTED -1
#define EC_OPENSSL_ERROR -2
#define EC_ALLOCATION_ERROR -3
#define EC_NULL_POINTER -4
#define EC_IO_ERROR -5
#define EC_PHRASE_DOES_NOT_GENERATE_SEED -6
#define EC_INVALID_PHRASE_WORD_COUNT -7
#define EC_INVALID_CHARACTER -8
#define EC_WORD_TOO_LONG -9
#define EC_NOT_ENOUGH_WORDS -10
#define EC_FILE_TOO_LONG -11
#define EC_ERROR_OPENING_FILE -12
#define EC_ERROR_CLOSING_FILE -13

#define EC_ENTROPY_LENGTH_NOT_MULTIPLE_OF_4 -20
#define EC_ENTROPY_LENGTH_NOT_WITHIN_16_32 -21

#endif //ERRORCODES_H
