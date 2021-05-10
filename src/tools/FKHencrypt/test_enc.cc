



#include <iostream>
#include <stdint.h>

#include "encrypt.h"

int main()
{
    std::cout << "main function testing encryption!!!!" << std::endl;
    AES_CBC_256 aes;
    unsigned char *plaintext = (unsigned char *)"A test text for encryption! 9 May 2021!";
    unsigned char ciphertext[128];

    std::cout << ">>>>>>>> plaintext : >>>>>>>" << plaintext << " >>>>>>>>>>>>>>>" << std::endl;

    /* A 256 bit key */
    unsigned char *key = (unsigned char *)"01234567890123456789012345678901";

    /* A 128 bit IV */
    unsigned char *iv = (unsigned char *)"0123456789012345";

    int result = aes.encrypt(plaintext, strlen((char *)plaintext), key, iv, ciphertext);

    std::cout << "enc status :  " << result  << std::endl;
    std::cout << "ciphertext : " << ciphertext << std::endl;

    std::cout << ">>>>>>>>>>>>>>> End of Main >>>>>>>>>>>>>>>" << std::endl;
    return 0;
}
