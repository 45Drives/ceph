



#include <iostream>
#include <stdint.h>

#include "encrypt.h"
#include "../rados/rados.h"

// 
#ifdef WITH_LIBRADOSSTRIPER
#include "include/radosstriper/libradosstriper.hpp"
using namespace libradosstriper;
#endif
//

unsigned default_op_size = 1 << 22;
static const unsigned MAX_OMAP_BYTES_PER_REQUEST = 1 << 10;


void usage(ostream &out)
{
    out << "OBJECT COMMANDS\n"
           "   get <obj-name> <outfile>  <pool-name> \n"   
           "                                 fetch object\n"
           "   put <obj-name> <infile>  <pool-name>\n"
           "                                    write encrypted object with start offset (default:0)\n";
    generic_client_usage();
}


[[noreturn]] static void usage_exit()
{
    usage(cerr);
    exit(1);
}

static std::string prettify(const std::string &s)
{
    if (std::find_if_not(s.begin(), s.end(),
                         (int (*)(int))isprint) != s.end())
    {
        return "(binary key)";
    }
    else
    {
        return s;
    }
}

namespace fkhdetail
{

#ifdef WITH_LIBRADOSSTRIPER
    RadosStriper &striper()
    {
        static RadosStriper s;
        return s;
    }
#endif


int write([[maybe_unused]] IoCtx &io_ctx, const std::string &oid, buffer::list &indata, const uint64_t count, const uint64_t offset, [[maybe_unused]] const bool use_striper)
    {
#ifdef WITH_LIBRADOSSTRIPER
        if (use_striper)
            return striper().write(oid, indata, count, offset);
#endif

        return io_ctx.write(oid, indata, count, offset);
    }

    int write_full([[maybe_unused]] IoCtx &io_ctx, const std::string &oid, bufferlist &indata, [[maybe_unused]] const bool use_striper)
    {
#ifdef WITH_LIBRADOSSTRIPER
        if (use_striper)
            return striper().write_full(oid, indata);
#endif

        return io_ctx.write_full(oid, indata);
    }

    int trunc([[maybe_unused]] IoCtx &io_ctx, const std::string &oid, const uint64_t offset, [[maybe_unused]] const bool use_striper)
    {
#ifdef WITH_LIBRADOSSTRIPER
        if (use_striper)
            return striper().trunc(oid, offset);
#endif

        return io_ctx.trunc(oid, offset);
    }


} // END of name space fkhdetail


