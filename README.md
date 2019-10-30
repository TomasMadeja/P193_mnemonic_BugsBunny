# Table of Contents
- [Table of Contents](#table-of-contents)
- [bip39 Mnemonic Phrase Generator](#bip39-mnemonic-phrase-generator)
- [Dependencies](#dependencies)
- [API Usage](#api-usage)
  - [**Header:** mnemonics.h](#header-mnemonicsh)
  - [**Header:** dictionary.h](#header-dictionaryh)
  - [**Error Codes:**](#error-codes)
- [Footer](#footer)
  - [Team Members](#team-members)

# bip39 Mnemonic Phrase Generator

[![Build Status (dev)](https://travis-ci.org/TomasMadeja/PA193_mnemonic_BugsBunny.svg?branch=dev)](https://travis-ci.org/TomasMadeja/PA193_mnemonic_BugsBunny)

This library implements Mnemonic Phrase Generator described by [bip39](https://github.com/bitcoin/bips/blob/master/bip-0039.mediawiki).

# Dependencies

Compilation requires OpenSSL version >= 1.1.0

Compiling tests requires unit testing framework Check >= 0.12.0.


# API Usage



## **Header:** mnemonics.h

Sample usage can be found in (TODO LINK).

> __int__ init_mnemonics()

A wrapper for OpenSSL initialization. Not mandatory in OpenSSL versions >= 1.1.0.

- **return**: 0 if successful

> __int__ entropy_to_mnemonic(__const struct dictionary *__ dictionary, __const unsigned char *__ entropy, __size_t__ entropy_l, __unsigned char **__ output)

Converts the input entropy to a mnemonic phrase using the given dictionary.

- **dictionary**: pointer to a dictionary struct with words to use in mnemonics (if NULL default dictionary is used)
- **entropy**: binary entropy input
- **entropy_l**: length of the input entropy in bytes. Must be multiple of 4 and 16 <= entropy_l <= 32.
- **output**: pointer to a string of the output mnemonic (the memory is dinamically allocated and needs to be freed afterwards)

- **return**: length of the mnemonic phrase if successful, negative error code otherwise

> __int__ mnemonic_to_seed(__const unsigned char *__ mnemonic, __size_t__ mnemonic_l, __const unsigned char *__ passphrase, __size_t__ passphrase_l, __unsigned char **__ seed)

Converts mnemonic phrase to binary seed.

- **mnemonic**: input mnemonics in text format
- **mnemonic_l**: length of the input mnemonics in characters
- **passphrase**: passphrase for mnemonics
- **passphrase_l**: length of the passphrase
- **seed**: pointer to a 64 bytes long string of the binary seed output (the memory is dinamically allocated and needs to be freed afterwards)

- **return**: zero if successful, negative error code otherwise

> __int__ mnemonic_to_entropy(__const struct dictionary *__ dictionary, __const unsigned char *__ mnemonic, __size_t__ mnemonic_l, __unsigned char **__ entropy, __size_t *__ entropy_l)

Converts the input (text) memonic to (binary) entropy.

- **dictionary**: pointer to a dictionary struct with words to use in mnemonics (if NULL default dictionary is used)
- **mnemonic**: input mnemonics in text format
- **mnemonic_l**: length of the input mnemonics in bytes
- **entropy**: binary entropy output (the memory is dinamically allocated and needs to be freed afterwards)
- **entropy_l**: length of the entropy in bytes

- **return**: zero if successful, negative error code otherwise

## **Header:** dictionary.h

> __int__ parse_dict_from_file(__char *__ path, __struct dictionary *__ dict)

Creates a dictionary from file input.

- **path**: path to the file
- **dict**: pointer to target dictionary struct

- **return**: zero if successful, negative error code otherwise

## **Error Codes:** 

> EC_OK
    
> EC_NOT_IMPLEMENTED

> EC_OPENSSL_ERROR

> EC_ALLOCATION_ERROR

> EC_NULL_POINTER

> EC_IO_ERROR

> EC_PHRASE_DOES_NOT_GENERATE_SEED

> EC_INVALID_PHRASE_WORD_COUNT

> EC_INVALID_CHARACTER

> EC_WORD_TOO_LONG

> EC_NOT_ENOUGH_WORDS

> EC_FILE_TOO_LONG

> EC_ERROR_OPENING_FILE

> EC_ERROR_CLOSING_FILE

> EC_ENTROPY_LENGTH_NOT_MULTIPLE_OF_4

> EC_ENTROPY_LENGTH_NOT_WITHIN_16_32

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


