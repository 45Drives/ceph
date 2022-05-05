
#include <iostream>
#include <stdint.h>


#include <errno.h>
#include <map>
#include <memory>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <assert.h>     /* assert */
#include <vector>

 #include <openssl/evp.h>
#include <openssl/rand.h>
#include <openssl/md5.h>
#include <openssl/sha.h>
#include <openssl/crypto.h>


#ifndef KMS_H
#define KMS_H

class KeyHandler;

struct data_t {

    // CONSTRUCTOR
    data_t(unsigned int len = 0) 
    : _len(len) {
        this->setKey (new unsigned char[len]());
        this->setIv (new unsigned char[len/2]());
    }
    data_t(unsigned int len = 0, unsigned char* key = NULL) 
    : _len(len) {
        assert(key);
        this->setKey(key);
        this->setIv (new unsigned char[len/2]());
        memcpy(this->_iv, key, (len/2));
    }
    // DESTRUCTOR
    ~data_t() {
        std::free(this->_iv);
        std::free(this->_key);
    }

    // GETTERS
    const unsigned int getLen() {
        return (this->_len);
    }
    const unsigned char* getIv() {
        return (this->_iv);
    }
    const unsigned char* getKey() {
        return (this->_key);
    }

    // FRIENDS
    friend KeyHandler;
    private: 
        unsigned int _len = 0;
        unsigned char* _iv = NULL;
        unsigned char* _key = NULL;

        //  SETTERS
        void setLen(unsigned int len) {
            this->_len = len;
        }
        void setIv(unsigned char* iv) {
            this->_iv = iv;
        }
        void setKey(unsigned char* key) {
            this->_key = key;
        }
        void setIvFromKey() {
            assert(this->_key);
            if (this->_iv == NULL)
                this->_iv = new unsigned char[this->_len/2]();
            // Copy half of key into iv
            memcpy(this->_iv, this->_key, (this->_len/2));
        }
};

class KeyHandler{
    public:
        data_t* getMD(unsigned char* pass);       
        data_t* getAESSecret(unsigned char* pass);       
        data_t* getSHA256(unsigned char* input, unsigned char* md);       
};


#endif