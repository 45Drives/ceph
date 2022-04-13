

#include <iostream>
#include <stdint.h>

#include "Crypt.h"
#include "KMS.h"
#include "../rados/rados.h"
#include "common/obj_bencher.h"
#include <bits/stdc++.h>

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
           "   get <obj-name> <outfile>  <pool-name> [--pass] \n"
           "                                 fetch object\n"
           "   put <obj-name> <infile>  <pool-name> [--pass]\n"
           "                                    write encrypted object with start offset (default:0)\n";
           "   bench <seconds> write|seq|rand [-t concurrent_operations] [--no-cleanup] [--run-name run_name] [--no-hints] [--reuse-bench]\n"
           "                                    default is 16 concurrent IOs and 4 MB ops\n"
           "                                    default is to clean up after write benchmark\n"
           "                                    default run-name is 'benchmark_last_metadata'\n";
           "GLOBAL OPTIONS:\n"
           "   -p pool\n"
           "   --pool=pool\n"
           "        select given pool by name\n"
           "   -b op_size\n"
           "        set the block size for put/get ops and for write benchmarking\n"
           "   -O object_size\n"
           "        set the object size for put/get ops and for write benchmarking\n";
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


static void sanitize_object_contents(bench_data *data, size_t length)
{
    // FIPS zeroization audit 20191115: this memset is not security related.
    memset(data->object_contents, 'z', length);
}



 void read_bench_dec( unsigned char *encMsgOut){ 
   

     Crypt cryptObj;
     //  get key and iv
    KeyHandler KeyHandler;
    unsigned char *key = new unsigned char();
    unsigned char *iv =new unsigned char();
    auto pass = reinterpret_cast<char *>(const_cast<char *>("12345"));
    int md_len = KeyHandler.getAESSecret(pass, key, iv);

   
    // derypt
    char *decMsg;
    cryptObj.aesDecrypt(encMsgOut, strlen((char*)encMsgOut), &decMsg, key, iv);
   
}

bufferlist write_bench_enc(bench_data data){ 

   
     Crypt cryptObj;
     //  get key and iv
    KeyHandler KeyHandler;
    unsigned char *key = new unsigned char();
    unsigned char *iv = new unsigned char();
    auto pass = reinterpret_cast<char *>(const_cast<char *>("12345"));
    int md_len = KeyHandler.getAESSecret(pass, key, iv);

     sanitize_object_contents(&data, data.op_size);
     // encrypt plaintext
     unsigned char *plaintext = (unsigned char *)data.object_contents;
     unsigned char *encMsgOut;

    auto ss = std::chrono::system_clock::now();
    std::chrono::duration<double> t_ss = ss.time_since_epoch();
     

     int encLen = cryptObj.aesEncrypt(plaintext, data.op_size, &encMsgOut, key, iv);
     
    auto ee = std::chrono::system_clock::now();
    std::chrono::duration<double> t_ee = ee.time_since_epoch();


    executionTimeFile<< setprecision(10) << (t_ee.count() - t_ss.count())*1000 <<"," <<" ms, "<< data.op_size<< "\n";


     std::string enc_str(reinterpret_cast<char *>(encMsgOut), encLen);           // (unsigned char* --> string)
     bufferlist encryptedBufferlist = buffer::list::static_from_string(enc_str); // (string --> bufferlist)

     
    return encryptedBufferlist;
   
}

enum OpWriteDest
{
    OP_WRITE_DEST_OBJ = 2 << 0,
    OP_WRITE_DEST_OMAP = 2 << 1,
    OP_WRITE_DEST_XATTR = 2 << 2,
};


class RadosBencher : public ObjBencher
{

    librados::AioCompletion **completions;
    librados::Rados &rados;
    librados::IoCtx &io_ctx;
    librados::NObjectIterator oi;
    bool iterator_valid;
    OpWriteDest write_destination;
    
    bool encFlag = false; // flag to determine if it proceed the encryption path
    

protected:
    int completions_init(int concurrentios) override
    {
        completions = new librados::AioCompletion *[concurrentios];
        return 0;
    }
    void completions_done() override
    {
        delete[] completions;
        completions = NULL;
    }
    int create_completion(int slot, void (*cb)(void *, void *), void *arg) override
    {
        completions[slot] = rados.aio_create_completion((void *)arg, cb);

        if (!completions[slot])
            return -EINVAL;

        return 0;
    }
    void release_completion(int slot) override
    {
        completions[slot]->release();
        completions[slot] = 0;
    }


