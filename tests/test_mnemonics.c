#include <check.h>
#include <string.h>
#include <stdlib.h>

#include "mnemonics.h"
#include "errorcodes.h"
#include "dictionary.h"

/*
====================
======= Test Vectors
====================
*/

#define VECTOR_PASSPHRASE "TREZOR"
#define VECTOR_PASSPHRASE_L 6

START_TEST (vector_0_en)
{
#define VECTOR_0_M_LEN 93
#define VECTOR_0_E_LEN 16
#define VECTOR_0_S_LEN 64
    unsigned char entropy[] = {
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
    };
    size_t entropy_l = VECTOR_0_E_LEN;
    unsigned char mnemonic_ref[] = "abandon abandon abandon abandon abandon abandon abandon abandon abandon abandon abandon about";
    unsigned char seed_ref[] = {
0xc5,0x52,0x57,0xc3,0x60,0xc0,0x7c,0x72,0x02,0x9a,0xeb,0xc1,0xb5,0x3c,0x05,0xed,0x03,0x62,0xad,0xa3,0x8e,0xad,0x3e,0x3e,0x9e,0xfa,0x37,0x08,0xe5,0x34,0x95,0x53,0x1f,0x09,0xa6,0x98,0x75,0x99,0xd1,0x82,0x64,0xc1,0xe1,0xc9,0x2f,0x2c,0xf1,0x41,0x63,0x0c,0x7a,0x3c,0x4a,0xb7,0xc8,0x1b,0x2f,0x00,0x16,0x98,0xe7,0x46,0x3b,0x04
    };

    int err=0;
    unsigned char *mnemonic;
    err = entropy_to_mnemonic(
        NULL,
        entropy, entropy_l,
        &mnemonic
    );

    ck_assert_msg(
        err >= 0,
        "entropy_to_mnemonic nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        mnemonic != NULL,
        "Output mnemonic is NULL."
    );

    size_t mnemonic_l = strlen((char *) mnemonic);
    ck_assert_msg(
        mnemonic_l == VECTOR_0_M_LEN,
        "Output mnemonic size didn't match = %llu.",
        mnemonic_l
    );

    ck_assert_msg(
        memcmp(mnemonic, mnemonic_ref, VECTOR_0_M_LEN) == 0,
        "Output didn't match."
    );

    unsigned char* seed;
    err = mnemonic_to_seed(
        mnemonic, mnemonic_l,
        (unsigned char*) VECTOR_PASSPHRASE, VECTOR_PASSPHRASE_L,
        &seed
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_seed nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        seed != NULL,
        "Output seed is NULL."
    );

    ck_assert_msg(
        memcmp(seed, seed_ref, VECTOR_0_S_LEN) == 0,
        "Output seed didn't match."
    );

    unsigned char* s_entropy;
    size_t s_entropy_l;
    err = mnemonic_to_entropy(
        NULL,
        mnemonic_ref, VECTOR_0_M_LEN,
        &s_entropy, &s_entropy_l
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_entropy nonzero error code = %llu.",
        err
    );

    ck_assert_msg(
        s_entropy != NULL,
        "Output entropy is NULL."
    );

    ck_assert_msg(
        s_entropy_l == VECTOR_0_E_LEN,
        "Output entropy size didn't match = %d.",
        s_entropy_l
    );

    ck_assert_msg(
        memcmp(s_entropy, entropy, VECTOR_0_E_LEN) == 0,
        "Output entropy didn't match."
    );

    free(mnemonic);
    free(seed);
    free(s_entropy);
}
END_TEST

START_TEST (vector_1_en)
{
#define VECTOR_1_M_LEN 75
#define VECTOR_1_E_LEN 16
#define VECTOR_1_S_LEN 64
    unsigned char entropy[] = {
0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f
    };
    size_t entropy_l = VECTOR_1_E_LEN;
    unsigned char mnemonic_ref[] = "legal winner thank year wave sausage worth useful legal winner thank yellow";
    unsigned char seed_ref[] = {
0x2e,0x89,0x05,0x81,0x9b,0x87,0x23,0xfe,0x2c,0x1d,0x16,0x18,0x60,0xe5,0xee,0x18,0x30,0x31,0x8d,0xbf,0x49,0xa8,0x3b,0xd4,0x51,0xcf,0xb8,0x44,0x0c,0x28,0xbd,0x6f,0xa4,0x57,0xfe,0x12,0x96,0x10,0x65,0x59,0xa3,0xc8,0x09,0x37,0xa1,0xc1,0x06,0x9b,0xe3,0xa3,0xa5,0xbd,0x38,0x1e,0xe6,0x26,0x0e,0x8d,0x97,0x39,0xfc,0xe1,0xf6,0x07
    };

    int err=0;
    unsigned char *mnemonic;
    err = entropy_to_mnemonic(
        NULL,
        entropy, entropy_l,
        &mnemonic
    );

    ck_assert_msg(
        err >= 0,
        "entropy_to_mnemonic nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        mnemonic != NULL,
        "Output mnemonic is NULL."
    );

    size_t mnemonic_l = strlen((char *) mnemonic);
    ck_assert_msg(
        mnemonic_l == VECTOR_1_M_LEN,
        "Output mnemonic size didn't match = %llu.",
        mnemonic_l
    );

    ck_assert_msg(
        memcmp(mnemonic, mnemonic_ref, VECTOR_1_M_LEN) == 0,
        "Output didn't match."
    );

    unsigned char* seed;
    err = mnemonic_to_seed(
        mnemonic, mnemonic_l,
        (unsigned char*) VECTOR_PASSPHRASE, VECTOR_PASSPHRASE_L,
        &seed
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_seed nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        seed != NULL,
        "Output seed is NULL."
    );

    ck_assert_msg(
        memcmp(seed, seed_ref, VECTOR_1_S_LEN) == 0,
        "Output seed didn't match."
    );

    unsigned char* s_entropy;
    size_t s_entropy_l;
    err = mnemonic_to_entropy(
        NULL,
        mnemonic_ref, VECTOR_1_M_LEN,
        &s_entropy, &s_entropy_l
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_entropy nonzero error code = %llu.",
        err
    );

    ck_assert_msg(
        s_entropy != NULL,
        "Output entropy is NULL."
    );

    ck_assert_msg(
        s_entropy_l == VECTOR_1_E_LEN,
        "Output entropy size didn't match = %d.",
        s_entropy_l
    );

    ck_assert_msg(
        memcmp(s_entropy, entropy, VECTOR_1_E_LEN) == 0,
        "Output entropy didn't match."
    );

    free(mnemonic);
    free(seed);
    free(s_entropy);
}
END_TEST

START_TEST (vector_2_en)
{
#define VECTOR_2_M_LEN 79
#define VECTOR_2_E_LEN 16
#define VECTOR_2_S_LEN 64
    unsigned char entropy[] = {
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80
    };
    size_t entropy_l = VECTOR_2_E_LEN;
    unsigned char mnemonic_ref[] = "letter advice cage absurd amount doctor acoustic avoid letter advice cage above";
    unsigned char seed_ref[] = {
0xd7,0x1d,0xe8,0x56,0xf8,0x1a,0x8a,0xcc,0x65,0xe6,0xfc,0x85,0x1a,0x38,0xd4,0xd7,0xec,0x21,0x6f,0xd0,0x79,0x6d,0x0a,0x68,0x27,0xa3,0xad,0x6e,0xd5,0x51,0x1a,0x30,0xfa,0x28,0x0f,0x12,0xeb,0x2e,0x47,0xed,0x2a,0xc0,0x3b,0x5c,0x46,0x2a,0x03,0x58,0xd1,0x8d,0x69,0xfe,0x4f,0x98,0x5e,0xc8,0x17,0x78,0xc1,0xb3,0x70,0xb6,0x52,0xa8
    };

    int err=0;
    unsigned char *mnemonic;
    err = entropy_to_mnemonic(
        NULL,
        entropy, entropy_l,
        &mnemonic
    );

    ck_assert_msg(
        err >= 0,
        "entropy_to_mnemonic nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        mnemonic != NULL,
        "Output mnemonic is NULL."
    );

    size_t mnemonic_l = strlen((char *) mnemonic);
    ck_assert_msg(
        mnemonic_l == VECTOR_2_M_LEN,
        "Output mnemonic size didn't match = %llu.",
        mnemonic_l
    );

    ck_assert_msg(
        memcmp(mnemonic, mnemonic_ref, VECTOR_2_M_LEN) == 0,
        "Output didn't match."
    );

    unsigned char* seed;
    err = mnemonic_to_seed(
        mnemonic, mnemonic_l,
        (unsigned char*) VECTOR_PASSPHRASE, VECTOR_PASSPHRASE_L,
        &seed
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_seed nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        seed != NULL,
        "Output seed is NULL."
    );

    ck_assert_msg(
        memcmp(seed, seed_ref, VECTOR_2_S_LEN) == 0,
        "Output seed didn't match."
    );

    unsigned char* s_entropy;
    size_t s_entropy_l;
    err = mnemonic_to_entropy(
        NULL,
        mnemonic_ref, VECTOR_2_M_LEN,
        &s_entropy, &s_entropy_l
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_entropy nonzero error code = %llu.",
        err
    );

    ck_assert_msg(
        s_entropy != NULL,
        "Output entropy is NULL."
    );

    ck_assert_msg(
        s_entropy_l == VECTOR_2_E_LEN,
        "Output entropy size didn't match = %d.",
        s_entropy_l
    );

    ck_assert_msg(
        memcmp(s_entropy, entropy, VECTOR_2_E_LEN) == 0,
        "Output entropy didn't match."
    );

    free(mnemonic);
    free(seed);
    free(s_entropy);
}
END_TEST

START_TEST (vector_3_en)
{
#define VECTOR_3_M_LEN 49
#define VECTOR_3_E_LEN 16
#define VECTOR_3_S_LEN 64
    unsigned char entropy[] = {
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
    };
    size_t entropy_l = VECTOR_3_E_LEN;
    unsigned char mnemonic_ref[] = "zoo zoo zoo zoo zoo zoo zoo zoo zoo zoo zoo wrong";
    unsigned char seed_ref[] = {
0xac,0x27,0x49,0x54,0x80,0x22,0x52,0x22,0x07,0x9d,0x7b,0xe1,0x81,0x58,0x37,0x51,0xe8,0x6f,0x57,0x10,0x27,0xb0,0x49,0x7b,0x5b,0x5d,0x11,0x21,0x8e,0x0a,0x8a,0x13,0x33,0x25,0x72,0x91,0x7f,0x0f,0x8e,0x5a,0x58,0x96,0x20,0xc6,0xf1,0x5b,0x11,0xc6,0x1d,0xee,0x32,0x76,0x51,0xa1,0x4c,0x34,0xe1,0x82,0x31,0x05,0x2e,0x48,0xc0,0x69
    };

    int err=0;
    unsigned char *mnemonic;
    err = entropy_to_mnemonic(
        NULL,
        entropy, entropy_l,
        &mnemonic
    );

    ck_assert_msg(
        err >= 0,
        "entropy_to_mnemonic nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        mnemonic != NULL,
        "Output mnemonic is NULL."
    );

    size_t mnemonic_l = strlen((char *) mnemonic);
    ck_assert_msg(
        mnemonic_l == VECTOR_3_M_LEN,
        "Output mnemonic size didn't match = %llu.",
        mnemonic_l
    );

    ck_assert_msg(
        memcmp(mnemonic, mnemonic_ref, VECTOR_3_M_LEN) == 0,
        "Output didn't match."
    );

    unsigned char* seed;
    err = mnemonic_to_seed(
        mnemonic, mnemonic_l,
        (unsigned char*) VECTOR_PASSPHRASE, VECTOR_PASSPHRASE_L,
        &seed
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_seed nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        seed != NULL,
        "Output seed is NULL."
    );

    ck_assert_msg(
        memcmp(seed, seed_ref, VECTOR_3_S_LEN) == 0,
        "Output seed didn't match."
    );

    unsigned char* s_entropy;
    size_t s_entropy_l;
    err = mnemonic_to_entropy(
        NULL,
        mnemonic_ref, VECTOR_3_M_LEN,
        &s_entropy, &s_entropy_l
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_entropy nonzero error code = %llu.",
        err
    );

    ck_assert_msg(
        s_entropy != NULL,
        "Output entropy is NULL."
    );

    ck_assert_msg(
        s_entropy_l == VECTOR_3_E_LEN,
        "Output entropy size didn't match = %d.",
        s_entropy_l
    );

    ck_assert_msg(
        memcmp(s_entropy, entropy, VECTOR_3_E_LEN) == 0,
        "Output entropy didn't match."
    );

    free(mnemonic);
    free(seed);
    free(s_entropy);
}
END_TEST