static int put_encrypted(IoCtx &io_ctx,
                            const std::string &oid, const char *infile, int op_size,
                            uint64_t obj_offset, bool create_object,
                            const bool use_striper)
{
    // FKH ENC START

    /*Read infile*/
    std::ifstream in(infile);
    std::string strFile((std::istreambuf_iterator<char>(in)),
                        std::istreambuf_iterator<char>());
    auto contents = strFile.c_str();
    auto plaintext = reinterpret_cast<unsigned char *>(const_cast<char *>(contents));




    AES_CBC_256 aes;

    /* Buffer for the decrypted text */
    unsigned char *decryptedtext= new unsigned char[128];
    unsigned char *ciphertext= new unsigned char[128];

    int decryptedtext_len, ciphertext_len;

    // unsigned char ciphertext[128];
    /* A 256 bit key */
    unsigned char *key = (unsigned char *)"01234567890123456789012345678901";

    /* A 128 bit IV */
    unsigned char *iv = (unsigned char *)"0123456789012345";


 /* Encrypt the plaintext */
    ciphertext_len = aes.encrypt(plaintext, strlen((char *)plaintext), key, iv,ciphertext);


    std::cout << "ciphertext_len rados.cc:  " << ciphertext_len  << std::endl;
    std::cout << "ciphertext rados.cc: " << ciphertext << std::endl;

    printf("Ciphertext is:\n");
    BIO_dump_fp(stdout, (const char *)ciphertext, ciphertext_len);

    std::ofstream encfile("enc.txt", std::ios::out | std::ios::binary);
    ciphertext[ciphertext_len]  = '\0';
    encfile << ciphertext;
    encfile.close();

// [TO DO] apppend the "enc_str" to the infile
 std::string enc_str(reinterpret_cast<char *>(ciphertext), ciphertext_len);

 std::cout << "###################### END OF ENCRYPTION #############################" << std::endl;



 // FKH ENC END
infile = "enc.txt";
 bool stdio = (strcmp(infile, "-") == 0);
 int ret = 0;
 int fd = STDIN_FILENO;
 if (!stdio)
     fd = open(infile, O_RDONLY | O_BINARY);
 if (fd < 0)
 {
     cerr << "error reading input file " << infile << std::endl;
    //  cerr << "error reading input file " << infile << ": " << cpp_strerror(errno) << std::endl;
     return 1;
    }
    int count = op_size;
    // buffer::ptr enc_buf(ciphertext_len);
    // int count = ciphertext_len;
    uint64_t offset = obj_offset;
    while (count != 0)
    {
        bufferlist indata;
       
        count = indata.read_fd(fd, op_size);
        //  indata.append(enc_str);
        if (count < 0)
        {
            ret = -errno;
            cerr << "error reading input file " << infile << ": " << cpp_strerror(ret) << std::endl;
            goto out;
        }

        if (count == 0)
        {
            if (offset == obj_offset)
            {                                                               // in case we have to create an empty object & if obj_offset > 0 do a hole
                ret = fkhdetail::write_full(io_ctx, oid, indata, use_striper); // indata is empty 

                if (ret < 0)
                {
                    goto out;
                }

                if (offset)
                {
                    ret = fkhdetail::trunc(io_ctx, oid, offset, use_striper); // before truncate, object must be existed.

                    if (ret < 0)
                    {
                        goto out;
                    }
                }
            }
            continue;
        }

        if (0 == offset && create_object)
            ret = fkhdetail::write_full(io_ctx, oid, indata, use_striper);
        else
            ret = fkhdetail::write(io_ctx, oid, indata, count, offset, use_striper);

        if (ret < 0)
        {
            goto out;
        }
        offset += count;
    }
    ret = 0;
out:
    if (fd != STDOUT_FILENO)
        VOID_TEMP_FAILURE_RETRY(close(fd));
    return ret;
}

// FKH END OF do_put_encrypted()


// }


