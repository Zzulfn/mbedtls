#ifndef MBEDTLS_CONFIG_H
#define MBEDTLS_CONFIG_H

/* System support */
#define MBEDTLS_PLATFORM_C
#define MBEDTLS_PLATFORM_MEMORY
#define MBEDTLS_MEMORY_BUFFER_ALLOC_C
#define MBEDTLS_PLATFORM_NO_STD_FUNCTIONS
#define MBEDTLS_PLATFORM_EXIT_ALT
#define MBEDTLS_NO_PLATFORM_ENTROPY
#define MBEDTLS_NO_DEFAULT_ENTROPY_SOURCES
#define MBEDTLS_PLATFORM_PRINTF_ALT
#define MBEDTLS_PLATFORM_SNPRINTF_ALT

/* mbed TLS feature support */
#define MBEDTLS_ECP_DP_SECP256R1_ENABLED
#define MBEDTLS_KEY_EXCHANGE_ECDHE_ECDSA_ENABLED
#define MBEDTLS_SSL_PROTO_TLS1_2

/* mbed TLS modules */
#define MBEDTLS_AES_C
#define MBEDTLS_ASN1_PARSE_C
#define MBEDTLS_ASN1_WRITE_C
#define MBEDTLS_BIGNUM_C
#define MBEDTLS_CIPHER_C
#define MBEDTLS_CTR_DRBG_C
#define MBEDTLS_ECDH_C
#define MBEDTLS_ECDSA_C
#define MBEDTLS_ECP_C
#define MBEDTLS_ENTROPY_C
#define MBEDTLS_GCM_C
#define MBEDTLS_MD_C
#define MBEDTLS_OID_C
#define MBEDTLS_PK_C
#define MBEDTLS_PK_PARSE_C
#define MBEDTLS_SHA256_C
#define MBEDTLS_SHA512_C
#define MBEDTLS_SSL_CLI_C
#define MBEDTLS_SSL_SRV_C
#define MBEDTLS_SSL_TLS_C
#define MBEDTLS_X509_CRT_PARSE_C
#define MBEDTLS_X509_USE_C

/* Save RAM at the expense of ROM */
#define MBEDTLS_AES_ROM_TABLES

/* Save RAM by adjusting to our exact needs */
#define MBEDTLS_ECP_MAX_BITS   256
#define MBEDTLS_MPI_MAX_SIZE    32 // 256 bits is 32 bytes

/* Save RAM at the expense of speed, see ecp.h */
#define MBEDTLS_ECP_WINDOW_SIZE        2
#define MBEDTLS_ECP_FIXED_POINT_OPTIM  0

/* Significant speed benefit at the expense of some ROM */
#define MBEDTLS_ECP_NIST_OPTIM

/*
 * You should adjust this to the exact number of sources you're using: default
 * is the "mbedtls_platform_entropy_poll" source, but you may want to add other ones.
 * Minimum is 2 for the entropy test suite.
 */
#define MBEDTLS_ENTROPY_MAX_SOURCES 2

/* Save ROM and a few bytes of RAM by specifying our own ciphersuite list */
#define MBEDTLS_SSL_CIPHERSUITES MBEDTLS_TLS_ECDHE_ECDSA_WITH_AES_256_GCM_SHA384

/*
 * Save RAM at the expense of interoperability: do this only if you control
 * both ends of the connection!  (See coments in "mbedtls/ssl.h".)
 * The minimum size here depends on the certificate chain used as well as the
 * typical size of records.
 */
#define MBEDTLS_SSL_MAX_CONTENT_LEN             1024

#include "mbedtls/check_config.h"

#endif /* MBEDTLS_CONFIG_H */