START_TEST (vector_4_en)
{
#define VECTOR_4_M_LEN 141
#define VECTOR_4_E_LEN 24
#define VECTOR_4_S_LEN 64
    unsigned char entropy[] = {
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
    };
    size_t entropy_l = VECTOR_4_E_LEN;
    unsigned char mnemonic_ref[] = "abandon abandon abandon abandon abandon abandon abandon abandon abandon abandon abandon abandon abandon abandon abandon abandon abandon agent";
    unsigned char seed_ref[] = {
0x03,0x58,0x95,0xf2,0xf4,0x81,0xb1,0xb0,0xf0,0x1f,0xcf,0x8c,0x28,0x9c,0x79,0x46,0x60,0xb2,0x89,0x98,0x1a,0x78,0xf8,0x10,0x64,0x47,0x70,0x7f,0xdd,0x96,0x66,0xca,0x06,0xda,0x5a,0x9a,0x56,0x51,0x81,0x59,0x9b,0x79,0xf5,0x3b,0x84,0x4d,0x8a,0x71,0xdd,0x9f,0x43,0x9c,0x52,0xa3,0xd7,0xb3,0xe8,0xa7,0x9c,0x90,0x6a,0xc8,0x45,0xfa
    };

    int err=0;
    unsigned char *mnemonic;
    err = entropy_to_mnemonic(
        NULL,
        entropy, entropy_l,
        &mnemonic
    );

    ck_assert_msg(
        err >= 0,
        "entropy_to_mnemonic nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        mnemonic != NULL,
        "Output mnemonic is NULL."
    );

    size_t mnemonic_l = strlen((char *) mnemonic);
    ck_assert_msg(
        mnemonic_l == VECTOR_4_M_LEN,
        "Output mnemonic size didn't match = %llu.",
        mnemonic_l
    );

    ck_assert_msg(
        memcmp(mnemonic, mnemonic_ref, VECTOR_4_M_LEN) == 0,
        "Output didn't match."
    );

    unsigned char* seed;
    err = mnemonic_to_seed(
        mnemonic, mnemonic_l,
        (unsigned char*) VECTOR_PASSPHRASE, VECTOR_PASSPHRASE_L,
        &seed
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_seed nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        seed != NULL,
        "Output seed is NULL."
    );

    ck_assert_msg(
        memcmp(seed, seed_ref, VECTOR_4_S_LEN) == 0,
        "Output seed didn't match."
    );

    unsigned char* s_entropy;
    size_t s_entropy_l;
    err = mnemonic_to_entropy(
        NULL,
        mnemonic_ref, VECTOR_4_M_LEN,
        &s_entropy, &s_entropy_l
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_entropy nonzero error code = %llu.",
        err
    );

    ck_assert_msg(
        s_entropy != NULL,
        "Output entropy is NULL."
    );

    ck_assert_msg(
        s_entropy_l == VECTOR_4_E_LEN,
        "Output entropy size didn't match = %d.",
        s_entropy_l
    );

    ck_assert_msg(
        memcmp(s_entropy, entropy, VECTOR_4_E_LEN) == 0,
        "Output entropy didn't match."
    );

    free(mnemonic);
    free(seed);
    free(s_entropy);
}
END_TEST

START_TEST (vector_5_en)
{
#define VECTOR_5_M_LEN 110
#define VECTOR_5_E_LEN 24
#define VECTOR_5_S_LEN 64
    unsigned char entropy[] = {
0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f
    };
    size_t entropy_l = VECTOR_5_E_LEN;
    unsigned char mnemonic_ref[] = "legal winner thank year wave sausage worth useful legal winner thank year wave sausage worth useful legal will";
    unsigned char seed_ref[] = {
0xf2,0xb9,0x45,0x08,0x73,0x2b,0xcb,0xac,0xbc,0xc0,0x20,0xfa,0xef,0xec,0xfc,0x89,0xfe,0xaf,0xa6,0x64,0x9a,0x54,0x91,0xb8,0xc9,0x52,0xce,0xde,0x49,0x6c,0x21,0x4a,0x0c,0x7b,0x3c,0x39,0x2d,0x16,0x87,0x48,0xf2,0xd4,0xa6,0x12,0xba,0xda,0x07,0x53,0xb5,0x2a,0x1c,0x7a,0xc5,0x3c,0x1e,0x93,0xab,0xd5,0xc6,0x32,0x0b,0x9e,0x95,0xdd
    };

    int err=0;
    unsigned char *mnemonic;
    err = entropy_to_mnemonic(
        NULL,
        entropy, entropy_l,
        &mnemonic
    );

    ck_assert_msg(
        err >= 0,
        "entropy_to_mnemonic nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        mnemonic != NULL,
        "Output mnemonic is NULL."
    );

    size_t mnemonic_l = strlen((char *) mnemonic);
    ck_assert_msg(
        mnemonic_l == VECTOR_5_M_LEN,
        "Output mnemonic size didn't match = %llu.",
        mnemonic_l
    );

    ck_assert_msg(
        memcmp(mnemonic, mnemonic_ref, VECTOR_5_M_LEN) == 0,
        "Output didn't match."
    );

    unsigned char* seed;
    err = mnemonic_to_seed(
        mnemonic, mnemonic_l,
        (unsigned char*) VECTOR_PASSPHRASE, VECTOR_PASSPHRASE_L,
        &seed
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_seed nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        seed != NULL,
        "Output seed is NULL."
    );

    ck_assert_msg(
        memcmp(seed, seed_ref, VECTOR_5_S_LEN) == 0,
        "Output seed didn't match."
    );

    unsigned char* s_entropy;
    size_t s_entropy_l;
    err = mnemonic_to_entropy(
        NULL,
        mnemonic_ref, VECTOR_5_M_LEN,
        &s_entropy, &s_entropy_l
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_entropy nonzero error code = %llu.",
        err
    );

    ck_assert_msg(
        s_entropy != NULL,
        "Output entropy is NULL."
    );

    ck_assert_msg(
        s_entropy_l == VECTOR_5_E_LEN,
        "Output entropy size didn't match = %d.",
        s_entropy_l
    );

    ck_assert_msg(
        memcmp(s_entropy, entropy, VECTOR_5_E_LEN) == 0,
        "Output entropy didn't match."
    );

    free(mnemonic);
    free(seed);
    free(s_entropy);
}
END_TEST

START_TEST (vector_6_en)
{
#define VECTOR_6_M_LEN 123
#define VECTOR_6_E_LEN 24
#define VECTOR_6_S_LEN 64
    unsigned char entropy[] = {
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80
    };
    size_t entropy_l = VECTOR_6_E_LEN;
    unsigned char mnemonic_ref[] = "letter advice cage absurd amount doctor acoustic avoid letter advice cage absurd amount doctor acoustic avoid letter always";
    unsigned char seed_ref[] = {
0x10,0x7d,0x7c,0x02,0xa5,0xaa,0x6f,0x38,0xc5,0x80,0x83,0xff,0x74,0xf0,0x4c,0x60,0x7c,0x2d,0x2c,0x0e,0xcc,0x55,0x50,0x1d,0xad,0xd7,0x2d,0x02,0x5b,0x75,0x1b,0xc2,0x7f,0xe9,0x13,0xff,0xb7,0x96,0xf8,0x41,0xc4,0x9b,0x1d,0x33,0xb6,0x10,0xcf,0x0e,0x91,0xd3,0xaa,0x23,0x90,0x27,0xf5,0xe9,0x9f,0xe4,0xce,0x9e,0x50,0x88,0xcd,0x65
    };

    int err=0;
    unsigned char *mnemonic;
    err = entropy_to_mnemonic(
        NULL,
        entropy, entropy_l,
        &mnemonic
    );

    ck_assert_msg(
        err >= 0,
        "entropy_to_mnemonic nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        mnemonic != NULL,
        "Output mnemonic is NULL."
    );

    size_t mnemonic_l = strlen((char *) mnemonic);
    ck_assert_msg(
        mnemonic_l == VECTOR_6_M_LEN,
        "Output mnemonic size didn't match = %llu.",
        mnemonic_l
    );

    ck_assert_msg(
        memcmp(mnemonic, mnemonic_ref, VECTOR_6_M_LEN) == 0,
        "Output didn't match."
    );

    unsigned char* seed;
    err = mnemonic_to_seed(
        mnemonic, mnemonic_l,
        (unsigned char*) VECTOR_PASSPHRASE, VECTOR_PASSPHRASE_L,
        &seed
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_seed nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        seed != NULL,
        "Output seed is NULL."
    );

    ck_assert_msg(
        memcmp(seed, seed_ref, VECTOR_6_S_LEN) == 0,
        "Output seed didn't match."
    );

    unsigned char* s_entropy;
    size_t s_entropy_l;
    err = mnemonic_to_entropy(
        NULL,
        mnemonic_ref, VECTOR_6_M_LEN,
        &s_entropy, &s_entropy_l
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_entropy nonzero error code = %llu.",
        err
    );

    ck_assert_msg(
        s_entropy != NULL,
        "Output entropy is NULL."
    );

    ck_assert_msg(
        s_entropy_l == VECTOR_6_E_LEN,
        "Output entropy size didn't match = %d.",
        s_entropy_l
    );

    ck_assert_msg(
        memcmp(s_entropy, entropy, VECTOR_6_E_LEN) == 0,
        "Output entropy didn't match."
    );

    free(mnemonic);
    free(seed);
    free(s_entropy);
}
END_TEST

START_TEST (vector_7_en)
{
#define VECTOR_7_M_LEN 72
#define VECTOR_7_E_LEN 24
#define VECTOR_7_S_LEN 64
    unsigned char entropy[] = {
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
    };
    size_t entropy_l = VECTOR_7_E_LEN;
    unsigned char mnemonic_ref[] = "zoo zoo zoo zoo zoo zoo zoo zoo zoo zoo zoo zoo zoo zoo zoo zoo zoo when";
    unsigned char seed_ref[] = {
0x0c,0xd6,0xe5,0xd8,0x27,0xbb,0x62,0xeb,0x8f,0xc1,0xe2,0x62,0x25,0x42,0x23,0x81,0x7f,0xd0,0x68,0xa7,0x4b,0x5b,0x44,0x9c,0xc2,0xf6,0x67,0xc3,0xf1,0xf9,0x85,0xa7,0x63,0x79,0xb4,0x33,0x48,0xd9,0x52,0xe2,0x26,0x5b,0x4c,0xd1,0x29,0x09,0x07,0x58,0xb3,0xe3,0xc2,0xc4,0x91,0x03,0xb5,0x05,0x1a,0xac,0x2e,0xae,0xb8,0x90,0xa5,0x28
    };

    int err=0;
    unsigned char *mnemonic;
    err = entropy_to_mnemonic(
        NULL,
        entropy, entropy_l,
        &mnemonic
    );

    ck_assert_msg(
        err >= 0,
        "entropy_to_mnemonic nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        mnemonic != NULL,
        "Output mnemonic is NULL."
    );

    size_t mnemonic_l = strlen((char *) mnemonic);
    ck_assert_msg(
        mnemonic_l == VECTOR_7_M_LEN,
        "Output mnemonic size didn't match = %llu.",
        mnemonic_l
    );

    ck_assert_msg(
        memcmp(mnemonic, mnemonic_ref, VECTOR_7_M_LEN) == 0,
        "Output didn't match."
    );

    unsigned char* seed;
    err = mnemonic_to_seed(
        mnemonic, mnemonic_l,
        (unsigned char*) VECTOR_PASSPHRASE, VECTOR_PASSPHRASE_L,
        &seed
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_seed nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        seed != NULL,
        "Output seed is NULL."
    );

    ck_assert_msg(
        memcmp(seed, seed_ref, VECTOR_7_S_LEN) == 0,
        "Output seed didn't match."
    );

    unsigned char* s_entropy;
    size_t s_entropy_l;
    err = mnemonic_to_entropy(
        NULL,
        mnemonic_ref, VECTOR_7_M_LEN,
        &s_entropy, &s_entropy_l
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_entropy nonzero error code = %llu.",
        err
    );

    ck_assert_msg(
        s_entropy != NULL,
        "Output entropy is NULL."
    );

    ck_assert_msg(
        s_entropy_l == VECTOR_7_E_LEN,
        "Output entropy size didn't match = %d.",
        s_entropy_l
    );

    ck_assert_msg(
        memcmp(s_entropy, entropy, VECTOR_7_E_LEN) == 0,
        "Output entropy didn't match."
    );

    free(mnemonic);
    free(seed);
    free(s_entropy);
}
END_TEST

START_TEST (vector_8_en)
{
#define VECTOR_8_M_LEN 187
#define VECTOR_8_E_LEN 32
#define VECTOR_8_S_LEN 64
    unsigned char entropy[] = {
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
    };
    size_t entropy_l = VECTOR_8_E_LEN;
    unsigned char mnemonic_ref[] = "abandon abandon abandon abandon abandon abandon abandon abandon abandon abandon abandon abandon abandon abandon abandon abandon abandon abandon abandon abandon abandon abandon abandon art";
    unsigned char seed_ref[] = {
0xbd,0xa8,0x54,0x46,0xc6,0x84,0x13,0x70,0x70,0x90,0xa5,0x20,0x22,0xed,0xd2,0x6a,0x1c,0x94,0x62,0x29,0x50,0x29,0xf2,0xe6,0x0c,0xd7,0xc4,0xf2,0xbb,0xd3,0x09,0x71,0x70,0xaf,0x7a,0x4d,0x73,0x24,0x5c,0xaf,0xa9,0xc3,0xcc,0xa8,0xd5,0x61,0xa7,0xc3,0xde,0x6f,0x5d,0x4a,0x10,0xbe,0x8e,0xd2,0xa5,0xe6,0x08,0xd6,0x8f,0x92,0xfc,0xc8
    };

    int err=0;
    unsigned char *mnemonic;
    err = entropy_to_mnemonic(
        NULL,
        entropy, entropy_l,
        &mnemonic
    );

    ck_assert_msg(
        err >= 0,
        "entropy_to_mnemonic nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        mnemonic != NULL,
        "Output mnemonic is NULL."
    );

    size_t mnemonic_l = strlen((char *) mnemonic);
    ck_assert_msg(
        mnemonic_l == VECTOR_8_M_LEN,
        "Output mnemonic size didn't match = %llu.",
        mnemonic_l
    );

    ck_assert_msg(
        memcmp(mnemonic, mnemonic_ref, VECTOR_8_M_LEN) == 0,
        "Output didn't match."
    );

    unsigned char* seed;
    err = mnemonic_to_seed(
        mnemonic, mnemonic_l,
        (unsigned char*) VECTOR_PASSPHRASE, VECTOR_PASSPHRASE_L,
        &seed
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_seed nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        seed != NULL,
        "Output seed is NULL."
    );

    ck_assert_msg(
        memcmp(seed, seed_ref, VECTOR_8_S_LEN) == 0,
        "Output seed didn't match."
    );

    unsigned char* s_entropy;
    size_t s_entropy_l;
    err = mnemonic_to_entropy(
        NULL,
        mnemonic_ref, VECTOR_8_M_LEN,
        &s_entropy, &s_entropy_l
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_entropy nonzero error code = %llu.",
        err
    );

    ck_assert_msg(
        s_entropy != NULL,
        "Output entropy is NULL."
    );

    ck_assert_msg(
        s_entropy_l == VECTOR_8_E_LEN,
        "Output entropy size didn't match = %d.",
        s_entropy_l
    );

    ck_assert_msg(
        memcmp(s_entropy, entropy, VECTOR_8_E_LEN) == 0,
        "Output entropy didn't match."
    );

    free(mnemonic);
    free(seed);
    free(s_entropy);
}
END_TEST

