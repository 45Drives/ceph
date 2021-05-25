
#include "include/types.h"

#include "include/rados/buffer.h"
#include "include/rados/librados.hpp"
#include "include/rados/rados_types.hpp"

#include "acconfig.h"
#ifdef WITH_LIBRADOSSTRIPER
#include "include/radosstriper/libradosstriper.hpp"
using namespace libradosstriper;
#endif

#include "common/config.h"
#include "common/ceph_argparse.h"
#include "global/global_init.h"
#include "common/Cond.h"
#include "common/debug.h"
#include "common/errno.h"
#include "common/Formatter.h"
#include "common/obj_bencher.h"
#include "common/TextTable.h"
#include "include/stringify.h"
#include "mds/inode_backtrace.h"
#include "include/random.h"
#include <iostream>
#include <fstream>

#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <errno.h>
#include <dirent.h>
#include <stdexcept>
#include <climits>
#include <locale>
#include <memory>
#include <optional>

#include "cls/lock/cls_lock_client.h"
#include "include/compat.h"
#include "include/util.h"
#include "common/hobject.h"

#include "PoolDump.h"
#include "RadosImport.h"

#include "osd/ECUtil.h"

// FKH
// #include "../FKHencrypt/encrypt.h"
#include <fstream>
//FKH

using namespace librados;
using ceph::util::generate_random_number;


namespace FKH {
static int do_put_encrypted(IoCtx &io_ctx,
                            const std::string &oid, const char *infile, int op_size,
                            uint64_t obj_offset, bool create_object,
                            const bool use_striper);
}

