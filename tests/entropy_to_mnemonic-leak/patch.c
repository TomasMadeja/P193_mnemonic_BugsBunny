#include <stdio.h>
#include <openssl/evp.h>

/*
 * Patching EVP_MD_CTX_create allows to trigger a memory leak
 * in entropy_to_mnemonic (mnemonics.c) function.
 */
EVP_MD_CTX * EVP_MD_CTX_create() {
  printf("CALLING PATCHED EVP_MD_CTX_create..\n");
  return NULL;
}