START_TEST (vector_9_en)
{
#define VECTOR_9_M_LEN 148
#define VECTOR_9_E_LEN 32
#define VECTOR_9_S_LEN 64
    unsigned char entropy[] = {
0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f
    };
    size_t entropy_l = VECTOR_9_E_LEN;
    unsigned char mnemonic_ref[] = "legal winner thank year wave sausage worth useful legal winner thank year wave sausage worth useful legal winner thank year wave sausage worth title";
    unsigned char seed_ref[] = {
0xbc,0x09,0xfc,0xa1,0x80,0x4f,0x7e,0x69,0xda,0x93,0xc2,0xf2,0x02,0x8e,0xb2,0x38,0xc2,0x27,0xf2,0xe9,0xdd,0xa3,0x0c,0xd6,0x36,0x99,0x23,0x25,0x78,0x48,0x0a,0x40,0x21,0xb1,0x46,0xad,0x71,0x7f,0xbb,0x7e,0x45,0x1c,0xe9,0xeb,0x83,0x5f,0x43,0x62,0x0b,0xf5,0xc5,0x14,0xdb,0x0f,0x8a,0xdd,0x49,0xf5,0xd1,0x21,0x44,0x9d,0x3e,0x87
    };

    int err=0;
    unsigned char *mnemonic;
    err = entropy_to_mnemonic(
        NULL,
        entropy, entropy_l,
        &mnemonic
    );

    ck_assert_msg(
        err >= 0,
        "entropy_to_mnemonic nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        mnemonic != NULL,
        "Output mnemonic is NULL."
    );

    size_t mnemonic_l = strlen((char *) mnemonic);
    ck_assert_msg(
        mnemonic_l == VECTOR_9_M_LEN,
        "Output mnemonic size didn't match = %llu.",
        mnemonic_l
    );

    ck_assert_msg(
        memcmp(mnemonic, mnemonic_ref, VECTOR_9_M_LEN) == 0,
        "Output didn't match."
    );

    unsigned char* seed;
    err = mnemonic_to_seed(
        mnemonic, mnemonic_l,
        (unsigned char*) VECTOR_PASSPHRASE, VECTOR_PASSPHRASE_L,
        &seed
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_seed nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        seed != NULL,
        "Output seed is NULL."
    );

    ck_assert_msg(
        memcmp(seed, seed_ref, VECTOR_9_S_LEN) == 0,
        "Output seed didn't match."
    );

    unsigned char* s_entropy;
    size_t s_entropy_l;
    err = mnemonic_to_entropy(
        NULL,
        mnemonic_ref, VECTOR_9_M_LEN,
        &s_entropy, &s_entropy_l
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_entropy nonzero error code = %llu.",
        err
    );

    ck_assert_msg(
        s_entropy != NULL,
        "Output entropy is NULL."
    );

    ck_assert_msg(
        s_entropy_l == VECTOR_9_E_LEN,
        "Output entropy size didn't match = %d.",
        s_entropy_l
    );

    ck_assert_msg(
        memcmp(s_entropy, entropy, VECTOR_9_E_LEN) == 0,
        "Output entropy didn't match."
    );

    free(mnemonic);
    free(seed);
    free(s_entropy);
}
END_TEST

START_TEST (vector_10_en)
{
#define VECTOR_10_M_LEN 164
#define VECTOR_10_E_LEN 32
#define VECTOR_10_S_LEN 64
    unsigned char entropy[] = {
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80
    };
    size_t entropy_l = VECTOR_10_E_LEN;
    unsigned char mnemonic_ref[] = "letter advice cage absurd amount doctor acoustic avoid letter advice cage absurd amount doctor acoustic avoid letter advice cage absurd amount doctor acoustic bless";
    unsigned char seed_ref[] = {
0xc0,0xc5,0x19,0xbd,0x0e,0x91,0xa2,0xed,0x54,0x35,0x7d,0x9d,0x1e,0xbe,0xf6,0xf5,0xaf,0x21,0x8a,0x15,0x36,0x24,0xcf,0x4f,0x2d,0xa9,0x11,0xa0,0xed,0x8f,0x7a,0x09,0xe2,0xef,0x61,0xaf,0x0a,0xca,0x00,0x70,0x96,0xdf,0x43,0x00,0x22,0xf7,0xa2,0xb6,0xfb,0x91,0x66,0x1a,0x95,0x89,0x09,0x70,0x69,0x72,0x0d,0x01,0x5e,0x4e,0x98,0x2f
    };

    int err=0;
    unsigned char *mnemonic;
    err = entropy_to_mnemonic(
        NULL,
        entropy, entropy_l,
        &mnemonic
    );

    ck_assert_msg(
        err >= 0,
        "entropy_to_mnemonic nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        mnemonic != NULL,
        "Output mnemonic is NULL."
    );

    size_t mnemonic_l = strlen((char *) mnemonic);
    ck_assert_msg(
        mnemonic_l == VECTOR_10_M_LEN,
        "Output mnemonic size didn't match = %llu.",
        mnemonic_l
    );

    ck_assert_msg(
        memcmp(mnemonic, mnemonic_ref, VECTOR_10_M_LEN) == 0,
        "Output didn't match."
    );

    unsigned char* seed;
    err = mnemonic_to_seed(
        mnemonic, mnemonic_l,
        (unsigned char*) VECTOR_PASSPHRASE, VECTOR_PASSPHRASE_L,
        &seed
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_seed nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        seed != NULL,
        "Output seed is NULL."
    );

    ck_assert_msg(
        memcmp(seed, seed_ref, VECTOR_10_S_LEN) == 0,
        "Output seed didn't match."
    );

    unsigned char* s_entropy;
    size_t s_entropy_l;
    err = mnemonic_to_entropy(
        NULL,
        mnemonic_ref, VECTOR_10_M_LEN,
        &s_entropy, &s_entropy_l
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_entropy nonzero error code = %llu.",
        err
    );

    ck_assert_msg(
        s_entropy != NULL,
        "Output entropy is NULL."
    );

    ck_assert_msg(
        s_entropy_l == VECTOR_10_E_LEN,
        "Output entropy size didn't match = %d.",
        s_entropy_l
    );

    ck_assert_msg(
        memcmp(s_entropy, entropy, VECTOR_10_E_LEN) == 0,
        "Output entropy didn't match."
    );

    free(mnemonic);
    free(seed);
    free(s_entropy);
}
END_TEST

START_TEST (vector_11_en)
{
#define VECTOR_11_M_LEN 96
#define VECTOR_11_E_LEN 32
#define VECTOR_11_S_LEN 64
    unsigned char entropy[] = {
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
    };
    size_t entropy_l = VECTOR_11_E_LEN;
    unsigned char mnemonic_ref[] = "zoo zoo zoo zoo zoo zoo zoo zoo zoo zoo zoo zoo zoo zoo zoo zoo zoo zoo zoo zoo zoo zoo zoo vote";
    unsigned char seed_ref[] = {
0xdd,0x48,0xc1,0x04,0x69,0x8c,0x30,0xcf,0xe2,0xb6,0x14,0x21,0x03,0x24,0x86,0x22,0xfb,0x7b,0xb0,0xff,0x69,0x2e,0xeb,0xb0,0x00,0x89,0xb3,0x2d,0x22,0x48,0x4e,0x16,0x13,0x91,0x2f,0x0a,0x5b,0x69,0x44,0x07,0xbe,0x89,0x9f,0xfd,0x31,0xed,0x39,0x92,0xc4,0x56,0xcd,0xf6,0x0f,0x5d,0x45,0x64,0xb8,0xba,0x3f,0x05,0xa6,0x98,0x90,0xad
    };

    int err=0;
    unsigned char *mnemonic;
    err = entropy_to_mnemonic(
        NULL,
        entropy, entropy_l,
        &mnemonic
    );

    ck_assert_msg(
        err >= 0,
        "entropy_to_mnemonic nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        mnemonic != NULL,
        "Output mnemonic is NULL."
    );

    size_t mnemonic_l = strlen((char *) mnemonic);
    ck_assert_msg(
        mnemonic_l == VECTOR_11_M_LEN,
        "Output mnemonic size didn't match = %llu.",
        mnemonic_l
    );

    ck_assert_msg(
        memcmp(mnemonic, mnemonic_ref, VECTOR_11_M_LEN) == 0,
        "Output didn't match."
    );

    unsigned char* seed;
    err = mnemonic_to_seed(
        mnemonic, mnemonic_l,
        (unsigned char*) VECTOR_PASSPHRASE, VECTOR_PASSPHRASE_L,
        &seed
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_seed nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        seed != NULL,
        "Output seed is NULL."
    );

    ck_assert_msg(
        memcmp(seed, seed_ref, VECTOR_11_S_LEN) == 0,
        "Output seed didn't match."
    );

    unsigned char* s_entropy;
    size_t s_entropy_l;
    err = mnemonic_to_entropy(
        NULL,
        mnemonic_ref, VECTOR_11_M_LEN,
        &s_entropy, &s_entropy_l
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_entropy nonzero error code = %llu.",
        err
    );

    ck_assert_msg(
        s_entropy != NULL,
        "Output entropy is NULL."
    );

    ck_assert_msg(
        s_entropy_l == VECTOR_11_E_LEN,
        "Output entropy size didn't match = %d.",
        s_entropy_l
    );

    ck_assert_msg(
        memcmp(s_entropy, entropy, VECTOR_11_E_LEN) == 0,
        "Output entropy didn't match."
    );

    free(mnemonic);
    free(seed);
    free(s_entropy);
}
END_TEST

START_TEST (vector_12_en)
{
#define VECTOR_12_M_LEN 76
#define VECTOR_12_E_LEN 16
#define VECTOR_12_S_LEN 64
    unsigned char entropy[] = {
0x9e,0x88,0x5d,0x95,0x2a,0xd3,0x62,0xca,0xeb,0x4e,0xfe,0x34,0xa8,0xe9,0x1b,0xd2
    };
    size_t entropy_l = VECTOR_12_E_LEN;
    unsigned char mnemonic_ref[] = "ozone drill grab fiber curtain grace pudding thank cruise elder eight picnic";
    unsigned char seed_ref[] = {
0x27,0x4d,0xdc,0x52,0x58,0x02,0xf7,0xc8,0x28,0xd8,0xef,0x7d,0xdb,0xcd,0xc5,0x30,0x4e,0x87,0xac,0x35,0x35,0x91,0x36,0x11,0xfb,0xbf,0xa9,0x86,0xd0,0xc9,0xe5,0x47,0x6c,0x91,0x68,0x9f,0x9c,0x8a,0x54,0xfd,0x55,0xbd,0x38,0x60,0x6a,0xa6,0xa8,0x59,0x5a,0xd2,0x13,0xd4,0xc9,0xc9,0xf9,0xac,0xa3,0xfb,0x21,0x70,0x69,0xa4,0x10,0x28
    };

    int err=0;
    unsigned char *mnemonic;
    err = entropy_to_mnemonic(
        NULL,
        entropy, entropy_l,
        &mnemonic
    );

    ck_assert_msg(
        err >= 0,
        "entropy_to_mnemonic nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        mnemonic != NULL,
        "Output mnemonic is NULL."
    );

    size_t mnemonic_l = strlen((char *) mnemonic);
    ck_assert_msg(
        mnemonic_l == VECTOR_12_M_LEN,
        "Output mnemonic size didn't match = %llu.",
        mnemonic_l
    );

    ck_assert_msg(
        memcmp(mnemonic, mnemonic_ref, VECTOR_12_M_LEN) == 0,
        "Output didn't match."
    );

    unsigned char* seed;
    err = mnemonic_to_seed(
        mnemonic, mnemonic_l,
        (unsigned char*) VECTOR_PASSPHRASE, VECTOR_PASSPHRASE_L,
        &seed
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_seed nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        seed != NULL,
        "Output seed is NULL."
    );

    ck_assert_msg(
        memcmp(seed, seed_ref, VECTOR_12_S_LEN) == 0,
        "Output seed didn't match."
    );

    unsigned char* s_entropy;
    size_t s_entropy_l;
    err = mnemonic_to_entropy(
        NULL,
        mnemonic_ref, VECTOR_12_M_LEN,
        &s_entropy, &s_entropy_l
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_entropy nonzero error code = %llu.",
        err
    );

    ck_assert_msg(
        s_entropy != NULL,
        "Output entropy is NULL."
    );

    ck_assert_msg(
        s_entropy_l == VECTOR_12_E_LEN,
        "Output entropy size didn't match = %d.",
        s_entropy_l
    );

    ck_assert_msg(
        memcmp(s_entropy, entropy, VECTOR_12_E_LEN) == 0,
        "Output entropy didn't match."
    );

    free(mnemonic);
    free(seed);
    free(s_entropy);
}
END_TEST

