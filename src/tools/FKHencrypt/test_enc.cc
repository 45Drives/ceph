



#include <iostream>
#include <stdint.h>

#include "encrypt.h"
#include "../rados/rados.h"

void usage(ostream &out)
{
    out << "OBJECT COMMANDS\n"
           "   get <obj-name> <outfile>    -p <pool-name> \n"   
           "                                 fetch object\n"
           "   put <obj-name> <infile> -p <pool-name>\n"
           "                                    write encrypted object with start offset (default:0)\n";
    // generic_client_usage();
}

bool argparse_need_usage(const std::vector<const char*>& args)
{
  if (args.empty()) {
    return true;
  }
  for (auto a : args) {
    if (strcmp(a, "-h") == 0 ||
	strcmp(a, "--help") == 0) {
      return true;
    }
  }
  return false;
}


int main(int argc, const char **argv)
{
    int ret;
    std::cout << "---------------- [ FKHENC API ] ---------------- " << std::endl;

    vector<const char *> args;
    args.insert(args.end(), argv + 1, argv + argc);

    // Cheking if the required argument are provided
    if (args.empty())
    {
         cerr << argv[0] << ": -h or --help for usage" << std::endl;
        exit(1);
    }

    if (argparse_need_usage(args))
    {
        usage(cout);
        exit(0);
    }


    // a map for parameters
    std::map<std::string, std::string> opts;
    std::string val;

    if (strcmp(args[0], "put") == 0){
        std::cout<< "FKHENC API storage in progress (put) "<<std::endl;
        std::string obj_name;
        const char *in_filename;
        obj_name = args[1];
        in_filename = args[2];

        bool create_object = false;

        std::cout<< " -----------------> obj_name: "<< obj_name << std::endl;
        std::cout<< " -----------------> in_filename: "<< in_filename << std::endl;

        // ret = FKH::do_put_encrypted(io_ctx, *obj_name, in_filename, op_size, obj_offset, create_object, use_striper);
        // if (ret < 0)
        // {
        //     cerr << "error putting " << pool_name << "/" << prettify(*obj_name) << ": " << cpp_strerror(ret) << std::endl;
        //     return 1;
        // }
        
    }



 

    // AES_CBC_256 aes;
    // unsigned char *plaintext = (unsigned char *)"A test text for encryption! 9 May 2021!";
    // unsigned char ciphertext[128];

    // std::cout << ">>>>>>>> plaintext : >>>>>>>" << plaintext << " >>>>>>>>>>>>>>>" << std::endl;

    // /* A 256 bit key */
    // unsigned char *key = (unsigned char *)"01234567890123456789012345678901";

    // /* A 128 bit IV */
    // unsigned char *iv = (unsigned char *)"0123456789012345";

    // int result = aes.encrypt(plaintext, strlen((char *)plaintext), key, iv, ciphertext);

    // // unsigned char decryptedtext[128];
    // //  int decryptedtext_len = aes.decrypt(result, sizeof(plaintext), key, iv, decryptedtext)
    // //  decryptedtext[decryptedtext_len] = '\0';

    // std::cout << "enc status :  " << result  << std::endl;
    // std::cout << "ciphertext : " << ciphertext << std::endl;

    // std::cout << ">>>>>>>>>>>>>>> End of Main >>>>>>>>>>>>>>>" << std::endl;
    return 0;
}
