# Table of Contents
- [Table of Contents](#table-of-contents)
- [bip39 Mnemonic Phrase Generator](#bip39-mnemonic-phrase-generator)
- [Footer](#footer)
  - [Team Members](#team-members)

# bip39 Mnemonic Phrase Generator

[![Build Status (dev)](https://travis-ci.org/TomasMadeja/PA193_mnemonic_BugsBunny.svg?branch=dev)](https://travis-ci.org/TomasMadeja/PA193_mnemonic_BugsBunny)

# API Usage

#### int init_mnemonics()
A wrapper for OpenSSL initialization. Not mandatory in OpenSSL versions >= 1.1.0.

- **return**: 0 if successful

#### int entropy_to_mnemonic(const struct dictionary *dictionary, const unsigned char *entropy, size_t entropy_l, unsigned char **output)
Converts the input entropy to a mnemonic phrase using the given dictionary.

- **dictionary**: pointer to a dictionary struct with words to use in mnemonics (if NULL default dictionary is used)
- **entropy**: binary entropy input
- **entropy_l**: length of the input entropy in bytes
- **output**: pointer to a string of the output mnemonic (the memory is dinamically allocated and needs to be freed afterwards)

- **return**: length of the output if successful, a negative error code otherwise

#### int mnemonic_to_seed(const unsigned char *mnemonic, size_t mnemonic_l, const unsigned char *passphrase, size_t passphrase_l, unsigned char **seed)
Converts mnemonic phrase to binary seed.

- **mnemonic**: input mnemonics in text format
- **mnemonic_l**: length of the input mnemonics in bytes
- **passphrase**: passphrase for mnemonics
- **passphrase_l**: length of the passphrase
- **seed**: pointer to a 64 bytes long string of the binary seed output (the memory is dinamically allocated and needs to be freed afterwards)

- **return**: zero if successful, a negative error code otherwise

#### int mnemonic_to_entropy(const struct dictionary *dictionary, const unsigned char *mnemonic, size_t mnemonic_l, unsigned char **entropy, size_t *entropy_l)
Converts the input (text) memonic to (binary) entropy.

- **dictionary**: pointer to a dictionary struct with words to use in mnemonics (if NULL default dictionary is used)
- **mnemonic**: input mnemonics in text format
- **mnemonic_l**: length of the input mnemonics in bytes
- **entropy**: binary entropy output
- **entropy_l**: length of the entropy in bytes

- **return**: zero if successful, a negative error code otherwise

# Footer

This project is a part of an assignament for PB193 - Secure coding principles and practices:

1. Write (securely) generator and verifier of bip39 mnemonic phrases
2. Write code as library code with proper API + demonstration usage
3. Analyze own implementation with static and dynamic analysis tools
4. Use GitHub + TravisCI integration for automatic tests, test vectors
5. Review code of other team generator
6. Create patch for selected flaws and open pull request

https://github.com/bitcoin/bips/blob/master/bip-0039.mediawiki

## Team Members
- Attila Farkas
- Tomáš Madeja
- Imrich Nagy