START_TEST (vector_13_en)
{
#define VECTOR_13_M_LEN 119
#define VECTOR_13_E_LEN 24
#define VECTOR_13_S_LEN 64
    unsigned char entropy[] = {
0x66,0x10,0xb2,0x59,0x67,0xcd,0xcc,0xa9,0xd5,0x98,0x75,0xf5,0xcb,0x50,0xb0,0xea,0x75,0x43,0x33,0x11,0x86,0x9e,0x93,0x0b
    };
    size_t entropy_l = VECTOR_13_E_LEN;
    unsigned char mnemonic_ref[] = "gravity machine north sort system female filter attitude volume fold club stay feature office ecology stable narrow fog";
    unsigned char seed_ref[] = {
0x62,0x8c,0x38,0x27,0xa8,0x82,0x32,0x98,0xee,0x68,0x5d,0xb8,0x4f,0x55,0xca,0xa3,0x4b,0x5c,0xc1,0x95,0xa7,0x78,0xe5,0x2d,0x45,0xf5,0x9b,0xcf,0x75,0xab,0xa6,0x8e,0x4d,0x75,0x90,0xe1,0x01,0xdc,0x41,0x4b,0xc1,0xbb,0xd5,0x73,0x76,0x66,0xfb,0xbe,0xf3,0x5d,0x1f,0x19,0x03,0x95,0x3b,0x66,0x62,0x4f,0x91,0x0f,0xee,0xf2,0x45,0xac
    };

    int err=0;
    unsigned char *mnemonic;
    err = entropy_to_mnemonic(
        NULL,
        entropy, entropy_l,
        &mnemonic
    );

    ck_assert_msg(
        err >= 0,
        "entropy_to_mnemonic nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        mnemonic != NULL,
        "Output mnemonic is NULL."
    );

    size_t mnemonic_l = strlen((char *) mnemonic);
    ck_assert_msg(
        mnemonic_l == VECTOR_13_M_LEN,
        "Output mnemonic size didn't match = %llu.",
        mnemonic_l
    );

    ck_assert_msg(
        memcmp(mnemonic, mnemonic_ref, VECTOR_13_M_LEN) == 0,
        "Output didn't match."
    );

    unsigned char* seed;
    err = mnemonic_to_seed(
        mnemonic, mnemonic_l,
        (unsigned char*) VECTOR_PASSPHRASE, VECTOR_PASSPHRASE_L,
        &seed
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_seed nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        seed != NULL,
        "Output seed is NULL."
    );

    ck_assert_msg(
        memcmp(seed, seed_ref, VECTOR_13_S_LEN) == 0,
        "Output seed didn't match."
    );

    unsigned char* s_entropy;
    size_t s_entropy_l;
    err = mnemonic_to_entropy(
        NULL,
        mnemonic_ref, VECTOR_13_M_LEN,
        &s_entropy, &s_entropy_l
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_entropy nonzero error code = %llu.",
        err
    );

    ck_assert_msg(
        s_entropy != NULL,
        "Output entropy is NULL."
    );

    ck_assert_msg(
        s_entropy_l == VECTOR_13_E_LEN,
        "Output entropy size didn't match = %d.",
        s_entropy_l
    );

    ck_assert_msg(
        memcmp(s_entropy, entropy, VECTOR_13_E_LEN) == 0,
        "Output entropy didn't match."
    );

    free(mnemonic);
    free(seed);
    free(s_entropy);
}
END_TEST

START_TEST (vector_14_en)
{
#define VECTOR_14_M_LEN 156
#define VECTOR_14_E_LEN 32
#define VECTOR_14_S_LEN 64
    unsigned char entropy[] = {
0x68,0xa7,0x9e,0xac,0xa2,0x32,0x48,0x73,0xea,0xcc,0x50,0xcb,0x9c,0x6e,0xca,0x8c,0xc6,0x8e,0xa5,0xd9,0x36,0xf9,0x87,0x87,0xc6,0x0c,0x7e,0xbc,0x74,0xe6,0xce,0x7c
    };
    size_t entropy_l = VECTOR_14_E_LEN;
    unsigned char mnemonic_ref[] = "hamster diagram private dutch cause delay private meat slide toddler razor book happy fancy gospel tennis maple dilemma loan word shrug inflict delay length";
    unsigned char seed_ref[] = {
0x64,0xc8,0x7c,0xde,0x7e,0x12,0xec,0xf6,0x70,0x4a,0xb9,0x5b,0xb1,0x40,0x8b,0xef,0x04,0x7c,0x22,0xdb,0x4c,0xc7,0x49,0x1c,0x42,0x71,0xd1,0x70,0xa1,0xb2,0x13,0xd2,0x0b,0x38,0x5b,0xc1,0x58,0x8d,0x9c,0x7b,0x38,0xf1,0xb3,0x9d,0x41,0x56,0x65,0xb8,0xa9,0x03,0x0c,0x9e,0xc6,0x53,0xd7,0x5e,0x65,0xf8,0x47,0xd8,0xfc,0x1f,0xc4,0x40
    };

    int err=0;
    unsigned char *mnemonic;
    err = entropy_to_mnemonic(
        NULL,
        entropy, entropy_l,
        &mnemonic
    );

    ck_assert_msg(
        err >= 0,
        "entropy_to_mnemonic nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        mnemonic != NULL,
        "Output mnemonic is NULL."
    );

    size_t mnemonic_l = strlen((char *) mnemonic);
    ck_assert_msg(
        mnemonic_l == VECTOR_14_M_LEN,
        "Output mnemonic size didn't match = %llu.",
        mnemonic_l
    );

    ck_assert_msg(
        memcmp(mnemonic, mnemonic_ref, VECTOR_14_M_LEN) == 0,
        "Output didn't match."
    );

    unsigned char* seed;
    err = mnemonic_to_seed(
        mnemonic, mnemonic_l,
        (unsigned char*) VECTOR_PASSPHRASE, VECTOR_PASSPHRASE_L,
        &seed
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_seed nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        seed != NULL,
        "Output seed is NULL."
    );

    ck_assert_msg(
        memcmp(seed, seed_ref, VECTOR_14_S_LEN) == 0,
        "Output seed didn't match."
    );

    unsigned char* s_entropy;
    size_t s_entropy_l;
    err = mnemonic_to_entropy(
        NULL,
        mnemonic_ref, VECTOR_14_M_LEN,
        &s_entropy, &s_entropy_l
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_entropy nonzero error code = %llu.",
        err
    );

    ck_assert_msg(
        s_entropy != NULL,
        "Output entropy is NULL."
    );

    ck_assert_msg(
        s_entropy_l == VECTOR_14_E_LEN,
        "Output entropy size didn't match = %d.",
        s_entropy_l
    );

    ck_assert_msg(
        memcmp(s_entropy, entropy, VECTOR_14_E_LEN) == 0,
        "Output entropy didn't match."
    );

    free(mnemonic);
    free(seed);
    free(s_entropy);
}
END_TEST

START_TEST (vector_15_en)
{
#define VECTOR_15_M_LEN 72
#define VECTOR_15_E_LEN 16
#define VECTOR_15_S_LEN 64
    unsigned char entropy[] = {
0xc0,0xba,0x5a,0x8e,0x91,0x41,0x11,0x21,0x0f,0x2b,0xd1,0x31,0xf3,0xd5,0xe0,0x8d
    };
    size_t entropy_l = VECTOR_15_E_LEN;
    unsigned char mnemonic_ref[] = "scheme spot photo card baby mountain device kick cradle pact join borrow";
    unsigned char seed_ref[] = {
0xea,0x72,0x58,0x95,0xaa,0xae,0x8d,0x4c,0x1c,0xf6,0x82,0xc1,0xbf,0xd2,0xd3,0x58,0xd5,0x2e,0xd9,0xf0,0xf0,0x59,0x11,0x31,0xb5,0x59,0xe2,0x72,0x4b,0xb2,0x34,0xfc,0xa0,0x5a,0xa9,0xc0,0x2c,0x57,0x40,0x7e,0x04,0xee,0x9d,0xc3,0xb4,0x54,0xaa,0x63,0xfb,0xff,0x48,0x3a,0x8b,0x11,0xde,0x94,0x96,0x24,0xb9,0xf1,0x83,0x1a,0x96,0x12
    };

    int err=0;
    unsigned char *mnemonic;
    err = entropy_to_mnemonic(
        NULL,
        entropy, entropy_l,
        &mnemonic
    );

    ck_assert_msg(
        err >= 0,
        "entropy_to_mnemonic nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        mnemonic != NULL,
        "Output mnemonic is NULL."
    );

    size_t mnemonic_l = strlen((char *) mnemonic);
    ck_assert_msg(
        mnemonic_l == VECTOR_15_M_LEN,
        "Output mnemonic size didn't match = %llu.",
        mnemonic_l
    );

    ck_assert_msg(
        memcmp(mnemonic, mnemonic_ref, VECTOR_15_M_LEN) == 0,
        "Output didn't match."
    );

    unsigned char* seed;
    err = mnemonic_to_seed(
        mnemonic, mnemonic_l,
        (unsigned char*) VECTOR_PASSPHRASE, VECTOR_PASSPHRASE_L,
        &seed
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_seed nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        seed != NULL,
        "Output seed is NULL."
    );

    ck_assert_msg(
        memcmp(seed, seed_ref, VECTOR_15_S_LEN) == 0,
        "Output seed didn't match."
    );

    unsigned char* s_entropy;
    size_t s_entropy_l;
    err = mnemonic_to_entropy(
        NULL,
        mnemonic_ref, VECTOR_15_M_LEN,
        &s_entropy, &s_entropy_l
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_entropy nonzero error code = %llu.",
        err
    );

    ck_assert_msg(
        s_entropy != NULL,
        "Output entropy is NULL."
    );

    ck_assert_msg(
        s_entropy_l == VECTOR_15_E_LEN,
        "Output entropy size didn't match = %d.",
        s_entropy_l
    );

    ck_assert_msg(
        memcmp(s_entropy, entropy, VECTOR_15_E_LEN) == 0,
        "Output entropy didn't match."
    );

    free(mnemonic);
    free(seed);
    free(s_entropy);
}
END_TEST

START_TEST (vector_16_en)
{
#define VECTOR_16_M_LEN 106
#define VECTOR_16_E_LEN 24
#define VECTOR_16_S_LEN 64
    unsigned char entropy[] = {
0x6d,0x9b,0xe1,0xee,0x6e,0xbd,0x27,0xa2,0x58,0x11,0x5a,0xad,0x99,0xb7,0x31,0x7b,0x9c,0x8d,0x28,0xb6,0xd7,0x64,0x31,0xc3
    };
    size_t entropy_l = VECTOR_16_E_LEN;
    unsigned char mnemonic_ref[] = "horn tenant knee talent sponsor spell gate clip pulse soap slush warm silver nephew swap uncle crack brave";
    unsigned char seed_ref[] = {
0xfd,0x57,0x98,0x28,0xaf,0x3d,0xa1,0xd3,0x25,0x44,0xce,0x4d,0xb5,0xc7,0x3d,0x53,0xfc,0x8a,0xcc,0x4d,0xdb,0x1e,0x3b,0x25,0x1a,0x31,0x17,0x9c,0xdb,0x71,0xe8,0x53,0xc5,0x6d,0x2f,0xcb,0x11,0xae,0xd3,0x98,0x98,0xce,0x6c,0x34,0xb1,0x0b,0x53,0x82,0x77,0x2d,0xb8,0x79,0x6e,0x52,0x83,0x7b,0x54,0x46,0x8a,0xeb,0x31,0x2c,0xfc,0x3d
    };

    int err=0;
    unsigned char *mnemonic;
    err = entropy_to_mnemonic(
        NULL,
        entropy, entropy_l,
        &mnemonic
    );

    ck_assert_msg(
        err >= 0,
        "entropy_to_mnemonic nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        mnemonic != NULL,
        "Output mnemonic is NULL."
    );

    size_t mnemonic_l = strlen((char *) mnemonic);
    ck_assert_msg(
        mnemonic_l == VECTOR_16_M_LEN,
        "Output mnemonic size didn't match = %llu.",
        mnemonic_l
    );

    ck_assert_msg(
        memcmp(mnemonic, mnemonic_ref, VECTOR_16_M_LEN) == 0,
        "Output didn't match."
    );

    unsigned char* seed;
    err = mnemonic_to_seed(
        mnemonic, mnemonic_l,
        (unsigned char*) VECTOR_PASSPHRASE, VECTOR_PASSPHRASE_L,
        &seed
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_seed nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        seed != NULL,
        "Output seed is NULL."
    );

    ck_assert_msg(
        memcmp(seed, seed_ref, VECTOR_16_S_LEN) == 0,
        "Output seed didn't match."
    );

    unsigned char* s_entropy;
    size_t s_entropy_l;
    err = mnemonic_to_entropy(
        NULL,
        mnemonic_ref, VECTOR_16_M_LEN,
        &s_entropy, &s_entropy_l
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_entropy nonzero error code = %llu.",
        err
    );

    ck_assert_msg(
        s_entropy != NULL,
        "Output entropy is NULL."
    );

    ck_assert_msg(
        s_entropy_l == VECTOR_16_E_LEN,
        "Output entropy size didn't match = %d.",
        s_entropy_l
    );

    ck_assert_msg(
        memcmp(s_entropy, entropy, VECTOR_16_E_LEN) == 0,
        "Output entropy didn't match."
    );

    free(mnemonic);
    free(seed);
    free(s_entropy);
}
END_TEST

START_TEST (vector_17_en)
{
#define VECTOR_17_M_LEN 156
#define VECTOR_17_E_LEN 32
#define VECTOR_17_S_LEN 64
    unsigned char entropy[] = {
0x9f,0x6a,0x28,0x78,0xb2,0x52,0x07,0x99,0xa4,0x4e,0xf1,0x8b,0xc7,0xdf,0x39,0x4e,0x70,0x61,0xa2,0x24,0xd2,0xc3,0x3c,0xd0,0x15,0xb1,0x57,0xd7,0x46,0x86,0x98,0x63
    };
    size_t entropy_l = VECTOR_17_E_LEN;
    unsigned char mnemonic_ref[] = "panda eyebrow bullet gorilla call smoke muffin taste mesh discover soft ostrich alcohol speed nation flash devote level hobby quick inner drive ghost inside";
    unsigned char seed_ref[] = {
0x72,0xbe,0x8e,0x05,0x2f,0xc4,0x91,0x9d,0x2a,0xdf,0x28,0xd5,0x30,0x6b,0x54,0x74,0xb0,0x06,0x9d,0xf3,0x5b,0x02,0x30,0x3d,0xe8,0xc1,0x72,0x9c,0x95,0x38,0xdb,0xb6,0xfc,0x2d,0x73,0x1d,0x5f,0x83,0x21,0x93,0xcd,0x9f,0xb6,0xae,0xec,0xbc,0x46,0x95,0x94,0xa7,0x0e,0x3d,0xd5,0x08,0x11,0xb5,0x06,0x7f,0x3b,0x88,0xb2,0x8c,0x3e,0x8d
    };

    int err=0;
    unsigned char *mnemonic;
    err = entropy_to_mnemonic(
        NULL,
        entropy, entropy_l,
        &mnemonic
    );

    ck_assert_msg(
        err >= 0,
        "entropy_to_mnemonic nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        mnemonic != NULL,
        "Output mnemonic is NULL."
    );

    size_t mnemonic_l = strlen((char *) mnemonic);
    ck_assert_msg(
        mnemonic_l == VECTOR_17_M_LEN,
        "Output mnemonic size didn't match = %llu.",
        mnemonic_l
    );

    ck_assert_msg(
        memcmp(mnemonic, mnemonic_ref, VECTOR_17_M_LEN) == 0,
        "Output didn't match."
    );

    unsigned char* seed;
    err = mnemonic_to_seed(
        mnemonic, mnemonic_l,
        (unsigned char*) VECTOR_PASSPHRASE, VECTOR_PASSPHRASE_L,
        &seed
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_seed nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        seed != NULL,
        "Output seed is NULL."
    );

    ck_assert_msg(
        memcmp(seed, seed_ref, VECTOR_17_S_LEN) == 0,
        "Output seed didn't match."
    );

    unsigned char* s_entropy;
    size_t s_entropy_l;
    err = mnemonic_to_entropy(
        NULL,
        mnemonic_ref, VECTOR_17_M_LEN,
        &s_entropy, &s_entropy_l
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_entropy nonzero error code = %llu.",
        err
    );

    ck_assert_msg(
        s_entropy != NULL,
        "Output entropy is NULL."
    );

    ck_assert_msg(
        s_entropy_l == VECTOR_17_E_LEN,
        "Output entropy size didn't match = %d.",
        s_entropy_l
    );

    ck_assert_msg(
        memcmp(s_entropy, entropy, VECTOR_17_E_LEN) == 0,
        "Output entropy didn't match."
    );

    free(mnemonic);
    free(seed);
    free(s_entropy);
}
END_TEST

