#include <check.h>
#include <string.h>
#include <stdlib.h>

#include "mnemonics.h"

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
        err == 0,
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
        err == 0,
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
        err == 0,
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
        err == 0,
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
        err == 0,
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
        err == 0,
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
        err == 0,
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
        err == 0,
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
        err == 0,
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
        err == 0,
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
        err == 0,
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
        err == 0,
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
        err == 0,
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
        err == 0,
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
        err == 0,
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
        err == 0,
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
        err == 0,
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
        err == 0,
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
        err == 0,
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
        err == 0,
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
        err == 0,
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
        err == 0,
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
        err == 0,
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
        err == 0,
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
        err == 0,
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
        err == 0,
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
        err == 0,
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
        err == 0,
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
        err == 0,
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
        err == 0,
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
        err == 0,
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
        err == 0,
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
        err == 0,
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
        err == 0,
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
        err == 0,
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
        err == 0,
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
        err == 0,
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
        err == 0,
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
        err == 0,
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
        err == 0,
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
        err == 0,
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
        err == 0,
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
        err == 0,
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
        err == 0,
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
        err == 0,
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
        err == 0,
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
        err == 0,
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
        err == 0,
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
}
END_TEST





Suite * mnemonics_test_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Test Vectors");

    /* Core test case */
    tc_core = tcase_create("Core");

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
