
#include "KMS.h"
#include <string>

using namespace std;



class KeyHandler{
  
public:


    int getAESSecret(char* pass, unsigned char* aeskey, unsigned char* aesiv){


        EVP_MD_CTX *mdctx;
        const EVP_MD *md;

        unsigned char key[32];
        unsigned char iv[16];
        unsigned int md_len, i;
        

        md = EVP_get_digestbyname("md5");

        mdctx = EVP_MD_CTX_new();
        EVP_DigestInit_ex(mdctx, md, NULL);
        EVP_DigestUpdate(mdctx, pass, strlen(pass));

        EVP_DigestFinal_ex(mdctx, key, &md_len);
        EVP_MD_CTX_free(mdctx);

        memcpy(iv, key, md_len/2);
        memcpy(aeskey, key, md_len);
        memcpy(aesiv, iv, md_len/2);

   
    return md_len;
    }

    
};