START_TEST (vector_18_en)
{
#define VECTOR_18_M_LEN 74
#define VECTOR_18_E_LEN 16
#define VECTOR_18_S_LEN 64
    unsigned char entropy[] = {
0x23,0xdb,0x81,0x60,0xa3,0x1d,0x3e,0x0d,0xca,0x36,0x88,0xed,0x94,0x1a,0xdb,0xf3
    };
    size_t entropy_l = VECTOR_18_E_LEN;
    unsigned char mnemonic_ref[] = "cat swing flag economy stadium alone churn speed unique patch report train";
    unsigned char seed_ref[] = {
0xde,0xb5,0xf4,0x54,0x49,0xe6,0x15,0xfe,0xff,0x56,0x40,0xf2,0xe4,0x9f,0x93,0x3f,0xf5,0x18,0x95,0xde,0x3b,0x43,0x81,0x83,0x2b,0x31,0x39,0x94,0x1c,0x57,0xb5,0x92,0x05,0xa4,0x24,0x80,0xc5,0x21,0x75,0xb6,0xef,0xcf,0xfa,0xa5,0x8a,0x25,0x03,0x88,0x7c,0x1e,0x8b,0x36,0x3a,0x70,0x72,0x56,0xbd,0xd2,0xb5,0x87,0xb4,0x65,0x41,0xf5
    };

    int err=0;
    unsigned char *mnemonic;
    err = entropy_to_mnemonic(
        NULL,
        entropy, entropy_l,
        &mnemonic
    );

    ck_assert_msg(
        err >= 0,
        "entropy_to_mnemonic nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        mnemonic != NULL,
        "Output mnemonic is NULL."
    );

    size_t mnemonic_l = strlen((char *) mnemonic);
    ck_assert_msg(
        mnemonic_l == VECTOR_18_M_LEN,
        "Output mnemonic size didn't match = %llu.",
        mnemonic_l
    );

    ck_assert_msg(
        memcmp(mnemonic, mnemonic_ref, VECTOR_18_M_LEN) == 0,
        "Output didn't match."
    );

    unsigned char* seed;
    err = mnemonic_to_seed(
        mnemonic, mnemonic_l,
        (unsigned char*) VECTOR_PASSPHRASE, VECTOR_PASSPHRASE_L,
        &seed
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_seed nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        seed != NULL,
        "Output seed is NULL."
    );

    ck_assert_msg(
        memcmp(seed, seed_ref, VECTOR_18_S_LEN) == 0,
        "Output seed didn't match."
    );

    unsigned char* s_entropy;
    size_t s_entropy_l;
    err = mnemonic_to_entropy(
        NULL,
        mnemonic_ref, VECTOR_18_M_LEN,
        &s_entropy, &s_entropy_l
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_entropy nonzero error code = %llu.",
        err
    );

    ck_assert_msg(
        s_entropy != NULL,
        "Output entropy is NULL."
    );

    ck_assert_msg(
        s_entropy_l == VECTOR_18_E_LEN,
        "Output entropy size didn't match = %d.",
        s_entropy_l
    );

    ck_assert_msg(
        memcmp(s_entropy, entropy, VECTOR_18_E_LEN) == 0,
        "Output entropy didn't match."
    );

    free(mnemonic);
    free(seed);
    free(s_entropy);
}
END_TEST

START_TEST (vector_19_en)
{
#define VECTOR_19_M_LEN 118
#define VECTOR_19_E_LEN 24
#define VECTOR_19_S_LEN 64
    unsigned char entropy[] = {
0x81,0x97,0xa4,0xa4,0x7f,0x04,0x25,0xfa,0xea,0xa6,0x9d,0xee,0xbc,0x05,0xca,0x29,0xc0,0xa5,0xb5,0xcc,0x76,0xce,0xac,0xc0
    };
    size_t entropy_l = VECTOR_19_E_LEN;
    unsigned char mnemonic_ref[] = "light rule cinnamon wrap drastic word pride squirrel upgrade then income fatal apart sustain crack supply proud access";
    unsigned char seed_ref[] = {
0x4c,0xbd,0xff,0x1c,0xa2,0xdb,0x80,0x0f,0xd6,0x1c,0xae,0x72,0xa5,0x74,0x75,0xfd,0xc6,0xba,0xb0,0x3e,0x44,0x1f,0xd6,0x3f,0x96,0xda,0xbd,0x1f,0x18,0x3e,0xf5,0xb7,0x82,0x92,0x5f,0x00,0x10,0x5f,0x31,0x83,0x09,0xa7,0xe9,0xc3,0xea,0x69,0x67,0xc7,0x80,0x1e,0x46,0xc8,0xa5,0x80,0x82,0x67,0x4c,0x86,0x0a,0x37,0xb9,0x3e,0xda,0x02
    };

    int err=0;
    unsigned char *mnemonic;
    err = entropy_to_mnemonic(
        NULL,
        entropy, entropy_l,
        &mnemonic
    );

    ck_assert_msg(
        err >= 0,
        "entropy_to_mnemonic nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        mnemonic != NULL,
        "Output mnemonic is NULL."
    );

    size_t mnemonic_l = strlen((char *) mnemonic);
    ck_assert_msg(
        mnemonic_l == VECTOR_19_M_LEN,
        "Output mnemonic size didn't match = %llu.",
        mnemonic_l
    );

    ck_assert_msg(
        memcmp(mnemonic, mnemonic_ref, VECTOR_19_M_LEN) == 0,
        "Output didn't match."
    );

    unsigned char* seed;
    err = mnemonic_to_seed(
        mnemonic, mnemonic_l,
        (unsigned char*) VECTOR_PASSPHRASE, VECTOR_PASSPHRASE_L,
        &seed
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_seed nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        seed != NULL,
        "Output seed is NULL."
    );

    ck_assert_msg(
        memcmp(seed, seed_ref, VECTOR_19_S_LEN) == 0,
        "Output seed didn't match."
    );

    unsigned char* s_entropy;
    size_t s_entropy_l;
    err = mnemonic_to_entropy(
        NULL,
        mnemonic_ref, VECTOR_19_M_LEN,
        &s_entropy, &s_entropy_l
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_entropy nonzero error code = %llu.",
        err
    );

    ck_assert_msg(
        s_entropy != NULL,
        "Output entropy is NULL."
    );

    ck_assert_msg(
        s_entropy_l == VECTOR_19_E_LEN,
        "Output entropy size didn't match = %d.",
        s_entropy_l
    );

    ck_assert_msg(
        memcmp(s_entropy, entropy, VECTOR_19_E_LEN) == 0,
        "Output entropy didn't match."
    );

    free(mnemonic);
    free(seed);
    free(s_entropy);
}
END_TEST

START_TEST (vector_20_en)
{
#define VECTOR_20_M_LEN 146
#define VECTOR_20_E_LEN 32
#define VECTOR_20_S_LEN 64
    unsigned char entropy[] = {
0x06,0x6d,0xca,0x1a,0x2b,0xb7,0xe8,0xa1,0xdb,0x28,0x32,0x14,0x8c,0xe9,0x93,0x3e,0xea,0x0f,0x3a,0xc9,0x54,0x8d,0x79,0x31,0x12,0xd9,0xa9,0x5c,0x94,0x07,0xef,0xad
    };
    size_t entropy_l = VECTOR_20_E_LEN;
    unsigned char mnemonic_ref[] = "all hour make first leader extend hole alien behind guard gospel lava path output census museum junior mass reopen famous sing advance salt reform";
    unsigned char seed_ref[] = {
0x26,0xe9,0x75,0xec,0x64,0x44,0x23,0xf4,0xa4,0xc4,0xf4,0x21,0x5e,0xf0,0x9b,0x4b,0xd7,0xef,0x92,0x4e,0x85,0xd1,0xd1,0x7c,0x4c,0xf3,0xf1,0x36,0xc2,0x86,0x3c,0xf6,0xdf,0x0a,0x47,0x50,0x45,0x65,0x2c,0x57,0xeb,0x5f,0xb4,0x15,0x13,0xca,0x2a,0x2d,0x67,0x72,0x2b,0x77,0xe9,0x54,0xb4,0xb3,0xfc,0x11,0xf7,0x59,0x04,0x49,0x19,0x1d
    };

    int err=0;
    unsigned char *mnemonic;
    err = entropy_to_mnemonic(
        NULL,
        entropy, entropy_l,
        &mnemonic
    );

    ck_assert_msg(
        err >= 0,
        "entropy_to_mnemonic nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        mnemonic != NULL,
        "Output mnemonic is NULL."
    );

    size_t mnemonic_l = strlen((char *) mnemonic);
    ck_assert_msg(
        mnemonic_l == VECTOR_20_M_LEN,
        "Output mnemonic size didn't match = %llu.",
        mnemonic_l
    );

    ck_assert_msg(
        memcmp(mnemonic, mnemonic_ref, VECTOR_20_M_LEN) == 0,
        "Output didn't match."
    );

    unsigned char* seed;
    err = mnemonic_to_seed(
        mnemonic, mnemonic_l,
        (unsigned char*) VECTOR_PASSPHRASE, VECTOR_PASSPHRASE_L,
        &seed
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_seed nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        seed != NULL,
        "Output seed is NULL."
    );

    ck_assert_msg(
        memcmp(seed, seed_ref, VECTOR_20_S_LEN) == 0,
        "Output seed didn't match."
    );

    unsigned char* s_entropy;
    size_t s_entropy_l;
    err = mnemonic_to_entropy(
        NULL,
        mnemonic_ref, VECTOR_20_M_LEN,
        &s_entropy, &s_entropy_l
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_entropy nonzero error code = %llu.",
        err
    );

    ck_assert_msg(
        s_entropy != NULL,
        "Output entropy is NULL."
    );

    ck_assert_msg(
        s_entropy_l == VECTOR_20_E_LEN,
        "Output entropy size didn't match = %d.",
        s_entropy_l
    );

    ck_assert_msg(
        memcmp(s_entropy, entropy, VECTOR_20_E_LEN) == 0,
        "Output entropy didn't match."
    );

    free(mnemonic);
    free(seed);
    free(s_entropy);
}
END_TEST

START_TEST (vector_21_en)
{
#define VECTOR_21_M_LEN 78
#define VECTOR_21_E_LEN 16
#define VECTOR_21_S_LEN 64
    unsigned char entropy[] = {
0xf3,0x0f,0x8c,0x1d,0xa6,0x65,0x47,0x8f,0x49,0xb0,0x01,0xd9,0x4c,0x5f,0xc4,0x52
    };
    size_t entropy_l = VECTOR_21_E_LEN;
    unsigned char mnemonic_ref[] = "vessel ladder alter error federal sibling chat ability sun glass valve picture";
    unsigned char seed_ref[] = {
0x2a,0xaa,0x92,0x42,0xda,0xaf,0xce,0xe6,0xaa,0x9d,0x72,0x69,0xf1,0x7d,0x4e,0xfe,0x27,0x1e,0x1b,0x9a,0x52,0x91,0x78,0xd7,0xdc,0x13,0x9c,0xd1,0x87,0x47,0x09,0x0b,0xf9,0xd6,0x02,0x95,0xd0,0xce,0x74,0x30,0x9a,0x78,0x85,0x2a,0x9c,0xaa,0xdf,0x0a,0xf4,0x8a,0xae,0x1c,0x62,0x53,0x83,0x96,0x24,0x07,0x62,0x24,0x37,0x4b,0xc6,0x3f
    };

    int err=0;
    unsigned char *mnemonic;
    err = entropy_to_mnemonic(
        NULL,
        entropy, entropy_l,
        &mnemonic
    );

    ck_assert_msg(
        err >= 0,
        "entropy_to_mnemonic nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        mnemonic != NULL,
        "Output mnemonic is NULL."
    );

    size_t mnemonic_l = strlen((char *) mnemonic);
    ck_assert_msg(
        mnemonic_l == VECTOR_21_M_LEN,
        "Output mnemonic size didn't match = %llu.",
        mnemonic_l
    );

    ck_assert_msg(
        memcmp(mnemonic, mnemonic_ref, VECTOR_21_M_LEN) == 0,
        "Output didn't match."
    );

    unsigned char* seed;
    err = mnemonic_to_seed(
        mnemonic, mnemonic_l,
        (unsigned char*) VECTOR_PASSPHRASE, VECTOR_PASSPHRASE_L,
        &seed
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_seed nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        seed != NULL,
        "Output seed is NULL."
    );

    ck_assert_msg(
        memcmp(seed, seed_ref, VECTOR_21_S_LEN) == 0,
        "Output seed didn't match."
    );

    unsigned char* s_entropy;
    size_t s_entropy_l;
    err = mnemonic_to_entropy(
        NULL,
        mnemonic_ref, VECTOR_21_M_LEN,
        &s_entropy, &s_entropy_l
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_entropy nonzero error code = %llu.",
        err
    );

    ck_assert_msg(
        s_entropy != NULL,
        "Output entropy is NULL."
    );

    ck_assert_msg(
        s_entropy_l == VECTOR_21_E_LEN,
        "Output entropy size didn't match = %d.",
        s_entropy_l
    );

    ck_assert_msg(
        memcmp(s_entropy, entropy, VECTOR_21_E_LEN) == 0,
        "Output entropy didn't match."
    );

    free(mnemonic);
    free(seed);
    free(s_entropy);
}
END_TEST