static int FKHENC_tool_common(const std::map<std::string, std::string> &opts,
                             std::vector<const char *> &nargs)
{

    int ret;
    const char *pool_name = NULL;
    unsigned op_size = default_op_size;
    uint64_t obj_offset = 0;
    bool obj_offset_specified = false;
    bool use_striper = false;
    std::map<std::string, std::string>::const_iterator i;


 
   // std::string input_file;
    std::optional<std::string> obj_name;

    Rados rados;
    IoCtx io_ctx;


    i = opts.find("pool");
    if (i != opts.end())
    {
        pool_name = i->second.c_str();
    }
    


    // open rados
    ret = rados.init_with_context(g_ceph_context);
    if (ret < 0)
    {
        cerr << "couldn't initialize rados: " << cpp_strerror(ret) << std::endl;
        return 1;
    }

    ret = rados.connect();
    if (ret)
    {
        cerr << "couldn't connect to cluster: " << cpp_strerror(ret) << std::endl;
        return 1;
    }



i = opts.find("pgid");
    boost::optional<pg_t> pgid(i != opts.end(), pg_t());
    if (pgid && (!pgid->parse(i->second.c_str()) || (pool_name && rados.pool_lookup(pool_name) != pgid->pool())))
    {
        cerr << "invalid pgid" << std::endl;
        return 1;
    }


 // open io context.
    if (pool_name || pgid)
    {
        ret = pool_name ? rados.ioctx_create(pool_name, io_ctx) : rados.ioctx_create2(pgid->pool(), io_ctx);
        if (ret < 0)
        {
            cerr << "error opening pool "
                 << (pool_name ? pool_name : std::string("with id ") + std::to_string(pgid->pool())) << ": "
                 << cpp_strerror(ret) << std::endl;
            return 1;
        }

        // align op_size
        {
            bool requires;
            ret = io_ctx.pool_requires_alignment2(&requires);
            if (ret < 0)
            {
                cerr << "error checking pool alignment requirement"
                     << cpp_strerror(ret) << std::endl;
                return 1;
            }

            if (requires)
            {
                uint64_t align = 0;
                ret = io_ctx.pool_required_alignment2(&align);
                if (ret < 0)
                {
                    cerr << "error getting pool alignment"
                         << cpp_strerror(ret) << std::endl;
                    return 1;
                }

                const uint64_t prev_op_size = op_size;
                op_size = uint64_t((op_size + align - 1) / align) * align;
                // Warn: if user specified and it was rounded
                if (prev_op_size != default_op_size && prev_op_size != op_size)
                    cerr << "INFO: op_size has been rounded to " << op_size << std::endl;
            }
        }

    }





         ceph_assert(!nargs.empty());

     if (strcmp(nargs[0], "put") == 0)
        {
            if (!pool_name || nargs.size() < (obj_name ? 2 : 3))
            {
                usage(cerr);
                return 1;
            }
            const char *in_filename;
            if (obj_name)
            {
                in_filename = nargs[1];
            }
            else
            {
                obj_name = nargs[1];
                in_filename = nargs[2];
            }
            bool create_object = !obj_offset_specified;
            ret = put_encrypted(io_ctx, *obj_name, in_filename, op_size, obj_offset, create_object, use_striper);
            if (ret < 0)
            {
                cerr << "error putting " << pool_name << "/" << prettify(*obj_name)<< ": " << cpp_strerror(ret) << std::endl;
                return 1;
            }
        }
        else
        {
            cerr << "unrecognized command FKHENC API" << nargs[0] << "; -h or --help for usage" << std::endl;
            ret = -EINVAL;
        }

        if (ret < 0)
            cerr << "error " << (-ret) << ": " << cpp_strerror(ret) << std::endl;

        return (ret < 0) ? 1 : 0;
}



int main(int argc, const char **argv)
{   std::cout << "---------------- [ FKHENC API ] ---------------- " << std::endl;

    
    // parse input arguments
    vector<const char *> args;
    argv_to_vec(argc, argv, args);
    if (args.empty())
    {
        cerr << argv[0] << ": -h or --help for usage" << std::endl;
        exit(1);
    }
    if (ceph_argparse_need_usage(args))
    {
        usage(cout);
        exit(0);
    }

    std::map<std::string, std::string> opts;
    std::string val;

    for (auto j = args.begin(); j != args.end(); ++j)
    {
        if (strcmp(*j, "--") == 0)
        {
            break;
        }
        else if ((j + 1) == args.end())
        {
            // This can't be a formatting call (no format arg)
            break;
        }
        else if (strcmp(*j, "-f") == 0)
        {
            val = *(j + 1);
            unique_ptr<Formatter> formatter(Formatter::create(val.c_str()));

            if (formatter)
            {
                j = args.erase(j);
                opts["format"] = val;

                j = args.erase(j);
                break;
            }
        }
    }





      // FKH initializing Ceph required environment values
    auto cct = global_init(NULL, args, CEPH_ENTITY_TYPE_CLIENT,
                           CODE_ENVIRONMENT_UTILITY, 0);
    common_init_finish(g_ceph_context);


    // FKH adds input parameters such as poolname into the vector i
    std::vector<const char *>::iterator i;
    for (i = args.begin(); i != args.end();)
    {
        if (ceph_argparse_double_dash(args, i))
        {
            break;
        }
        else if (ceph_argparse_witharg(args, i, &val, "-p", "--pool", (char *)NULL))
        {
            opts["pool"] = val;
        }
        else
        {
            if (val[0] == '-')
                usage_exit();
            ++i;
        }

    }

    
 if (args.empty())
    {
        cerr << "FKHENC: you must give an action. Try --help" << std::endl;
        return 1;
    }

    return FKHENC_tool_common(opts, args);
}