    int aio_read_enc(const std::string &oid, int slot, bufferlist *pbl, size_t len,
                 size_t offset,  unsigned char *encMsgOut) override
    {
       
        read_bench_dec(encMsgOut); 
  
    
        return io_ctx.aio_read(oid, completions[slot], pbl, len, offset);
    }

    int aio_read(const std::string &oid, int slot, bufferlist *pbl, size_t len,
                 size_t offset) override
    {
        return io_ctx.aio_read(oid, completions[slot], pbl, len, offset);
    }




    int aio_write(const std::string &oid, int slot, bufferlist &bl, size_t len,
                  size_t offset, bool encryptionFlag) override
    { 
        librados::ObjectWriteOperation op;

        if (write_destination & OP_WRITE_DEST_OBJ)
        {
            if (data.hints)
                op.set_alloc_hint2(data.object_size, data.op_size,
                                   ALLOC_HINT_FLAG_SEQUENTIAL_WRITE |
                                       ALLOC_HINT_FLAG_SEQUENTIAL_READ |
                                       ALLOC_HINT_FLAG_APPEND_ONLY |
                                       ALLOC_HINT_FLAG_IMMUTABLE);
            if (encryptionFlag){

                // do encryption
               bufferlist encryptedBufferlist = write_bench_enc(data);


                op.write(offset, bl); 

            }
            else{

            op.write(offset, bl); 

            }
        }

        if (write_destination & OP_WRITE_DEST_OMAP)
        {
            std::map<std::string, librados::bufferlist> omap;
            omap[string("bench-omap-key-") + stringify(offset)] = bl;
            op.omap_set(omap);
        }

        if (write_destination & OP_WRITE_DEST_XATTR)
        {
            char key[80];
            snprintf(key, sizeof(key), "bench-xattr-key-%d", (int)offset);
            op.setxattr(key, bl);
        }

        return io_ctx.aio_operate(oid, completions[slot], &op);
    }




    int aio_remove(const std::string &oid, int slot) override
    {
        return io_ctx.aio_remove(oid, completions[slot]);
    }

    int sync_read(const std::string &oid, bufferlist &bl, size_t len) override
    {
        return io_ctx.read(oid, bl, len, 0);
    }
    int sync_write(const std::string &oid, bufferlist &bl, size_t len) override
    {
        return io_ctx.write_full(oid, bl);
    }

    int sync_remove(const std::string &oid) override
    {
        return io_ctx.remove(oid);
    }

    bool completion_is_done(int slot) override
    {
        return completions[slot] && completions[slot]->is_complete();
    }

    int completion_wait(int slot) override
    {
        return completions[slot]->wait_for_complete_and_cb();
    }
    int completion_ret(int slot) override
    {
        return completions[slot]->get_return_value();
    }

    bool get_objects(std::list<Object> *objects, int num) override
    {
        int count = 0;

        if (!iterator_valid)
        {
            oi = io_ctx.nobjects_begin();
            iterator_valid = true;
        }

        librados::NObjectIterator ei = io_ctx.nobjects_end();

        if (oi == ei)
        {
            iterator_valid = false;
            return false;
        }

        objects->clear();
        for (; oi != ei && count < num; ++oi)
        {
            Object obj(oi->get_oid(), oi->get_nspace());
            objects->push_back(obj);
            ++count;
        }

        return true;
    }

    void set_namespace(const std::string &ns) override
    {
        io_ctx.set_namespace(ns);
    }

public:
    RadosBencher(CephContext *cct_, librados::Rados &_r, librados::IoCtx &_i) // (2)
        : ObjBencher(cct_), completions(NULL), rados(_r), io_ctx(_i), iterator_valid(false), write_destination(OP_WRITE_DEST_OBJ)
    {
    }
    ~RadosBencher() override {}

    void set_write_destination(OpWriteDest dest)
    {
        write_destination = dest;
    }
    void set_enc_flag(){
        encFlag = true;
    }
};

namespace cepharmor
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



