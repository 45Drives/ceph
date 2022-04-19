#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/aes.h>
#include <openssl/err.h>
#include <openssl/rand.h>

#include <stdio.h>
#include <string>
#include <string.h>
#include <fstream>
#include <iostream>


#ifndef CRYPTO_H
#define CRYPTO_H

#define AES_KEYLEN 256


#define SUCCESS 0
#define FAILURE -1

int benchEncrypt(const char *infile, unsigned char &ciphertext );

class Crypt {

public:
    Crypt(){ }

    int aesEncrypt(unsigned char *msg, size_t msgLen, unsigned char **encMsg, unsigned char *key, unsigned char *iv);

    int aesDecrypt(unsigned char *encMsg, size_t encMsgLen, char **decMsg, unsigned char *key, unsigned char *iv);

   
};

#endif