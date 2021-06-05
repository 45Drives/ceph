



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


template <typename I, typename T>
static int rados_sistrtoll(I &i, T *val)
{
    std::string err;
    *val = strict_iecstrtoll(i->second.c_str(), &err);
    if (err != "")
    {
        cerr << "Invalid value for " << i->first << ": " << err << std::endl;
        return -EINVAL;
    }
    else
    {
        return 0;
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

int read([[maybe_unused]] IoCtx &io_ctx, const std::string &oid, buffer::list &out_data, const unsigned op_size, const uint64_t offset, [[maybe_unused]] const bool use_striper)
    {
#ifdef WITH_LIBRADOSSTRIPER
        if (use_striper)
            return striper().read(oid, &out_data, op_size, offset);
#endif

        return io_ctx.read(oid, out_data, op_size, offset);
    }

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


// static int do_lock_cmd(std::vector<const char *> &nargs,
//                        const std::map<std::string, std::string> &opts,
//                        IoCtx *ioctx,
//                        Formatter *formatter)
// {
//     if (nargs.size() < 3)
//         usage_exit();

//     string cmd(nargs[1]);
//     string oid(nargs[2]);

//     string lock_tag;
//     string lock_cookie;
//     string lock_description;
//     int lock_duration = 0;
//     ClsLockType lock_type = ClsLockType::EXCLUSIVE;

//     map<string, string>::const_iterator i;
//     i = opts.find("lock-tag");
//     if (i != opts.end())
//     {
//         lock_tag = i->second;
//     }
//     i = opts.find("lock-cookie");
//     if (i != opts.end())
//     {
//         lock_cookie = i->second;
//     }
//     i = opts.find("lock-description");
//     if (i != opts.end())
//     {
//         lock_description = i->second;
//     }
//     i = opts.find("lock-duration");
//     if (i != opts.end())
//     {
//         if (rados_sistrtoll(i, &lock_duration))
//         {
//             return -EINVAL;
//         }
//     }
//     i = opts.find("lock-type");
//     if (i != opts.end())
//     {
//         const string &type_str = i->second;
//         if (type_str.compare("exclusive") == 0)
//         {
//             lock_type = ClsLockType::EXCLUSIVE;
//         }
//         else if (type_str.compare("shared") == 0)
//         {
//             lock_type = ClsLockType::SHARED;
//         }
//         else
//         {
//             cerr << "unknown lock type was specified, aborting" << std::endl;
//             return -EINVAL;
//         }
//     }

//     if (cmd.compare("list") == 0)
//     {
//         list<string> locks;
//         int ret = rados::cls::lock::list_locks(ioctx, oid, &locks);
//         if (ret < 0)
//         {
//             cerr << "ERROR: rados_list_locks(): " << cpp_strerror(ret) << std::endl;
//             return ret;
//         }

//         formatter->open_object_section("object");
//         formatter->dump_string("objname", oid);
//         formatter->open_array_section("locks");
//         list<string>::iterator iter;
//         for (iter = locks.begin(); iter != locks.end(); ++iter)
//         {
//             formatter->open_object_section("lock");
//             formatter->dump_string("name", *iter);
//             formatter->close_section();
//         }
//         formatter->close_section();
//         formatter->close_section();
//         formatter->flush(cout);
//         return 0;
//     }

//     if (nargs.size() < 4)
//         usage_exit();

//     string lock_name(nargs[3]);

//     if (cmd.compare("info") == 0)
//     {
//         map<rados::cls::lock::locker_id_t, rados::cls::lock::locker_info_t> lockers;
//         ClsLockType type = ClsLockType::NONE;
//         string tag;
//         int ret = rados::cls::lock::get_lock_info(ioctx, oid, lock_name, &lockers, &type, &tag);
//         if (ret < 0)
//         {
//             cerr << "ERROR: rados_lock_get_lock_info(): " << cpp_strerror(ret) << std::endl;
//             return ret;
//         }

//         formatter->open_object_section("lock");
//         formatter->dump_string("name", lock_name);
//         formatter->dump_string("type", cls_lock_type_str(type));
//         formatter->dump_string("tag", tag);
//         formatter->open_array_section("lockers");
//         map<rados::cls::lock::locker_id_t, rados::cls::lock::locker_info_t>::iterator iter;
//         for (iter = lockers.begin(); iter != lockers.end(); ++iter)
//         {
//             const rados::cls::lock::locker_id_t &id = iter->first;
//             const rados::cls::lock::locker_info_t &info = iter->second;
//             formatter->open_object_section("locker");
//             formatter->dump_stream("name") << id.locker;
//             formatter->dump_string("cookie", id.cookie);
//             formatter->dump_string("description", info.description);
//             formatter->dump_stream("expiration") << info.expiration;
//             formatter->dump_stream("addr") << info.addr.get_legacy_str();
//             formatter->close_section();
//         }
//         formatter->close_section();
//         formatter->close_section();
//         formatter->flush(cout);

//         return ret;
//     }
//     else if (cmd.compare("get") == 0)
//     {
//         rados::cls::lock::Lock l(lock_name);
//         l.set_cookie(lock_cookie);
//         l.set_tag(lock_tag);
//         l.set_duration(utime_t(lock_duration, 0));
//         l.set_description(lock_description);
//         int ret;
//         switch (lock_type)
//         {
//         case ClsLockType::SHARED:
//             ret = l.lock_shared(ioctx, oid);
//             break;
//         default:
//             ret = l.lock_exclusive(ioctx, oid);
//         }
//         if (ret < 0)
//         {
//             cerr << "ERROR: failed locking: " << cpp_strerror(ret) << std::endl;
//             return ret;
//         }

//         return ret;
//     }

//     if (nargs.size() < 5)
//         usage_exit();

//     if (cmd.compare("break") == 0)
//     {
//         string locker(nargs[4]);
//         rados::cls::lock::Lock l(lock_name);
//         l.set_cookie(lock_cookie);
//         l.set_tag(lock_tag);
//         entity_name_t name;
//         if (!name.parse(locker))
//         {
//             cerr << "ERROR: failed to parse locker name (" << locker << ")" << std::endl;
//             return -EINVAL;
//         }
//         int ret = l.break_lock(ioctx, oid, name);
//         if (ret < 0)
//         {
//             cerr << "ERROR: failed breaking lock: " << cpp_strerror(ret) << std::endl;
//             return ret;
//         }
//     }
//     else
//     {
//         usage_exit();
//     }

//     return 0;
// }


std::map<std::string, unsigned char*> setupEnc(void){

std::map<std::string, unsigned char*> setup;
/* A 256 bit key */
setup["key"]=(unsigned char *)"01234567890123456789012345678901";

/* A 128 bit IV */
setup["iv"]=(unsigned char *)"0123456789012345";

   return setup;
}



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
    
    unsigned char *ciphertext= new unsigned char[128];

    int ciphertext_len;


    //Set up Key and IV
    unsigned char *key;
    unsigned char *iv;
    std::map<std::string, unsigned char *> values = setupEnc();
    key = values["key"];
    iv = values["iv"];



 /* Encrypt the plaintext */
    ciphertext_len = aes.encrypt(plaintext, strlen((char *)plaintext), key, iv, ciphertext);


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
    const std::string oid_enc=oid+".enc";
    // oid = oid+".enc";
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
                ret = fkhdetail::write_full(io_ctx, oid_enc, indata, use_striper); // indata is empty 

                if (ret < 0)
                {
                    goto out;
                }

                if (offset)
                {
                    ret = fkhdetail::trunc(io_ctx, oid_enc, offset, use_striper); // before truncate, object must be existed.

                    if (ret < 0)
                    {
                        goto out;
                    }
                }
            }
            continue;
        }

        if (0 == offset && create_object)
            ret = fkhdetail::write_full(io_ctx, oid_enc, indata, use_striper);
        else
            ret = fkhdetail::write(io_ctx, oid_enc, indata, count, offset, use_striper);

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

