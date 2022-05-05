
#include "KMS.h"
#include <string>
#include <iterator>

using namespace std;



   data_t* KeyHandler::getAESSecret(unsigned char* pass){

        SHA256_CTX context;
        
        SHA256_Init(&context);
        unsigned long len =  strlen((char*)pass);
        unsigned char* key = new unsigned char[len]();
        SHA256_Update(&context, pass, len);
        SHA256_Final(key, &context);
        
        std::cout   << "[INSIDE getAESSecret()]:" << std::endl
                    << "\tlen:" << len << std::endl
                    << "\tkey:" << key << std::endl;

        return (new data_t(32, key)); 
    }

data_t* KeyHandler::getSHA256(unsigned char* input, unsigned char* md)
{
    SHA256_CTX context;
    unsigned char* key = NULL;
    unsigned long length = strlen((char*)input);
    
    SHA256_Init(&context);
    SHA256_Update(&context, input, length);
    SHA256_Final(md, &context);
    return (new data_t(length, key));
}

data_t* KeyHandler::getMD(unsigned char* pass)
{
        const EVP_MD *md;
        EVP_MD_CTX *mdctx;

        unsigned int len = 0;
        unsigned char* key = NULL;

        md = EVP_get_digestbyname("md5");

        mdctx = EVP_MD_CTX_new();
        EVP_DigestInit_ex(mdctx, md, NULL);
        EVP_DigestUpdate(mdctx, pass, strlen((char*)pass));

        EVP_DigestFinal_ex(mdctx, key, &(len));
        EVP_MD_CTX_free(mdctx);

        return (new data_t(len, key));
}