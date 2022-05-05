#include "Crypt.h"
#include <string>

using namespace std;


int Crypt::aesEncrypt( unsigned char *msg, size_t msgLen, unsigned char **encMsg,  const unsigned char *key, const unsigned char *iv) {
    // std::cout << "aesEncrypt() in Crypt.cc" <<std::endl;

    EVP_CIPHER_CTX *aesEncryptCtx;
    aesEncryptCtx = EVP_CIPHER_CTX_new();

    size_t blockLen = 0;
    size_t encMsgLen = 0;

    *encMsg = (unsigned char *)malloc(msgLen + AES_BLOCK_SIZE);
    if (encMsg == NULL)
        return FAILURE;

    if (!EVP_EncryptInit_ex(aesEncryptCtx, EVP_aes_256_cbc(), NULL, key, iv)) {
        return FAILURE;
    }

    if (!EVP_EncryptUpdate(aesEncryptCtx, *encMsg, (int *)&blockLen, (unsigned char *)msg, msgLen)) {
        return FAILURE;
    }
    encMsgLen += blockLen;

    if (!EVP_EncryptFinal_ex(aesEncryptCtx, *encMsg + encMsgLen, (int *)&blockLen)) {
        return FAILURE;
    }

    EVP_CIPHER_CTX_cleanup(aesEncryptCtx);

    return (encMsgLen + blockLen);
}

int Crypt::aesDecrypt(unsigned char *encMsg, size_t encMsgLen, char **decMsg, const unsigned char *key, const unsigned char *iv) {
        // std::cout << "aesDecrypt() in Crypt.cc" <<std::endl;

    EVP_CIPHER_CTX *aesDecryptCtx;
    aesDecryptCtx = EVP_CIPHER_CTX_new();

    size_t decLen = 0;
    size_t blockLen = 0;

    *decMsg = (char *)malloc(encMsgLen);
    if (*decMsg == NULL)
        return FAILURE;

    if (!EVP_DecryptInit_ex(aesDecryptCtx, EVP_aes_256_cbc(), NULL, key, iv)) {
        return FAILURE;
    }

    if (!EVP_DecryptUpdate(aesDecryptCtx, (unsigned char *)*decMsg, (int *)&blockLen, encMsg, (int)encMsgLen)) {
        return FAILURE;
    }
    decLen += blockLen; 

    if (!EVP_DecryptFinal_ex(aesDecryptCtx, (unsigned char *)*decMsg + decLen, (int *)&blockLen)) {
        return FAILURE;
    }

    decLen += blockLen;

    (*decMsg)[decLen] = '\0';

    EVP_CIPHER_CTX_cleanup(aesDecryptCtx);

    return (encMsgLen);
}