// FKH END OF put_encrypted()


// FKH get_encrypted()



static int get_encrypted(IoCtx &io_ctx, const std::string &oid, const char *outfile, 
                            unsigned op_size, [[maybe_unused]] const bool use_striper)
{
    std::cout<< "--------------[ FKH get_encrypted function started ]--------------  " << std::endl;
    int fd;
    if (strcmp(outfile, "-") == 0)
    {
        fd = STDOUT_FILENO;
    }
    else
    {
        fd = TEMP_FAILURE_RETRY(::open(outfile, O_WRONLY | O_CREAT | O_TRUNC | O_BINARY, 0644));
        if (fd < 0)
        {
            int err = errno;
            cerr << "failed to open file: " << cpp_strerror(err) << std::endl;
            return -err;
        }
    }

    uint64_t offset = 0;
    int ret;
    const std::string oid_enc = oid + ".enc";

    // oid = oid+".enc";
    while (true)
    {
        bufferlist outdata;
        

        ret = fkhdetail::read(io_ctx, oid_enc, outdata, op_size, offset, use_striper);


        // FKH START of Decryption Process
        AES_CBC_256 aes;

        unsigned char *ciphertext; 
        int ciphertext_len;
        unsigned char *plaintext= new unsigned char[128];
        
        //Set up Key and IV
        unsigned char *key;
        unsigned char *iv;
        std::map<std::string, unsigned char *> values = setupEnc();
        key = values["key"];
        iv = values["iv"];

     
        // decryptedtext_len = aes.decrypt(ciphertext, ciphertext_len, unsigned key, iv, plaintext);

        std::string bf_to_str=outdata.c_str();
        std::cout<< " --------------[ bf_to_str ]-------------- : "<<bf_to_str << std::endl;
        // FKH END of Decryption Process


        if (ret <= 0)
        {
            goto out;
        }
        ret = outdata.write_fd(fd);
        if (ret < 0)
        {
            cerr << "error writing to file: " << cpp_strerror(ret) << std::endl;
            goto out;
        }
        if (outdata.length() < op_size)
            break;
        offset += outdata.length();
    }
    ret = 0;

out:
    if (fd != 1)
        VOID_TEMP_FAILURE_RETRY(::close(fd));
    return ret;
}