START_TEST (vector_22_en)
{
#define VECTOR_22_M_LEN 120
#define VECTOR_22_E_LEN 24
#define VECTOR_22_S_LEN 64
    unsigned char entropy[] = {
0xc1,0x0e,0xc2,0x0d,0xc3,0xcd,0x9f,0x65,0x2c,0x7f,0xac,0x2f,0x12,0x30,0xf7,0xa3,0xc8,0x28,0x38,0x9a,0x14,0x39,0x2f,0x05
    };
    size_t entropy_l = VECTOR_22_E_LEN;
    unsigned char mnemonic_ref[] = "scissors invite lock maple supreme raw rapid void congress muscle digital elegant little brisk hair mango congress clump";
    unsigned char seed_ref[] = {
0x7b,0x4a,0x10,0xbe,0x9d,0x98,0xe6,0xcb,0xa2,0x65,0x56,0x6d,0xb7,0xf1,0x36,0x71,0x8e,0x13,0x98,0xc7,0x1c,0xb5,0x81,0xe1,0xb2,0xf4,0x64,0xca,0xc1,0xce,0xed,0xf4,0xf3,0xe2,0x74,0xdc,0x27,0x00,0x03,0xc6,0x70,0xad,0x8d,0x02,0xc4,0x55,0x8b,0x2f,0x8e,0x39,0xed,0xea,0x27,0x75,0xc9,0xe2,0x32,0xc7,0xcb,0x79,0x8b,0x06,0x9e,0x88
    };

    int err=0;
    unsigned char *mnemonic;
    err = entropy_to_mnemonic(
        NULL,
        entropy, entropy_l,
        &mnemonic
    );

    ck_assert_msg(
        err >= 0,
        "entropy_to_mnemonic nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        mnemonic != NULL,
        "Output mnemonic is NULL."
    );

    size_t mnemonic_l = strlen((char *) mnemonic);
    ck_assert_msg(
        mnemonic_l == VECTOR_22_M_LEN,
        "Output mnemonic size didn't match = %llu.",
        mnemonic_l
    );

    ck_assert_msg(
        memcmp(mnemonic, mnemonic_ref, VECTOR_22_M_LEN) == 0,
        "Output didn't match."
    );

    unsigned char* seed;
    err = mnemonic_to_seed(
        mnemonic, mnemonic_l,
        (unsigned char*) VECTOR_PASSPHRASE, VECTOR_PASSPHRASE_L,
        &seed
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_seed nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        seed != NULL,
        "Output seed is NULL."
    );

    ck_assert_msg(
        memcmp(seed, seed_ref, VECTOR_22_S_LEN) == 0,
        "Output seed didn't match."
    );

    unsigned char* s_entropy;
    size_t s_entropy_l;
    err = mnemonic_to_entropy(
        NULL,
        mnemonic_ref, VECTOR_22_M_LEN,
        &s_entropy, &s_entropy_l
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_entropy nonzero error code = %llu.",
        err
    );

    ck_assert_msg(
        s_entropy != NULL,
        "Output entropy is NULL."
    );

    ck_assert_msg(
        s_entropy_l == VECTOR_22_E_LEN,
        "Output entropy size didn't match = %d.",
        s_entropy_l
    );

    ck_assert_msg(
        memcmp(s_entropy, entropy, VECTOR_22_E_LEN) == 0,
        "Output entropy didn't match."
    );

    free(mnemonic);
    free(seed);
    free(s_entropy);
}
END_TEST

START_TEST (vector_23_en)
{
#define VECTOR_23_M_LEN 152
#define VECTOR_23_E_LEN 32
#define VECTOR_23_S_LEN 64
    unsigned char entropy[] = {
0xf5,0x85,0xc1,0x1a,0xec,0x52,0x0d,0xb5,0x7d,0xd3,0x53,0xc6,0x95,0x54,0xb2,0x1a,0x89,0xb2,0x0f,0xb0,0x65,0x09,0x66,0xfa,0x0a,0x9d,0x6f,0x74,0xfd,0x98,0x9d,0x8f
    };
    size_t entropy_l = VECTOR_23_E_LEN;
    unsigned char mnemonic_ref[] = "void come effort suffer camp survey warrior heavy shoot primary clutch crush open amazing screen patrol group space point ten exist slush involve unfold";
    unsigned char seed_ref[] = {
0x01,0xf5,0xbc,0xed,0x59,0xde,0xc4,0x8e,0x36,0x2f,0x2c,0x45,0xb5,0xde,0x68,0xb9,0xfd,0x6c,0x92,0xc6,0x63,0x4f,0x44,0xd6,0xd4,0x0a,0xab,0x69,0x05,0x65,0x06,0xf0,0xe3,0x55,0x24,0xa5,0x18,0x03,0x4d,0xdc,0x11,0x92,0xe1,0xda,0xcd,0x32,0xc1,0xed,0x3e,0xaa,0x3c,0x3b,0x13,0x1c,0x88,0xed,0x8e,0x7e,0x54,0xc4,0x9a,0x5d,0x09,0x98
    };

    int err=0;
    unsigned char *mnemonic;
    err = entropy_to_mnemonic(
        NULL,
        entropy, entropy_l,
        &mnemonic
    );

    ck_assert_msg(
        err >= 0,
        "entropy_to_mnemonic nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        mnemonic != NULL,
        "Output mnemonic is NULL."
    );

    size_t mnemonic_l = strlen((char *) mnemonic);
    ck_assert_msg(
        mnemonic_l == VECTOR_23_M_LEN,
        "Output mnemonic size didn't match = %llu.",
        mnemonic_l
    );

    ck_assert_msg(
        memcmp(mnemonic, mnemonic_ref, VECTOR_23_M_LEN) == 0,
        "Output didn't match."
    );

    unsigned char* seed;
    err = mnemonic_to_seed(
        mnemonic, mnemonic_l,
        (unsigned char*) VECTOR_PASSPHRASE, VECTOR_PASSPHRASE_L,
        &seed
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_seed nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        seed != NULL,
        "Output seed is NULL."
    );

    ck_assert_msg(
        memcmp(seed, seed_ref, VECTOR_23_S_LEN) == 0,
        "Output seed didn't match."
    );

    unsigned char* s_entropy;
    size_t s_entropy_l;
    err = mnemonic_to_entropy(
        NULL,
        mnemonic_ref, VECTOR_23_M_LEN,
        &s_entropy, &s_entropy_l
    );

    ck_assert_msg(
        err == EC_OK,
        "mnemonic_to_entropy nonzero error code = %llu.",
        err
    );

    ck_assert_msg(
        s_entropy != NULL,
        "Output entropy is NULL."
    );

    ck_assert_msg(
        s_entropy_l == VECTOR_23_E_LEN,
        "Output entropy size didn't match = %d.",
        s_entropy_l
    );

    ck_assert_msg(
        memcmp(s_entropy, entropy, VECTOR_23_E_LEN) == 0,
        "Output entropy didn't match."
    );

    free(mnemonic);
    free(seed);
    free(s_entropy);
}
END_TEST

/*
=====================
===== to mnemonic
=====================
*/

START_TEST ( to_mnemonic_NULL_entropy )
{
    unsigned char *mnemonic;
    int err;
    err = entropy_to_mnemonic(
        NULL,
        NULL, // entropy
        10,
        &mnemonic
    );
    ck_assert_msg(
        err == EC_NULL_POINTER,
        "Null entropy param did not raise proper error."
    );
}
END_TEST

START_TEST ( to_mnemonic_NULL_mnemonic )
{
#define VECTOR_NULL_TEST_E_LEN 32
    unsigned char entropy[] = {
0xf5,0x85,0xc1,0x1a,0xec,0x52,0x0d,0xb5,0x7d,0xd3,0x53,0xc6,0x95,0x54,0xb2,0x1a,0x89,0xb2,0x0f,0xb0,0x65,0x09,0x66,0xfa,0x0a,0x9d,0x6f,0x74,0xfd,0x98,0x9d,0x8f
    };
    size_t entropy_l = VECTOR_NULL_TEST_E_LEN;
    int err;
    err = entropy_to_mnemonic(
        NULL,
        entropy, // entropy
        entropy_l,
        NULL
    );
    ck_assert_msg(
        err == EC_NULL_POINTER,
        "Null mnemonic pointer did not raise proper error."
    );
}
END_TEST

START_TEST ( to_mnemonic_entropy_too_big_multiple )
{
#define VECTOR_TOO_BIG_MULTIPLE_E_LEN 64
    unsigned char entropy[] = {
0xf5,0x85,0xc1,0x1a,0xec,0x52,0x0d,0xb5,0x7d,0xd3,0x53,0xc6,0x95,0x54,0xb2,0x1a,0x89,0xb2,0x0f,0xb0,0x65,0x09,0x66,0xfa,0x0a,0x9d,0x6f,0x74,0xfd,0x98,0x9d,0x8f,0xf5,0x85,0xc1,0x1a,0xec,0x52,0x0d,0xb5,0x7d,0xd3,0x53,0xc6,0x95,0x54,0xb2,0x1a,0x89,0xb2,0x0f,0xb0,0x65,0x09,0x66,0xfa,0x0a,0x9d,0x6f,0x74,0xfd,0x98,0x9d,0x8f
    };
    size_t entropy_l = VECTOR_TOO_BIG_MULTIPLE_E_LEN;
    int err;
    unsigned char *mnemonic;
    err = entropy_to_mnemonic(
        NULL,
        entropy, // entropy
        entropy_l,
        &mnemonic
    );
    ck_assert_msg(
        err == EC_ENTROPY_LENGTH_NOT_WITHIN_16_32,
        "Too large entropy buffer did not raise proper error."
    );
}
END_TEST

START_TEST ( to_mnemonic_entropy_too_small_multiple )
{
#define VECTOR_TOO_SMALL_MULTIPLE_E_LEN 8
    unsigned char entropy[] = {
0xf5,0x85,0xc1,0x1a,0xec,0x52,0x0d,0xb5
    };
    size_t entropy_l = VECTOR_TOO_SMALL_MULTIPLE_E_LEN;
    int err;
    unsigned char *mnemonic;
    err = entropy_to_mnemonic(
        NULL,
        entropy, // entropy
        entropy_l,
        &mnemonic
    );
    ck_assert_msg(
        err == EC_ENTROPY_LENGTH_NOT_WITHIN_16_32,
        "Entropy buffer too small did not raise proper error."
    );
}
END_TEST

START_TEST ( to_mnemonic_entropy_not_multiple )
{
#define VECTOR_NOT_MULTIPLE_E_LEN 31
    unsigned char entropy[] = {
0xf5,0x85,0xc1,0x1a,0xec,0x52,0x0d,0xb5,0x7d,0xd3,0x53,0xc6,0x95,0x54,0xb2,0x1a,0x89,0xb2,0x0f,0xb0,0x65,0x09,0x66,0xfa,0x0a,0x9d,0x6f,0x74,0xfd,0x98,0x9d
    };
    size_t entropy_l = VECTOR_NOT_MULTIPLE_E_LEN;
    int err;
    unsigned char *mnemonic;
    err = entropy_to_mnemonic(
        NULL,
        entropy, // entropy
        entropy_l,
        &mnemonic
    );
    ck_assert_msg(
        err == EC_ENTROPY_LENGTH_NOT_MULTIPLE_OF_4,
        "Entropy buffer not multiple of 4 did not raise proper error."
    );
}
END_TEST

START_TEST ( to_mnemonic_entropy_larger_buffer )
{
#define VECTOR_LARGE_BUFFER_M_LEN 152
#define VECTOR_LARGE_BUFFER_E_LEN 32
    unsigned char entropy[] = {
0xf5,0x85,0xc1,0x1a,0xec,0x52,0x0d,0xb5,0x7d,0xd3,0x53,0xc6,0x95,0x54,0xb2,0x1a,0x89,0xb2,0x0f,0xb0,0x65,0x09,0x66,0xfa,0x0a,0x9d,0x6f,0x74,0xfd,0x98,0x9d,0x8f,0xf5,0x85,0xc1,0x1a,0xec,0x52,0x0d,0xb5,0x7d,0xd3,0x53,0xc6,0x95,0x54,0xb2,0x1a,0x89,0xb2,0x0f,0xb0,0x65,0x09,0x66,0xfa,0x0a,0x9d,0x6f,0x74,0xfd,0x98,0x9d,0x8f
    };
    size_t entropy_l = VECTOR_LARGE_BUFFER_E_LEN;
    unsigned char mnemonic_ref[] = "void come effort suffer camp survey warrior heavy shoot primary clutch crush open amazing screen patrol group space point ten exist slush involve unfold";

    int err=0;
    unsigned char *mnemonic;
    err = entropy_to_mnemonic(
        NULL,
        entropy, entropy_l,
        &mnemonic
    );

    ck_assert_msg(
        err >= 0,
        "entropy_to_mnemonic nonzero error code = %d.",
        err
    );

    ck_assert_msg(
        mnemonic != NULL,
        "Output mnemonic is NULL."
    );

    size_t mnemonic_l = strlen((char *) mnemonic);
    ck_assert_msg(
        mnemonic_l == VECTOR_LARGE_BUFFER_M_LEN,
        "Output mnemonic size didn't match = %llu.",
        mnemonic_l
    );

    ck_assert_msg(
        memcmp(mnemonic, mnemonic_ref, VECTOR_LARGE_BUFFER_M_LEN) == 0,
        "Output didn't match."
    );
    free(mnemonic);
}
END_TEST

/*
====================
==== to seed
====================
*/

START_TEST ( to_seed_NULL_mnemonic )
{
    int err=0;
    unsigned char* seed;
    err = mnemonic_to_seed(
        NULL, 23,
        (unsigned char*) VECTOR_PASSPHRASE, VECTOR_PASSPHRASE_L,
        &seed
    );

    ck_assert_msg(
        err == EC_NULL_POINTER,
        "NULL mnemonic pointer did not raise proper error"
    );
}
END_TEST