static int put_encrypted(IoCtx &io_ctx,
                         const std::string &oid, const char *infile, int op_size,
                         uint64_t obj_offset, bool create_object,
                         const bool use_striper, unsigned char* pass)
{
   //  get key and iv
    KeyHandler KeyHandler;
    unsigned char *key = new unsigned char();
    unsigned char *iv =new unsigned char();
    auto pass = reinterpret_cast<char *>(const_cast<char *>(pass));
    int md_len = KeyHandler.getAESSecret(pass, key, iv);


   

    /*Read infile*/
    std::ifstream in(infile);
    std::string strFile((std::istreambuf_iterator<char>(in)),
                        std::istreambuf_iterator<char>());
    auto contents = strFile.c_str();
    auto message = reinterpret_cast<unsigned char *>(const_cast<char *>(contents));

    // encrypt plaintext
    size_t messageSize = strFile.size();
    unsigned char *encMsgOut;

    Crypt cryptObj;
    int encLen = cryptObj.aesEncrypt(message, messageSize, &encMsgOut, key, iv);
    encMsgOut[encLen] = '\0';

    

    //
    std::string enc_str(reinterpret_cast<char *>(encMsgOut), encLen); // (unsigned char* --> string)
    bufferlist indata = buffer::list::static_from_string(enc_str);    // (string --> bufferlist)


    
    
    //  bool stdio = (strcmp(infile, "-") == 0);
    int ret = 0;
    int fd = STDIN_FILENO;
    //  if (!stdio)
    //  fd = open(infile, O_RDONLY | O_BINARY);
    //  if (fd < 0)
    //  {
    //  cerr << "error reading input file " << infile << std::endl;
    //  cerr << "error reading input file " << infile << ": " << cpp_strerror(errno) << std::endl;
    //  return 1;
    // }
    int count = op_size;
    // buffer::ptr enc_buf(ciphertext_len);
    // int count = ciphertext_len;
    uint64_t offset = obj_offset;
    const std::string oid_enc = oid + ".enc";
    // oid = oid+".enc";
    // while (count != 0)
    // {
    // bufferlist indata;

    // count = indata.read_fd(fd, op_size);
    //  indata.append(enc_str);
    // if (count < 0)
    // {
    //     ret = -errno;
    //     cerr << "error reading input file " << infile << ": " << cpp_strerror(ret) << std::endl;
    //     goto out;
    // }

    // if (count == 0)
    // {
    // if (offset == obj_offset)
    // {                                                               // in case we have to create an empty object & if obj_offset > 0 do a hole
    //     ret = cepharmor::write_full(io_ctx, oid_enc, indata, use_striper); // indata is empty

    //     if (ret < 0)
    //     {
    //         goto out;
    //     }

    //     if (offset)
    //     {
    //         ret = cepharmor::trunc(io_ctx, oid_enc, offset, use_striper); // before truncate, object must be existed.

    //         if (ret < 0)
    //         {
    //             goto out;
    //         }
    //     }
    // }
    // continue;
    // }

    if (0 == offset && create_object)
        ret = cepharmor::write_full(io_ctx, oid_enc, indata, use_striper);
    else
        ret = cepharmor::write(io_ctx, oid_enc, indata, count, offset, use_striper);

    // if (ret < 0)
    // {
    //     goto out;
    // }
    // offset += count;
    // }
    //     ret = 0;
    // out:
    //     if (fd != STDOUT_FILENO)
    //         VOID_TEMP_FAILURE_RETRY(close(fd));
    return ret;
}



static int get_decrypted(IoCtx &io_ctx, const std::string &oid, const char *outfile,
                         unsigned op_size, [[maybe_unused]] const bool use_striper, unsigned char* pass)
{
    
    Crypt cryptObj;

    //  get key and iv
    KeyHandler KeyHandler;
    unsigned char *key = new unsigned char();
    unsigned char *iv =new unsigned char();
    auto pass = reinterpret_cast<char *>(const_cast<char *>(pass));
    int md_len = KeyHandler.getAESSecret(pass, key, iv);

    
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
        ret = cepharmor::read(io_ctx, oid_enc, outdata, op_size, offset, use_striper);

        // convert bufferlist to string
        std::string bf_to_str = outdata.to_str();
        int ciphertext_len = bf_to_str.size();

        char *plaintext;
        unsigned char *ciphertext = (unsigned char *)bf_to_str.c_str();

        int decryptedtext_len = cryptObj.aesDecrypt(ciphertext, ciphertext_len, &plaintext, key, iv);

        // convert plaintext to bufferlist 
        std::string plain_str(reinterpret_cast<char *>(plaintext)); // [WARNING!]
        bufferlist str_to_bf = buffer::list::static_from_string(plain_str);

        // END of Decryption Process

        if (ret <= 0)
        {
            goto out;
        }
        ret = str_to_bf.write_fd(fd);
        if (ret < 0)
        {
            cerr << "error writing to file: " << cpp_strerror(ret) << std::endl;
            goto out;
        }
        if (str_to_bf.length() < op_size)
            break;
        offset += str_to_bf.length();
    }
    ret = 0;

out:
    if (fd != 1)
        VOID_TEMP_FAILURE_RETRY(::close(fd));
    return ret;
}



