#ifndef MNEMONICS_H
#define MNEMONICS_H


#include <stdlib.h>

#include "dictionary.h"

/**
 * @brief entropy_to_mnemonic
 * @param dict      initialized dictionary
 *                  if set to NULL, default dictionary will be used
 * @param entropy   16 to 32 bytes of entropy, must be multiple of 4
 * @param entropy_l length of entropy
 * @param output    stores pointer to allocated memory containing mnemonic
 * @return 0 in case of success, error code otherwise
 */
int entropy_to_mnemonic(const struct dictionary *dict,
                        const unsigned char *entropy,
                        size_t entropy_l,
                        unsigned char **mnemonic);

/**
 * @brief mnemonic_to_seed
 * @param mnemonic     mnemonic phrase
 * @param mnemonic_l   length of mnemonic phrase
 * @param passphrase   passphrase
 * @param passphrase_l length of passphrase
 * @param seed         stores pointer to allocated memory containing seed
 * @return 0 in case of success, error code otherwise
 */
int mnemonic_to_seed(const unsigned char *mnemonic,
                     size_t mnemonic_l,
                     const unsigned char *passphrase,
                     size_t passphrase_l,
                     unsigned char **seed);

/**
 * @brief mnemonic_to_entropy
 * @param dict       initialized dictionary
 *                   if set to NULL, default dictionary will be used
 * @param mnemonic   mnemonic phrase
 * @param mnemonic_l length of mnemonic phrase
 * @param entropy    stores pointer to allocated memory containing memory
 * @param entropy_l  pointer to variable to store size of entropy in bytes
 * @return 0 in case of success, error code otherwise
 */
int mnemonic_to_entropy(const struct dictionary *dict,
                        const unsigned char *mnemonic,
                        size_t mnemonic_l,
                        unsigned char **entropy,
                        size_t *entropy_l);

#endif //MNEMONICS_H