START_TEST ( to_seed_NULL_pass )
{
    unsigned char mnemonic_ref[] = "void come effort suffer camp survey warrior heavy shoot primary clutch crush open amazing screen patrol group space point ten exist slush involve unfold";

    int err=0;
    unsigned char* seed;
    err = mnemonic_to_seed(
        mnemonic_ref, strlen( (char *) mnemonic_ref),
        NULL, VECTOR_PASSPHRASE_L,
        &seed
    );

    ck_assert_msg(
        err == EC_OK,
        "NULL pass pointer did not generate seed succesfully."
    );

    free(seed);
}
END_TEST

START_TEST ( to_seed_zero_pass )
{
    unsigned char mnemonic_ref[] = "void come effort suffer camp survey warrior heavy shoot primary clutch crush open amazing screen patrol group space point ten exist slush involve unfold";

    int err=0;
    unsigned char* seed;
    err = mnemonic_to_seed(
        mnemonic_ref, strlen( (char *) mnemonic_ref),
        (unsigned char*) VECTOR_PASSPHRASE, 0,
        &seed
    );

    ck_assert_msg(
        err == EC_OK,
        "0 length pass did not generate seed succesfully."
    );

    free(seed);
}
END_TEST

START_TEST ( to_seed_NULL_seed )
{
    unsigned char mnemonic_ref[] = "void come effort suffer camp survey warrior heavy shoot primary clutch crush open amazing screen patrol group space point ten exist slush involve unfold";

    int err=0;
    err = mnemonic_to_seed(
        mnemonic_ref, strlen( (char *) mnemonic_ref),
        (unsigned char*) VECTOR_PASSPHRASE, VECTOR_PASSPHRASE_L,
        NULL
    );

    ck_assert_msg(
        err == EC_NULL_POINTER,
        "NULL seed pointer did not raise proper error"
    );
}
END_TEST

START_TEST ( to_seed_smaller_mnemonic )
{
    unsigned char mnemonic_ref[] = "void come effort suffer camp survey warrior heavy shoot primary clutch";

    int err=0;
    unsigned char* seed;
    err = mnemonic_to_seed(
        mnemonic_ref, strlen( (char *) mnemonic_ref),
        (unsigned char*) VECTOR_PASSPHRASE, VECTOR_PASSPHRASE_L,
        &seed
    );

    ck_assert_msg(
        err != EC_OK,
        "Mnemonic too short didn't raise error"
    );
}
END_TEST

START_TEST ( to_seed_longer_mnemonic )
{
    unsigned char mnemonic_ref[] = "void come effort suffer camp survey warrior heavy shoot primary clutch crush open amazing screen patrol group space point ten exist slush involve unfold unfold";

    int err=0;
    unsigned char* seed;
    err = mnemonic_to_seed(
        mnemonic_ref, strlen( (char *) mnemonic_ref),
        (unsigned char*) VECTOR_PASSPHRASE, VECTOR_PASSPHRASE_L,
        &seed
    );

    ck_assert_msg(
        err != EC_OK,
        "Mnemonic too long didn't raise error"
    );
}
END_TEST

/*
====================
==== to entropy
====================
*/

START_TEST ( to_entropy_NULL_mnemonic )
{
    int err=0;
    unsigned char* s_entropy;
    size_t s_entropy_l;
    err = mnemonic_to_entropy(
        NULL,
        NULL, 10,
        &s_entropy, &s_entropy_l
    );

    ck_assert_msg(
        err == EC_NULL_POINTER,
        "Null mnemonic didnt raise approriate error."
    );
}
END_TEST

START_TEST ( to_entropy_NULL_entropy )
{
    unsigned char mnemonic_ref[] = "void come effort suffer camp survey warrior heavy shoot primary clutch crush open amazing screen patrol group space point ten exist slush involve unfold";

    int err=0;
    size_t s_entropy_l;
    err = mnemonic_to_entropy(
        NULL,
        mnemonic_ref, strlen( (char *) mnemonic_ref),
        NULL, &s_entropy_l
    );

    ck_assert_msg(
        err == EC_NULL_POINTER,
        "Null mnemonic didnt raise approriate error."
    );
}
END_TEST

START_TEST ( to_entropy_NULL_entropy_l )
{
    unsigned char mnemonic_ref[] = "void come effort suffer camp survey warrior heavy shoot primary clutch crush open amazing screen patrol group space point ten exist slush involve unfold";

    int err=0;
    unsigned char* s_entropy;
    err = mnemonic_to_entropy(
        NULL,
        mnemonic_ref, strlen( (char *) mnemonic_ref),
        &s_entropy, NULL
    );

    ck_assert_msg(
        err == EC_NULL_POINTER,
        "Null mnemonic didnt raise approriate error."
    );
}
END_TEST


START_TEST ( to_entropy_longer_mnemonic )
{
    unsigned char mnemonic_ref[] = "void come effort suffer camp survey warrior heavy shoot primary clutch crush open amazing screen patrol group space point ten exist slush involve unfold unfold";

    int err=0;
    unsigned char* s_entropy;
    size_t s_entropy_l;
    err = mnemonic_to_entropy(
        NULL,
        mnemonic_ref, strlen( (char *) mnemonic_ref),
        &s_entropy, &s_entropy_l
    );

    ck_assert_msg(
        err != EC_OK,
        "Error code is zero for longer mnemonic."
    );
}
END_TEST

START_TEST ( to_entropy_shorter_mnemonic )
{
    unsigned char mnemonic_ref[] = "void come effort suffer camp survey warrior heavy shoot primary";

    int err=0;
    unsigned char* s_entropy;
    size_t s_entropy_l;
    err = mnemonic_to_entropy(
        NULL,
        mnemonic_ref, strlen( (char *) mnemonic_ref),
        &s_entropy, &s_entropy_l
    );

    ck_assert_msg(
        err != EC_OK,
        "Error code is zero for shorter mnemonic."
    );
}
END_TEST

/*
========================
===== dict from file
========================
*/

START_TEST ( dictionary_NULL_path )
{
    int err;
    struct dictionary dict;
    err = parse_dict_from_file(
        NULL,
        &dict
    );
    ck_assert_msg(
        err == EC_NULL_POINTER,
        "msg"
    );
}
END_TEST

START_TEST ( dictionary_NULL_dict )
{
    int err;
    struct dictionary dict;
    err = parse_dict_from_file(
        "../resources/tests/english.txt",
        &dict
    );
    ck_assert_msg(
        err == EC_NULL_POINTER,
        "msg"
    );
}
END_TEST

START_TEST ( dictionary_file_doesntexist )
{
    int err;
    struct dictionary dict;
    err = parse_dict_from_file(
        "../resources/tests/doesnotexist.txt",
        &dict
    );
    ck_assert_msg(
        err == EC_ERROR_OPENING_FILE,
        "msg"
    );
}
END_TEST

START_TEST ( dictionary_file_shorter )
{
    int err;
    struct dictionary dict;
    err = parse_dict_from_file(
        "../resources/tests/english_few_words.txt",
        &dict
    );
    ck_assert_msg(
        err == EC_NOT_ENOUGH_WORDS,
        "msg"
    );
}
END_TEST

START_TEST ( dictionary_file_longer )
{
    int err;
    struct dictionary dict;
    err = parse_dict_from_file(
        "../resources/tests/english_too_many_words.txt",
        &dict
    );
    ck_assert_msg(
        err == EC_FILE_TOO_LONG,
        "Incorrect error code"
    );
}
END_TEST

START_TEST ( dictionary_word_too_long )
{
    int err;
    struct dictionary dict;
    err = parse_dict_from_file(
        "../resources/tests/english_word_too_long.txt",
        &dict
    );
    ck_assert_msg(
        err == EC_WORD_TOO_LONG,
        "Incorrect error code"
    );
}
END_TEST

