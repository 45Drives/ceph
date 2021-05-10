

#include <iostream>
#include <stdint.h>
#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <string.h>
#include <string>


#include "global/global_init.h"
#include "common/ceph_argparse.h"



using namespace std;

// 
void handleErrors(void);
//


class AES_CBC_256
{
public:
    static const long unsigned int AES_256_KEYSIZE = 256 / 8;
    static const long unsigned int AES_256_IVSIZE = 128 / 8;
    static const long unsigned int CHUNK_SIZE = 4096;

private:
    static const unsigned char  IV[AES_256_IVSIZE];
    unsigned char  key[AES_256_KEYSIZE];

public:
    bool set_key(unsigned char *key_t, long unsigned int key_size)
    {
        memcpy(key, key_t, AES_256_KEYSIZE);
        return true;
    }

AES_CBC_256(){
    std::cout<< "AES_CBC_256 constructor header! "<< std::endl;

}

~AES_CBC_256(){
    std::cout<< "AES_CBC_256 destructor ! "<< std::endl;

}

bool encrypt(bufferlist& input, off_t in_ofs,
             long unsigned int size, bufferlist& output,   
             off_t stream_offset);


int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
            unsigned char *iv, unsigned char *ciphertext);


bool decrypt(bufferlist& input, off_t in_ofs,
                       long unsigned int size, bufferlist& output,
                       off_t stream_offset);

};