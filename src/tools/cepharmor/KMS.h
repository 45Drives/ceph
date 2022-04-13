
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

#ifndef KMS_H
#define KMS_H

class KeyHandler{
  
public:
    int getAESSecret(char* pass, unsigned char* aeskey, unsigned char* aesiv);
    
};


#endif