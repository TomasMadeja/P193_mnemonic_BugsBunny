#ifndef MNEMONICS_H
#define MNEMONICS_H

#include <stdlib.h>

#include "dictionary.h"


/**
 * @brief entropy_to_mnemonic
 * @param dictionary initialized dictionary
 *                   if set to NULL, default dictionary will be used
 * @param entropy    16 to 32 bytes of entropy, must be multiple of 4
 * @param entropy_l  length of entropy
 * @param mnemonic   stores pointer to allocated memory containing mnemonic
 * @return           length of mnemonic phrase in characters 
 *                   or negative error code in case of failure
 */
int entropy_to_mnemonic(const struct dictionary *dictionary,
                        const unsigned char *entropy,
                        size_t entropy_l,
                        unsigned char **mnemonic);

/**
 * @brief mnemonic_to_seed
 * @param mnemonic     mnemonic phrase
 * @param mnemonic_l   length of mnemonic phrase
 * @param passphrase   passphrase. If set to NULL, default passphrase "" used.
 * @param passphrase_l length of passphrase
 * @param seed         stores pointer to allocated memory containing seed
 * @return 0 in case of success, negative error code otherwise
 */
int mnemonic_to_seed(const unsigned char *mnemonic,
                     size_t mnemonic_l,
                     const unsigned char *passphrase,
                     size_t passphrase_l,
                     unsigned char **seed);

/**
 * @brief mnemonic_to_entropy
 * @param dictionary initialized dictionary
 *                   if set to NULL, default dictionary will be used
 * @param mnemonic   mnemonic phrase
 * @param mnemonic_l length of mnemonic phrase
 * @param entropy    stores pointer to allocated memory containing memory
 * @param entropy_l  pointer to variable to store size of entropy in bytes
 * @return 0 in case of success, negative error code otherwise
 */
int mnemonic_to_entropy(const struct dictionary *dictionary,
                        const unsigned char *mnemonic,
                        size_t mnemonic_l,
                        unsigned char **entropy,
                        size_t *entropy_l);

/**
 * @brief init_mnemonics Initializes mnemonics library
 * @return 0 in case of success
 */
int init_mnemonics(void);

/**
 * @brief entropy_to_mnemonic_seed
 * @param dictionary   initialized dictionary
 *                     if set to NULL, default dictionary will be used
 * @param entropy      16 to 32 bytes of entropy, must be multiple of 4
 * @param entropy_l    length of entropy
 * @param passphrase   passphrase. If set to NULL, default passphrase "" used.
 * @param passphrase_l length of passphrase
 * @param mnemonic     stores pointer to allocated memory containing mnemonic
 * @param seed         stores pointer to allocated memory containing seed
 * @return  0 in case of success, negative error code otherwise
 */
int entropy_to_mnemonic_seed(const struct dictionary *dictionary,
                             const unsigned char *entropy,
                             size_t entropy_l,
                             const unsigned char *passphrase,
                             size_t passphrase_l,
                             unsigned char **mnemonic,
                             unsigned char **seed);

/**
 * @brief mnemonic_to_entropy_seed
 * @param dictionary   initialized dictionary
 *                     if set to NULL, default dictionary will be used
 * @param mnemonic     mnemonic phrase
 * @param mnemonic_l   length of mnemonic phrase
 * @param passphrase   passphrase. If set to NULL, default passphrase "" used.
 * @param passphrase_l length of passphrase
 * @param entropy      stores pointer to allocated memory containing memory
 * @param entropy_l    pointer to variable to store size of entropy in bytes
 * @param seed         stores pointer to allocated memory containing seed
 * @return 0 in case of success, negative error code otherwise
 */
int mnemonic_to_entropy_seed(const struct dictionary *dictionary,
                             const unsigned char *mnemonic,
                             size_t mnemonic_l,
                             const unsigned char *passphrase,
                             size_t passphrase_l,
                             unsigned char **entropy,
                             size_t *entropy_l,
                             unsigned char **seed);

/**
 * @brief check_phrase_seed
 * @param mnemonic     mnemonic phrase
 * @param mnemonic_l   length of mnemonic phrase
 * @param passphrase   passphrase. If set to NULL, default passphrase "" used.
 * @param passphrase_l length of passphrase
 * @param seed         seed to check against provided mnemonic phrase
 * @return 0 if provided mnemonic phrase generates provided seed,
 *         negative error code otherwise
 */
int check_phrase_seed(const unsigned char *mnemonic,
                      size_t mnemonic_l,
                      const unsigned char *passphrase,
                      size_t passphrase_l,
                      const unsigned char *seed);

#endif //MNEMONICS_H
