#include <stdio.h>

#include <openssl/err.h>

#include "errorcodes.h"

int parse_error(FILE *file, int error_code) {
    FILE *f = file;
    if (file == NULL) {
        f = stderr;
    }

    switch (error_code) {

    // Libc and OpenSSL errors
    case EC_OK: {
        if (fprintf(f, "Operation was successfull.\n") != 0) {
            return EC_IO_ERROR;
        }
        break;
    }

    case EC_OPENSSL_ERROR: {
        if (fprintf(f, "An OpenSSL error occured:\n") != 0) {
            return EC_IO_ERROR;
        }
        ERR_print_errors_fp(f);
        break;
    }

    case EC_ALLOCATION_ERROR: {
        if (fprintf(f, "There was problem with memory allocation.\n") != 0) {
            return EC_IO_ERROR;
        }
        break;
    }

    case EC_NOT_IMPLEMENTED: {
        if (fprintf(f, "Used operation is not yet implemented.\n") != 0) {
            return EC_IO_ERROR;
        }
        break;
    }

    // Argument errors
    case EC_ENTROPY_LENGTH_NOT_WITHIN_16_32: {
        if (fprintf(f, "Length of entropy must be in "
                      "closed interval <16, 32>.\n") != 0) {
            return EC_IO_ERROR;
        }
        break;
    }

    case EC_ENTROPY_LENGTH_NOT_MULTIPLE_OF_4: {
        if (fprintf(f, "Length of entropy must be multiple of 4.\n") != 0) {
            return EC_IO_ERROR;
        }
        break;
    }

    case EC_NULL_POINTER: {
        if (fprintf(f, "NULL pointer value has been passed.\n") != 0) {
            return EC_IO_ERROR;
        }
        break;
    }
    }

    return EC_OK;
}
