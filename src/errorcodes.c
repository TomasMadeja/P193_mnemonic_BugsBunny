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
        if (fprintf_s(f, "Operation was successfull.\n") != 0) {
            return EC_IO_ERROR;
        }
    }

    case EC_OPENSSL_ERROR: {
        ERR_print_errors_fp(f);
        if (fprintf_s(f, "Operation was successfull.\n") != 0) {
            return EC_IO_ERROR;
        }
    }

    case EC_ALLOCATION_ERROR: {
        if (fprintf_s(f, "There was problem with memory allocation.\n") != 0) {
            return EC_IO_ERROR;
        }
    }

    case EC_NOT_IMPLEMENTED: {
        if (fprintf_s(f, "Used operation is not yet implemented.\n") != 0) {
            return EC_IO_ERROR;
        }
    }

    // Argument errors
    case EC_ENTROPY_LENGTH_NOT_WITHIN_16_32: {
        if (fprintf_s(f, "Length of entropy must be in "
                      "closed interval <16, 32>.\n") != 0) {
            return EC_IO_ERROR;
        }
    }

    case EC_ENTROPY_LENGTH_NOT_MULTIPLE_OF_4: {
        if (fprintf_s(f, "Length of entropy must be multiple of 4.\n") != 0) {
            return EC_IO_ERROR;
        }
    }

    case EC_NULL_POINTER: {
        if (fprintf_s(f, "NULL pointer value has been passed.\n") != 0) {
            return EC_IO_ERROR;
        }
    }
    }

    return EC_OK;
}