static int CephArmor_tool_common(const std::map<std::string, std::string> &opts,
                              std::vector<const char *> &nargs)
{

    int ret;
    const char *pool_name = NULL;
    unsigned op_size = default_op_size;
    uint64_t obj_offset = 0;
    bool obj_offset_specified = false;
    
    bool use_striper = false;
    std::map<std::string, std::string>::const_iterator i;

    // valiables for benchmarking
    int concurrent_ios = 16;
    int bench_write_dest = 0;
    bool cleanup = true;
    bool hints = true; 
    bool reuse_bench = false;
    bool block_size_specified = false;
    unsigned object_size = 0;
    unsigned max_objects = 0;
    bool no_verify = false;

    bool enc_bench = false;
    bool write_flag = false;
    bool read_flag = false;


    std::string run_name;
    std::string prefix;
    bool forcefull = false;
    unique_ptr<Formatter> formatter = nullptr;
    bool pretty_format = false;
    bool show_time = false;
    bool wildcard = false;
    const char *output = NULL;
    unsigned char* pass = NULL;



    // std::string input_file;
    std::optional<std::string> obj_name;

    Rados rados;
    IoCtx io_ctx;

    i = opts.find("pool");
    if (i != opts.end())
    {
        pool_name = i->second.c_str();
    }
    i = opts.find("run-name");
    if (i != opts.end())
    {
        run_name = i->second;
    }
    i = opts.find("prefix");
    if (i != opts.end())
    {
        prefix = i->second;
    }
    i = opts.find("concurrent-ios");
    if (i != opts.end())
    {
        if (rados_sistrtoll(i, &concurrent_ios))
        {
            return -EINVAL;
        }
    }
    i = opts.find("block-size");
    if (i != opts.end())
    {
        if (rados_sistrtoll(i, &op_size))
        {
            return -EINVAL;
        }
        block_size_specified = true;
    }
    i = opts.find("object-size");
    if (i != opts.end())
    {
        if (rados_sistrtoll(i, &object_size))
        {
            return -EINVAL;
        }
        block_size_specified = true;
    }
     i = opts.find("max-objects");
    if (i != opts.end())
    {
        if (rados_sistrtoll(i, &max_objects))
        {
            return -EINVAL;
        }
    }
    i = opts.find("no-cleanup");
    if (i != opts.end())
    {
        cleanup = false;
    }
    i = opts.find("enc-bench");
    if (i != opts.end())
    {
        enc_bench = true;
    }
     i = opts.find("show-time");
    if (i != opts.end())
    {
        show_time = true;
    }
    i = opts.find("reuse-bench");
    if (i != opts.end())
    {
        reuse_bench = true;
    }
    i = opts.find("pass");
    if (i != opts.end())
    {
        if (rados_sistrtoll(i, &pass))
        {
            return -EINVAL;
        }
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
        ret = put_encrypted(io_ctx, *obj_name, in_filename, op_size, obj_offset, create_object, use_striper, pass);
        if (ret < 0)
        {
            cerr << "error putting " << pool_name << "/" << prettify(*obj_name) << ": " << cpp_strerror(ret) << std::endl;
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
        ret = get_decrypted(io_ctx, *obj_name, out_filename, op_size, use_striper, pass);
        if (ret < 0)
        {
            cerr << "error getting " << pool_name << "/" << prettify(*obj_name) << ": " << cpp_strerror(ret) << std::endl;
            return 1;
        }
    }
    else if (strcmp(nargs[0], "bench") == 0) // (benchmarking section)
    {
        if (!pool_name || nargs.size() < 3)
        {
            usage(cerr);
            return 1;
        }
        char *endptr = NULL;
        int seconds = strtol(nargs[1], &endptr, 10);
        if (*endptr)
        {
            cerr << "Invalid value for seconds: '" << nargs[1] << "'" << std::endl;
            return 1;
        }
       
        int operation = 0;
        if (strcmp(nargs[2], "write") == 0)
        {
            if (enc_bench)
            {
                operation = OP_WRITE;
                write_flag = true;
            }
            else
            {
                operation = OP_WRITE;
            }
        }
        else if (strcmp(nargs[2], "seq") == 0)
        {
            if (enc_bench)
            {
                operation = OP_SEQ_READ;
                read_flag = true;
            }
            else
            {

                operation = OP_SEQ_READ;
            }
            // read_flag = true;
        }
        else if (strcmp(nargs[2], "rand") == 0){
             if (enc_bench){

             operation = OP_RAND_READ;
             read_flag = true;

             }
             else{

                  operation = OP_RAND_READ;
             }
            
            // read_flag = true;

        }
        else
        {
            usage(cerr);
            return 1;
        }
        if (operation != OP_WRITE)
        {
            if (block_size_specified)
            {
                cerr << "-b|--block_size option can be used only with 'write' bench test"
                     << std::endl;
                return 1;
            }
            if (bench_write_dest != 0)
            {
                cerr << "--write-object, --write-omap and --write-xattr options can "
                        "only be used with the 'write' bench test"
                     << std::endl;
                return 1;
            }
        }
        else if (bench_write_dest == 0)
        {
            bench_write_dest = OP_WRITE_DEST_OBJ;
        }

        if (!formatter && output)
        {
            cerr << "-o|--output option can only be used with '--format' option"
                 << std::endl;
            return 1;
        }
        RadosBencher bencher(g_ceph_context, rados, io_ctx);
        bencher.set_show_time(show_time);
        bencher.set_write_destination(static_cast<OpWriteDest>(bench_write_dest));

        if (enc_bench){
        bencher.set_enc_flag();// FKH enc benchmarking
        }
        ostream *outstream = NULL;
        if (formatter)
        {
            bencher.set_formatter(formatter.get());
            if (output)
                outstream = new ofstream(output);
            else
                outstream = &cout;
            bencher.set_outstream(*outstream);
        }
        if (!object_size)
            object_size = op_size;
        else if (object_size < op_size)
            op_size = object_size;
        cout << "hints = " << (int)hints << std::endl;
        if (write_flag || read_flag)
        {
             ret = bencher.aio_bench_enc(operation, seconds,
                                            concurrent_ios, op_size, object_size,
                                            max_objects, cleanup, hints, run_name, reuse_bench, write_flag, read_flag, no_verify);
        }else
        {
            ret = bencher.aio_bench(operation, seconds,
                                    concurrent_ios, op_size, object_size,
                                    max_objects, cleanup, hints, run_name, reuse_bench, no_verify);
        }
        if (ret != 0)
            cerr << "error during benchmark: " << cpp_strerror(ret) << std::endl;
        if (formatter && output)
            delete outstream;
    }
    else if (strcmp(nargs[0], "cleanup") == 0)
    {
        if (!pool_name)
        {
            usage(cerr);
            return 1;
        }
        if (wildcard)
            io_ctx.set_namespace(all_nspaces);
        RadosBencher bencher(g_ceph_context, rados, io_ctx);
        ret = bencher.clean_up(prefix, concurrent_ios, run_name);
        if (ret != 0)
            cerr << "error during cleanup: " << cpp_strerror(ret) << std::endl;
    }
    else
    {
        cerr << "unrecognized command CephArmor API" << nargs[0] << "; -h or --help for usage" << std::endl;
        ret = -EINVAL;
    }

    if (ret < 0)
        cerr << "error " << (-ret) << ": " << cpp_strerror(ret) << std::endl;

    return (ret < 0) ? 1 : 0;
}

int main(int argc, const char **argv)
{


    
    std::cout << "---------------- [ CephArmor API ] ---------------- " << std::endl;

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
         else if (ceph_argparse_flag(args, i, "--show-time", (char *)NULL))
        {
            opts["show-time"] = "true";
        }
        else if (ceph_argparse_flag(args, i, "--no-cleanup", (char *)NULL)) // for benchmarking
        {
            opts["no-cleanup"] = "true";
        }
         else if (ceph_argparse_witharg(args, i, &val, "-t", "--concurrent-ios", (char *)NULL))
        {
            opts["concurrent-ios"] = val;
        }
        else if (ceph_argparse_witharg(args, i, &val, "--block-size", (char *)NULL))
        {
            opts["block-size"] = val;
        }
        else if (ceph_argparse_witharg(args, i, &val, "-b", (char *)NULL))
        {
            opts["block-size"] = val;
        }
        else if (ceph_argparse_witharg(args, i, &val, "--object-size", (char *)NULL))
        {
            opts["object-size"] = val;
        }
        else if (ceph_argparse_witharg(args, i, &val, "-O", (char *)NULL))
        {
            opts["object-size"] = val;
        }
         else if (ceph_argparse_witharg(args, i, &val, "--max-objects", (char *)NULL))
        {
            opts["max-objects"] = val;
        }
        else if (ceph_argparse_flag(args, i, "--pretty-format", (char *)NULL))
        {
            opts["pretty-format"] = "true";
        }
        else if (ceph_argparse_flag(args, i, "--enc-bench", (char *)NULL))
        {
            opts["enc-bench"] = "true";
        }
        else if (ceph_argparse_flag(args, i, "--pass", (char *)NULL))
        {
            opts["pass"] = "true";
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
        cerr << "CephArmor: you must give an action. Try --help" << std::endl;
        return 1;
    }

    return CephArmor_tool_common(opts, args);
}
