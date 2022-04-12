
#include <iostream>
#include <stdint.h>

#include <errno.h>
#include <map>
#include <memory>
#include <sstream>
#include <algorithm>
#include <stdio.h>
 #include <string.h>

 #include <openssl/evp.h>
#include <openssl/rand.h>
#include <openssl/md5.h>


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

    //  aeskey = key; 
    //  aesiv = iv;
    memcpy(aeskey, key, md_len);
    memcpy(aesiv, iv, md_len/2);

    printf("key: ");
     for (i = 0; i < md_len; i++)
         printf("%02x", key[i]);
     printf("\n");


    printf("local key: ");
        for (i = 0; i < md_len; i++)
            printf("%02x", aeskey[i]);
        printf("\n");



     printf("iv: ");
     for (i = 0; i < md_len/2; i++)
         printf("%02x", iv[i]);
     printf("\n");

     printf("local iv: ");
     for (i = 0; i < md_len/2; i++)
         printf("%02x", aesiv[i]);
     printf("\n");

    return md_len;
    }

    
};

void getMd(char* message){

    EVP_MD_CTX *mdctx;
     const EVP_MD *md;
    //  char mess1[] = "Test Message\n";
    //  char mess2[] = "Hello World\n";
    //  unsigned char md_value[EVP_MAX_MD_SIZE];
    //  unsigned char md_value[32];
     unsigned char key[32];
     unsigned char iv[16];
     unsigned int md_len, i;

    //  if (mdType == NULL) {
    //      printf("Usage: mdtest digestname\n");
    //      exit(1);
    //  }

     md = EVP_get_digestbyname("md5");
    //  if (md == NULL) {
    //      printf("Unknown message digest %s\n", mdType);
    //      exit(1);
    //  }

     mdctx = EVP_MD_CTX_new();
     EVP_DigestInit_ex(mdctx, md, NULL);
    //  EVP_DigestUpdate(mdctx, mess1, strlen(mess1));
    //  EVP_DigestUpdate(mdctx, mess2, strlen(mess2));
     EVP_DigestUpdate(mdctx, message, strlen(message));

    //  EVP_DigestFinal_ex(mdctx, md_value, &md_len);
     EVP_DigestFinal_ex(mdctx, key, &md_len);
     EVP_DigestFinal_ex(mdctx, iv, &md_len);
     EVP_MD_CTX_free(mdctx);

     memcpy(iv, key, sizeof(iv));
    //  memcpy(iv, key, 16);

     printf("Digest is: ");
     for (i = 0; i < sizeof(key); i++)
     std::cout<<  "         ----->   key[j]: "<< key[i]<<" \n" ;
         printf("%02x", key[i]);
     printf("\n");

     printf("IV is: ");
     for (int j = 0; j < sizeof(iv) ; j++){
        //   iv[j] = key[j];
          std::cout<< "iv["<< j << "]: " <<static_cast<char>(iv[j])<< "            key[j]: "<< key[j]<<" \n" ;
            printf("%02x", iv[j]);
     }




        std::cout << " \n Size of iv: " <<  sizeof(iv)<<  " Size of key: " << sizeof(key)<< std::endl;  
     printf("\n");
}

int main(int args, char* argv[]){

    //  get key and iv
    KeyHandler KeyHandler;
    unsigned char *key = new unsigned char();
    unsigned char *iv =new unsigned char();
    auto pass = reinterpret_cast<char *>(const_cast<char *>("12345"));
    int md_len = KeyHandler.getAESSecret(pass, key, iv);

     printf("key(b): ");
     for (int i = 0; i < md_len; i++)
         printf("%02x", key[i]);
     printf("\n");


    printf("iv(b): ");
     for (int i = 0; i < md_len/2; i++)
         printf("%02x", iv[i]);
     printf("\n");

     
     exit(0);

}