START_TEST ( dictionary_english_dict )
{
    const char* ref[] = {
    "abandon","ability","able","about","above","absent","absorb","abstract","absurd","abuse","access","accident","account","accuse","achieve","acid",
    "acoustic","acquire","across","act","action","actor","actress","actual","adapt","add","addict","address","adjust","admit","adult","advance",
    "advice","aerobic","affair","afford","afraid","again","age","agent","agree","ahead","aim","air","airport","aisle","alarm","album",
    "alcohol","alert","alien","all","alley","allow","almost","alone","alpha","already","also","alter","always","amateur","amazing","among",
    "amount","amused","analyst","anchor","ancient","anger","angle","angry","animal","ankle","announce","annual","another","answer","antenna","antique",
    "anxiety","any","apart","apology","appear","apple","approve","april","arch","arctic","area","arena","argue","arm","armed","armor",
    "army","around","arrange","arrest","arrive","arrow","art","artefact","artist","artwork","ask","aspect","assault","asset","assist","assume",
    "asthma","athlete","atom","attack","attend","attitude","attract","auction","audit","august","aunt","author","auto","autumn","average","avocado",
    "avoid","awake","aware","away","awesome","awful","awkward","axis","baby","bachelor","bacon","badge","bag","balance","balcony","ball",
    "bamboo","banana","banner","bar","barely","bargain","barrel","base","basic","basket","battle","beach","bean","beauty","because","become",
    "beef","before","begin","behave","behind","believe","below","belt","bench","benefit","best","betray","better","between","beyond","bicycle",
    "bid","bike","bind","biology","bird","birth","bitter","black","blade","blame","blanket","blast","bleak","bless","blind","blood",
    "blossom","blouse","blue","blur","blush","board","boat","body","boil","bomb","bone","bonus","book","boost","border","boring",
    "borrow","boss","bottom","bounce","box","boy","bracket","brain","brand","brass","brave","bread","breeze","brick","bridge","brief",
    "bright","bring","brisk","broccoli","broken","bronze","broom","brother","brown","brush","bubble","buddy","budget","buffalo","build","bulb",
    "bulk","bullet","bundle","bunker","burden","burger","burst","bus","business","busy","butter","buyer","buzz","cabbage","cabin","cable",
    "cactus","cage","cake","call","calm","camera","camp","can","canal","cancel","candy","cannon","canoe","canvas","canyon","capable",
    "capital","captain","car","carbon","card","cargo","carpet","carry","cart","case","cash","casino","castle","casual","cat","catalog",
    "catch","category","cattle","caught","cause","caution","cave","ceiling","celery","cement","census","century","cereal","certain","chair","chalk",
    "champion","change","chaos","chapter","charge","chase","chat","cheap","check","cheese","chef","cherry","chest","chicken","chief","child",
    "chimney","choice","choose","chronic","chuckle","chunk","churn","cigar","cinnamon","circle","citizen","city","civil","claim","clap","clarify",
    "claw","clay","clean","clerk","clever","click","client","cliff","climb","clinic","clip","clock","clog","close","cloth","cloud",
    "clown","club","clump","cluster","clutch","coach","coast","coconut","code","coffee","coil","coin","collect","color","column","combine",
    "come","comfort","comic","common","company","concert","conduct","confirm","congress","connect","consider","control","convince","cook","cool","copper",
    "copy","coral","core","corn","correct","cost","cotton","couch","country","couple","course","cousin","cover","coyote","crack","cradle",
    "craft","cram","crane","crash","crater","crawl","crazy","cream","credit","creek","crew","cricket","crime","crisp","critic","crop",
    "cross","crouch","crowd","crucial","cruel","cruise","crumble","crunch","crush","cry","crystal","cube","culture","cup","cupboard","curious",
    "current","curtain","curve","cushion","custom","cute","cycle","dad","damage","damp","dance","danger","daring","dash","daughter","dawn",
    "day","deal","debate","debris","decade","december","decide","decline","decorate","decrease","deer","defense","define","defy","degree","delay",
    "deliver","demand","demise","denial","dentist","deny","depart","depend","deposit","depth","deputy","derive","describe","desert","design","desk",
    "despair","destroy","detail","detect","develop","device","devote","diagram","dial","diamond","diary","dice","diesel","diet","differ","digital",
    "dignity","dilemma","dinner","dinosaur","direct","dirt","disagree","discover","disease","dish","dismiss","disorder","display","distance","divert","divide",
    "divorce","dizzy","doctor","document","dog","doll","dolphin","domain","donate","donkey","donor","door","dose","double","dove","draft",
    "dragon","drama","drastic","draw","dream","dress","drift","drill","drink","drip","drive","drop","drum","dry","duck","dumb",
    "dune","during","dust","dutch","duty","dwarf","dynamic","eager","eagle","early","earn","earth","easily","east","easy","echo",
    "ecology","economy","edge","edit","educate","effort","egg","eight","either","elbow","elder","electric","elegant","element","elephant","elevator",
    "elite","else","embark","embody","embrace","emerge","emotion","employ","empower","empty","enable","enact","end","endless","endorse","enemy",
    "energy","enforce","engage","engine","enhance","enjoy","enlist","enough","enrich","enroll","ensure","enter","entire","entry","envelope","episode",
    "equal","equip","era","erase","erode","erosion","error","erupt","escape","essay","essence","estate","eternal","ethics","evidence","evil",
    "evoke","evolve","exact","example","excess","exchange","excite","exclude","excuse","execute","exercise","exhaust","exhibit","exile","exist","exit",
    "exotic","expand","expect","expire","explain","expose","express","extend","extra","eye","eyebrow","fabric","face","faculty","fade","faint",
    "faith","fall","false","fame","family","famous","fan","fancy","fantasy","farm","fashion","fat","fatal","father","fatigue","fault",
    "favorite","feature","february","federal","fee","feed","feel","female","fence","festival","fetch","fever","few","fiber","fiction","field",
    "figure","file","film","filter","final","find","fine","finger","finish","fire","firm","first","fiscal","fish","fit","fitness",
    "fix","flag","flame","flash","flat","flavor","flee","flight","flip","float","flock","floor","flower","fluid","flush","fly",
    "foam","focus","fog","foil","fold","follow","food","foot","force","forest","forget","fork","fortune","forum","forward","fossil",
    "foster","found","fox","fragile","frame","frequent","fresh","friend","fringe","frog","front","frost","frown","frozen","fruit","fuel",
    "fun","funny","furnace","fury","future","gadget","gain","galaxy","gallery","game","gap","garage","garbage","garden","garlic","garment",
    "gas","gasp","gate","gather","gauge","gaze","general","genius","genre","gentle","genuine","gesture","ghost","giant","gift","giggle",
    "ginger","giraffe","girl","give","glad","glance","glare","glass","glide","glimpse","globe","gloom","glory","glove","glow","glue",
    "goat","goddess","gold","good","goose","gorilla","gospel","gossip","govern","gown","grab","grace","grain","grant","grape","grass",
    "gravity","great","green","grid","grief","grit","grocery","group","grow","grunt","guard","guess","guide","guilt","guitar","gun",
    "gym","habit","hair","half","hammer","hamster","hand","happy","harbor","hard","harsh","harvest","hat","have","hawk","hazard",
    "head","health","heart","heavy","hedgehog","height","hello","helmet","help","hen","hero","hidden","high","hill","hint","hip",
    "hire","history","hobby","hockey","hold","hole","holiday","hollow","home","honey","hood","hope","horn","horror","horse","hospital",
    "host","hotel","hour","hover","hub","huge","human","humble","humor","hundred","hungry","hunt","hurdle","hurry","hurt","husband",
    "hybrid","ice","icon","idea","identify","idle","ignore","ill","illegal","illness","image","imitate","immense","immune","impact","impose",
    "improve","impulse","inch","include","income","increase","index","indicate","indoor","industry","infant","inflict","inform","inhale","inherit","initial",
    "inject","injury","inmate","inner","innocent","input","inquiry","insane","insect","inside","inspire","install","intact","interest","into","invest",
    "invite","involve","iron","island","isolate","issue","item","ivory","jacket","jaguar","jar","jazz","jealous","jeans","jelly","jewel",
    "job","join","joke","journey","joy","judge","juice","jump","jungle","junior","junk","just","kangaroo","keen","keep","ketchup",
    "key","kick","kid","kidney","kind","kingdom","kiss","kit","kitchen","kite","kitten","kiwi","knee","knife","knock","know",
    "lab","label","labor","ladder","lady","lake","lamp","language","laptop","large","later","latin","laugh","laundry","lava","law",
    "lawn","lawsuit","layer","lazy","leader","leaf","learn","leave","lecture","left","leg","legal","legend","leisure","lemon","lend",
    "length","lens","leopard","lesson","letter","level","liar","liberty","library","license","life","lift","light","like","limb","limit",
    "link","lion","liquid","list","little","live","lizard","load","loan","lobster","local","lock","logic","lonely","long","loop",
    "lottery","loud","lounge","love","loyal","lucky","luggage","lumber","lunar","lunch","luxury","lyrics","machine","mad","magic","magnet",
    "maid","mail","main","major","make","mammal","man","manage","mandate","mango","mansion","manual","maple","marble","march","margin",
    "marine","market","marriage","mask","mass","master","match","material","math","matrix","matter","maximum","maze","meadow","mean","measure",
    "meat","mechanic","medal","media","melody","melt","member","memory","mention","menu","mercy","merge","merit","merry","mesh","message",
    "metal","method","middle","midnight","milk","million","mimic","mind","minimum","minor","minute","miracle","mirror","misery","miss","mistake",
    "mix","mixed","mixture","mobile","model","modify","mom","moment","monitor","monkey","monster","month","moon","moral","more","morning",
    "mosquito","mother","motion","motor","mountain","mouse","move","movie","much","muffin","mule","multiply","muscle","museum","mushroom","music",
    "must","mutual","myself","mystery","myth","naive","name","napkin","narrow","nasty","nation","nature","near","neck","need","negative",
    "neglect","neither","nephew","nerve","nest","net","network","neutral","never","news","next","nice","night","noble","noise","nominee",
    "noodle","normal","north","nose","notable","note","nothing","notice","novel","now","nuclear","number","nurse","nut","oak","obey",
    "object","oblige","obscure","observe","obtain","obvious","occur","ocean","october","odor","off","offer","office","often","oil","okay",
    "old","olive","olympic","omit","once","one","onion","online","only","open","opera","opinion","oppose","option","orange","orbit",
    "orchard","order","ordinary","organ","orient","original","orphan","ostrich","other","outdoor","outer","output","outside","oval","oven","over",
    "own","owner","oxygen","oyster","ozone","pact","paddle","page","pair","palace","palm","panda","panel","panic","panther","paper",
    "parade","parent","park","parrot","party","pass","patch","path","patient","patrol","pattern","pause","pave","payment","peace","peanut",
    "pear","peasant","pelican","pen","penalty","pencil","people","pepper","perfect","permit","person","pet","phone","photo","phrase","physical",
    "piano","picnic","picture","piece","pig","pigeon","pill","pilot","pink","pioneer","pipe","pistol","pitch","pizza","place","planet",
    "plastic","plate","play","please","pledge","pluck","plug","plunge","poem","poet","point","polar","pole","police","pond","pony",
    "pool","popular","portion","position","possible","post","potato","pottery","poverty","powder","power","practice","praise","predict","prefer","prepare",
    "present","pretty","prevent","price","pride","primary","print","priority","prison","private","prize","problem","process","produce","profit","program",
    "project","promote","proof","property","prosper","protect","proud","provide","public","pudding","pull","pulp","pulse","pumpkin","punch","pupil",
    "puppy","purchase","purity","purpose","purse","push","put","puzzle","pyramid","quality","quantum","quarter","question","quick","quit","quiz",
    "quote","rabbit","raccoon","race","rack","radar","radio","rail","rain","raise","rally","ramp","ranch","random","range","rapid",
    "rare","rate","rather","raven","raw","razor","ready","real","reason","rebel","rebuild","recall","receive","recipe","record","recycle",
    "reduce","reflect","reform","refuse","region","regret","regular","reject","relax","release","relief","rely","remain","remember","remind","remove",
    "render","renew","rent","reopen","repair","repeat","replace","report","require","rescue","resemble","resist","resource","response","result","retire",
    "retreat","return","reunion","reveal","review","reward","rhythm","rib","ribbon","rice","rich","ride","ridge","rifle","right","rigid",
    "ring","riot","ripple","risk","ritual","rival","river","road","roast","robot","robust","rocket","romance","roof","rookie","room",
    "rose","rotate","rough","round","route","royal","rubber","rude","rug","rule","run","runway","rural","sad","saddle","sadness",
    "safe","sail","salad","salmon","salon","salt","salute","same","sample","sand","satisfy","satoshi","sauce","sausage","save","say",
    "scale","scan","scare","scatter","scene","scheme","school","science","scissors","scorpion","scout","scrap","screen","script","scrub","sea",
    "search","season","seat","second","secret","section","security","seed","seek","segment","select","sell","seminar","senior","sense","sentence",
    "series","service","session","settle","setup","seven","shadow","shaft","shallow","share","shed","shell","sheriff","shield","shift","shine",
    "ship","shiver","shock","shoe","shoot","shop","short","shoulder","shove","shrimp","shrug","shuffle","shy","sibling","sick","side",
    "siege","sight","sign","silent","silk","silly","silver","similar","simple","since","sing","siren","sister","situate","six","size",
    "skate","sketch","ski","skill","skin","skirt","skull","slab","slam","sleep","slender","slice","slide","slight","slim","slogan",
    "slot","slow","slush","small","smart","smile","smoke","smooth","snack","snake","snap","sniff","snow","soap","soccer","social",
    "sock","soda","soft","solar","soldier","solid","solution","solve","someone","song","soon","sorry","sort","soul","sound","soup",
    "source","south","space","spare","spatial","spawn","speak","special","speed","spell","spend","sphere","spice","spider","spike","spin",
    "spirit","split","spoil","sponsor","spoon","sport","spot","spray","spread","spring","spy","square","squeeze","squirrel","stable","stadium",
    "staff","stage","stairs","stamp","stand","start","state","stay","steak","steel","stem","step","stereo","stick","still","sting",
    "stock","stomach","stone","stool","story","stove","strategy","street","strike","strong","struggle","student","stuff","stumble","style","subject",
    "submit","subway","success","such","sudden","suffer","sugar","suggest","suit","summer","sun","sunny","sunset","super","supply","supreme",
    "sure","surface","surge","surprise","surround","survey","suspect","sustain","swallow","swamp","swap","swarm","swear","sweet","swift","swim",
    "swing","switch","sword","symbol","symptom","syrup","system","table","tackle","tag","tail","talent","talk","tank","tape","target",
    "task","taste","tattoo","taxi","teach","team","tell","ten","tenant","tennis","tent","term","test","text","thank","that",
    "theme","then","theory","there","they","thing","this","thought","three","thrive","throw","thumb","thunder","ticket","tide","tiger",
    "tilt","timber","time","tiny","tip","tired","tissue","title","toast","tobacco","today","toddler","toe","together","toilet","token",
    "tomato","tomorrow","tone","tongue","tonight","tool","tooth","top","topic","topple","torch","tornado","tortoise","toss","total","tourist",
    "toward","tower","town","toy","track","trade","traffic","tragic","train","transfer","trap","trash","travel","tray","treat","tree",
    "trend","trial","tribe","trick","trigger","trim","trip","trophy","trouble","truck","true","truly","trumpet","trust","truth","try",
    "tube","tuition","tumble","tuna","tunnel","turkey","turn","turtle","twelve","twenty","twice","twin","twist","two","type","typical",
    "ugly","umbrella","unable","unaware","uncle","uncover","under","undo","unfair","unfold","unhappy","uniform","unique","unit","universe","unknown",
    "unlock","until","unusual","unveil","update","upgrade","uphold","upon","upper","upset","urban","urge","usage","use","used","useful",
    "useless","usual","utility","vacant","vacuum","vague","valid","valley","valve","van","vanish","vapor","various","vast","vault","vehicle",
    "velvet","vendor","venture","venue","verb","verify","version","very","vessel","veteran","viable","vibrant","vicious","victory","video","view",
    "village","vintage","violin","virtual","virus","visa","visit","visual","vital","vivid","vocal","voice","void","volcano","volume","vote",
    "voyage","wage","wagon","wait","walk","wall","walnut","want","warfare","warm","warrior","wash","wasp","waste","water","wave",
    "way","wealth","weapon","wear","weasel","weather","web","wedding","weekend","weird","welcome","west","wet","whale","what","wheat",
    "wheel","when","where","whip","whisper","wide","width","wife","wild","will","win","window","wine","wing","wink","winner",
    "winter","wire","wisdom","wise","wish","witness","wolf","woman","wonder","wood","wool","word","work","world","worry","worth",
    "wrap","wreck","wrestle","wrist","write","wrong","yard","year","yellow","you","young","youth","zebra","zero","zone","zoo"
    };

    int err;
    struct dictionary dict;
    err = parse_dict_from_file(
        "../resources/tests/english.txt",
        &dict
    );
    ck_assert_msg(
        err == EC_OK,
        "Nonzero error code."
    );
    unsigned int i;
    for (i=0; i<2048; i++)
    {
        ck_assert_msg( 
            strcmp(dict->words[i], ref[i]) == 0,
            "Incorrect word for index %u.",
            i 
        );
    }
    free_dict(dict);
}
END_TEST

/*
START_TEST ( test_name )
{
    ck_assert_msg(
        1 == 0,
        "msg"
    );
}
END_TEST
*/

Suite * mnemonics_test_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Test Vectors");

    /* Core test case */
    tc_core = tcase_create("Core");

    // test vectors
    tcase_add_test(tc_core, vector_0_en);
    tcase_add_test(tc_core, vector_1_en);
    tcase_add_test(tc_core, vector_2_en);
    tcase_add_test(tc_core, vector_3_en);
    tcase_add_test(tc_core, vector_4_en);
    tcase_add_test(tc_core, vector_5_en);
    tcase_add_test(tc_core, vector_6_en);
    tcase_add_test(tc_core, vector_7_en);
    tcase_add_test(tc_core, vector_8_en);
    tcase_add_test(tc_core, vector_9_en);
    tcase_add_test(tc_core, vector_10_en);
    tcase_add_test(tc_core, vector_11_en);
    tcase_add_test(tc_core, vector_12_en);
    tcase_add_test(tc_core, vector_13_en);
    tcase_add_test(tc_core, vector_14_en);
    tcase_add_test(tc_core, vector_15_en);
    tcase_add_test(tc_core, vector_16_en);
    tcase_add_test(tc_core, vector_17_en);
    tcase_add_test(tc_core, vector_18_en);
    tcase_add_test(tc_core, vector_19_en);
    tcase_add_test(tc_core, vector_20_en);
    tcase_add_test(tc_core, vector_21_en);
    tcase_add_test(tc_core, vector_22_en);
    tcase_add_test(tc_core, vector_23_en);
    
    // to mnemonic
    tcase_add_test(tc_core, to_mnemonic_NULL_entropy);
    tcase_add_test(tc_core, to_mnemonic_NULL_mnemonic);
    tcase_add_test(tc_core, to_mnemonic_entropy_too_big_multiple);
    tcase_add_test(tc_core, to_mnemonic_entropy_too_small_multiple);
    tcase_add_test(tc_core, to_mnemonic_entropy_not_multiple);
    tcase_add_test(tc_core, to_mnemonic_entropy_larger_buffer);

    // to seed
    tcase_add_test(tc_core, to_seed_NULL_mnemonic);
    tcase_add_test(tc_core, to_seed_NULL_pass);
    tcase_add_test(tc_core, to_seed_zero_pass);
    tcase_add_test(tc_core, to_seed_NULL_seed);
    tcase_add_test(tc_core, to_seed_smaller_mnemonic);
    tcase_add_test(tc_core, to_seed_longer_mnemonic);

    // to entropy
    tcase_add_test(tc_core, to_entropy_NULL_mnemonic);
    tcase_add_test(tc_core, to_entropy_NULL_entropy);
    tcase_add_test(tc_core, to_entropy_NULL_entropy_l);
    tcase_add_test(tc_core, to_entropy_shorter_mnemonic);
    tcase_add_test(tc_core, to_entropy_longer_mnemonic);

    // dictionary from file
    tcase_add_test(tc_core, dictionary_NULL_path);
    tcase_add_test(tc_core, dictionary_NULL_dict);
    tcase_add_test(tc_core, dictionary_file_doesntexist);
    tcase_add_test(tc_core, dictionary_file_shorter);
    tcase_add_test(tc_core, dictionary_file_longer);
    tcase_add_test(tc_core, dictionary_word_too_long);
    tcase_add_test(tc_core, dictionary_english_dict);

    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = mnemonics_test_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
