#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "mnemonics.h"

#define MNEMONIC_BUFFER_LEN 1024
#define ENTROPY_BUFFER_LEN  256
#define SEED_BUFFER_LEN     512

void print_hex(unsigned char *bytes, size_t len) {
    for (size_t i = 0; i < len; i++) {
        printf("%02x", bytes[i]);
    }
}

int check_flags(int argc, char **argv) {

    if (argc != 3) {
        printf("Error: Incorrect number of arguments.\n");
        return 0;
    }

    int hflag = 0;
    int eflag = 0;
    int mflag = 0;
    int cflag = 0;
    int flag;

    while ((flag = getopt(argc, argv, "hemc")) != -1) {
        switch (flag) {
          case 'h':
            hflag = 1;
            break;
          case 'e':
            eflag = 1;
            break;
          case 'm':
            mflag = 1;
            break;
          case 'c':
            cflag = 1;
            break;
          default:
            printf("Error: Unknown flag.\n");
            hflag = 1;
        }
    }

    if (hflag) {
        return 0;
    }
    if (eflag && !mflag && !cflag) {
        return 1;
    }
    if (mflag && !eflag && !cflag) {
        return 2;
    }
    if (cflag && !mflag && !eflag) {
        return 3;
    }
    if (!cflag && !mflag && !eflag) {
        printf("Error: No flag.\n");
        return 0;
    }
    printf("Error: Multiple flags.\n");
    return 0;
}

void print_help() {
    const char help_string[] = "Usage: example flag\n"
                               "  -h                    Display this help.\n"
                               "  -m mnemonic_file      Computes the seed from a mnemonic phrase.\n"
                               "  -e entropy_file       Computes the mnemonic phrase from entropy.\n"
                               "  -c mnemonic_file      Computes entropy from a mnemonic phrase.\n\n"
                               "Mnemonic files should be text files with a mnemonic phrase.\n"
                               "Entropy files should be binary.\n";

    printf(help_string);
}

size_t get_mnemonic(char *file_name, unsigned char *mnemonic) {

    FILE *file;
    file = fopen(file_name, "r");

    if(!file) {
        return 0;
    }

    int c;
    size_t i = 0;
    while (i < MNEMONIC_BUFFER_LEN && (c = fgetc(file)) != EOF) {
        putchar(c);
        mnemonic[i] = c;
        i++;
    }

    fclose(file);
    return i;
}

size_t get_entropy(char *file_name, unsigned char *entropy) {

    FILE *file;
    file = fopen(file_name, "rb");

    if(!file) {
        return 0;
    }

    size_t i = fread(entropy, 1, ENTROPY_BUFFER_LEN, file);

    fclose(file);

    return i;
}

void convert_entropy_to_mnemonics(char *entropy_file_name) {

    unsigned char entropy[ENTROPY_BUFFER_LEN];
    size_t entropy_len = 0;
    unsigned char *mnemonic;

    entropy_len = get_entropy(entropy_file_name, entropy);

    if (entropy_len == 0) {
        printf("Error: Cannot load the entropy file.\n");
        return;
    }

    int return_code;

    /* Converting entropy to a mnemonic phrase using the default dictionary. */
    return_code = entropy_to_mnemonic(NULL, entropy, entropy_len, &mnemonic);

    if (return_code != 0) {
        printf("Error: Could not convert entropy.\n");
        return;
    }

    /* Printing the mnemonic phrase. */
    printf("ENTROPY -> MNEMONIC\n");
    printf("The mnemonic phrase for the entropy ");
    print_hex(entropy, entropy_len);
    printf(" is:\n%s\n\n", mnemonic);

    free(mnemonic);
}

void convert_mnemonics_to_seed(char *mnemonics_file_name) {

    unsigned char mnemonic[MNEMONIC_BUFFER_LEN];
    size_t mnemonic_len;
    unsigned char *seed;

    mnemonic_len = get_mnemonic(mnemonics_file_name, mnemonic);

    if (mnemonic_len == 0) {
        printf("Error: Cannot load the mnemonic file.\n");
        return;
    }

    int return_code;

    /* Converting the mnemonic phrase to seed using the passphrase "TREZOR". */
    return_code = mnemonic_to_seed(mnemonic, strlen((char*) mnemonic),
                     (unsigned char*) "TREZOR", 6, &seed);

    if (return_code != 0) {
        printf("Error: Could not convert mnemonic.\n");
        return;
    }

    /* Printing the seed. */
    printf("MNEMONIC -> SEED\n");
    printf("The seed for the mnemonic phrase\n%sis:\n", mnemonic);
    print_hex(seed, 64);
    printf("\n");

    free(seed);
}

void convert_mnemonic_to_entropy(char *mnemonics_file_name) {

    unsigned char mnemonic[MNEMONIC_BUFFER_LEN];
    size_t mnemonic_len = 0;
    unsigned char *entropy;
    size_t entropy_len = 0;
    int return_code;

    mnemonic_len = get_mnemonic(mnemonics_file_name, mnemonic);

    if (mnemonic_len == 0) {
        printf("Error: Cannot load the mnemonic file.\n");
        return;
    }

    /* Converting the mnemonic phrase to entropy using the default dictionary. */
    return_code = mnemonic_to_entropy(NULL,
                        mnemonic, strlen((char*) mnemonic),
                        &entropy, &entropy_len);

    if (return_code != 0) {
        printf("Error: Could not convert mnemonic.\n");
        return;
    }

    /* Printing out the result. */
    printf("MNEMONIC -> ENTROPY\n");
    printf("The entropy for the mnemonic phrase\n%sis:\n", mnemonic);
    print_hex(entropy, entropy_len);
    printf("\n");
}

int main(int argc, char **argv) {

    short mode;
    mode = check_flags(argc, argv);

    /* Initializing the API. */
    init_mnemonics();

    switch (mode) {
      // entropy to mnemonic
      case 1:
        convert_entropy_to_mnemonics(argv[2]);
        break;
      // mnemonic to seed
      case 2:
        convert_mnemonics_to_seed(argv[2]);
        break;
      // mnemonic-entropy check
      case 3:
        convert_mnemonic_to_entropy(argv[2]);
        break;
      // print help
      default:
        print_help();
        break;
    }

    return EXIT_SUCCESS;
}
