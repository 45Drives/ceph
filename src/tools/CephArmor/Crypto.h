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

//#define PSUEDO_CLIENT

#define SUCCESS 0
#define FAILURE -1

int benchEncrypt(const char *infile, unsigned char &ciphertext );

class Crypto {

public:
    Crypto(){
        std::cout<< " Crypto started! " <<std::endl;
    }

    // ~Crypto(){
    //     std::cout<< " Crypto finished! " <<std::endl;

               
    // }

    // int aesEncrypt(const unsigned char *msg, size_t msgLen, unsigned char **encMsg, unsigned char *key, unsigned char *iv);
    int aesEncrypt(unsigned char *msg, size_t msgLen, unsigned char **encMsg, unsigned char *key, unsigned char *iv);

    int aesDecrypt(unsigned char *encMsg, size_t encMsgLen, char **decMsg, unsigned char *key, unsigned char *iv);

   
};

#endif