// FKH END of get_encrypted()




static int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,
            unsigned char *iv, unsigned char *plaintext)
{
    EVP_CIPHER_CTX *ctx;

    int len;

    int plaintext_len;

    /* Create and initialise the context */
    if (!(ctx = EVP_CIPHER_CTX_new()))
        handleErrors();

    /*
     * Initialise the decryption operation. IMPORTANT - ensure you use a key
     * and IV size appropriate for your cipher
     * In this example we are using 256 bit AES (i.e. a 256 bit key). The
     * IV size for *most* modes is the same as the block size. For AES this
     * is 128 bits
     */
    if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    /*
     * Provide the message to be decrypted, and obtain the plaintext output.
     * EVP_DecryptUpdate can be called multiple times if necessary.
     */
    if (1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len))
        handleErrors();
    plaintext_len = len;

    /*
     * Finalise the decryption. Further plaintext bytes may be written at
     * this stage.
     */
    if (1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len))
        handleErrors();
    plaintext_len += len;

    /* Clean up */
    EVP_CIPHER_CTX_free(ctx);

    return plaintext_len;
}


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
        else if (strcmp(nargs[0], "get") == 0)
    {
        if (!pool_name || nargs.size() < (obj_name ? 2 : 3))
        {
            usage(cerr);
            return 1;
        }
        const char *out_filename;
        if (obj_name)
        {
            out_filename = nargs[1];
        }
        else
        {
            obj_name = nargs[1];
            out_filename = nargs[2];
        }
        ret = get_encrypted(io_ctx, *obj_name, out_filename, op_size, use_striper);
        if (ret < 0)
        {
            cerr << "error getting " << pool_name << "/" << prettify(*obj_name) << ": " << cpp_strerror(ret) << std::endl;
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
