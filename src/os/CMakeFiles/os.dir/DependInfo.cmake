# The set of languages for which implicit dependencies are needed:
set(CMAKE_DEPENDS_LANGUAGES
  "C"
  "CXX"
  )
# The set of files for implicit dependencies of each language:
set(CMAKE_DEPENDS_CHECK_C
  "/root/ceph/src/os/filestore/os_xattr.c" "/root/ceph/src/os/CMakeFiles/os.dir/filestore/os_xattr.c.o"
  )
set(CMAKE_C_COMPILER_ID "GNU")

# Preprocessor definitions for this target.
set(CMAKE_TARGET_DEFINITIONS_C
  "HAVE_CONFIG_H"
  "_FILE_OFFSET_BITS=64"
  "_GNU_SOURCE"
  "_REENTRANT"
  "_THREAD_SAFE"
  "__CEPH__"
  "__STDC_FORMAT_MACROS"
  "__linux__"
  )

# The include file search paths:
set(CMAKE_C_TARGET_INCLUDE_PATH
  "boost/include"
  "src/include"
  "src"
  "include"
  "src/xxHash"
  "src/rapidjson/include"
  "src/fmt/include"
  "src/rocksdb/include"
  "/usr/include/fuse"
  )
set(CMAKE_DEPENDS_CHECK_CXX
  "/root/ceph/src/os/FuseStore.cc" "/root/ceph/src/os/CMakeFiles/os.dir/FuseStore.cc.o"
  "/root/ceph/src/os/ObjectStore.cc" "/root/ceph/src/os/CMakeFiles/os.dir/ObjectStore.cc.o"
  "/root/ceph/src/os/Transaction.cc" "/root/ceph/src/os/CMakeFiles/os.dir/Transaction.cc.o"
  "/root/ceph/src/os/bluestore/Allocator.cc" "/root/ceph/src/os/CMakeFiles/os.dir/bluestore/Allocator.cc.o"
  "/root/ceph/src/os/bluestore/AvlAllocator.cc" "/root/ceph/src/os/CMakeFiles/os.dir/bluestore/AvlAllocator.cc.o"
  "/root/ceph/src/os/bluestore/BitmapAllocator.cc" "/root/ceph/src/os/CMakeFiles/os.dir/bluestore/BitmapAllocator.cc.o"
  "/root/ceph/src/os/bluestore/BitmapFreelistManager.cc" "/root/ceph/src/os/CMakeFiles/os.dir/bluestore/BitmapFreelistManager.cc.o"
  "/root/ceph/src/os/bluestore/BlueFS.cc" "/root/ceph/src/os/CMakeFiles/os.dir/bluestore/BlueFS.cc.o"
  "/root/ceph/src/os/bluestore/BlueRocksEnv.cc" "/root/ceph/src/os/CMakeFiles/os.dir/bluestore/BlueRocksEnv.cc.o"
  "/root/ceph/src/os/bluestore/BlueStore.cc" "/root/ceph/src/os/CMakeFiles/os.dir/bluestore/BlueStore.cc.o"
  "/root/ceph/src/os/bluestore/FreelistManager.cc" "/root/ceph/src/os/CMakeFiles/os.dir/bluestore/FreelistManager.cc.o"
  "/root/ceph/src/os/bluestore/HybridAllocator.cc" "/root/ceph/src/os/CMakeFiles/os.dir/bluestore/HybridAllocator.cc.o"
  "/root/ceph/src/os/bluestore/StupidAllocator.cc" "/root/ceph/src/os/CMakeFiles/os.dir/bluestore/StupidAllocator.cc.o"
  "/root/ceph/src/os/bluestore/bluefs_types.cc" "/root/ceph/src/os/CMakeFiles/os.dir/bluestore/bluefs_types.cc.o"
  "/root/ceph/src/os/bluestore/bluestore_types.cc" "/root/ceph/src/os/CMakeFiles/os.dir/bluestore/bluestore_types.cc.o"
  "/root/ceph/src/os/bluestore/fastbmap_allocator_impl.cc" "/root/ceph/src/os/CMakeFiles/os.dir/bluestore/fastbmap_allocator_impl.cc.o"
  "/root/ceph/src/os/filestore/BtrfsFileStoreBackend.cc" "/root/ceph/src/os/CMakeFiles/os.dir/filestore/BtrfsFileStoreBackend.cc.o"
  "/root/ceph/src/os/filestore/DBObjectMap.cc" "/root/ceph/src/os/CMakeFiles/os.dir/filestore/DBObjectMap.cc.o"
  "/root/ceph/src/os/filestore/FileJournal.cc" "/root/ceph/src/os/CMakeFiles/os.dir/filestore/FileJournal.cc.o"
  "/root/ceph/src/os/filestore/FileStore.cc" "/root/ceph/src/os/CMakeFiles/os.dir/filestore/FileStore.cc.o"
  "/root/ceph/src/os/filestore/GenericFileStoreBackend.cc" "/root/ceph/src/os/CMakeFiles/os.dir/filestore/GenericFileStoreBackend.cc.o"
  "/root/ceph/src/os/filestore/HashIndex.cc" "/root/ceph/src/os/CMakeFiles/os.dir/filestore/HashIndex.cc.o"
  "/root/ceph/src/os/filestore/IndexManager.cc" "/root/ceph/src/os/CMakeFiles/os.dir/filestore/IndexManager.cc.o"
  "/root/ceph/src/os/filestore/JournalThrottle.cc" "/root/ceph/src/os/CMakeFiles/os.dir/filestore/JournalThrottle.cc.o"
  "/root/ceph/src/os/filestore/JournalingObjectStore.cc" "/root/ceph/src/os/CMakeFiles/os.dir/filestore/JournalingObjectStore.cc.o"
  "/root/ceph/src/os/filestore/LFNIndex.cc" "/root/ceph/src/os/CMakeFiles/os.dir/filestore/LFNIndex.cc.o"
  "/root/ceph/src/os/filestore/WBThrottle.cc" "/root/ceph/src/os/CMakeFiles/os.dir/filestore/WBThrottle.cc.o"
  "/root/ceph/src/os/filestore/XfsFileStoreBackend.cc" "/root/ceph/src/os/CMakeFiles/os.dir/filestore/XfsFileStoreBackend.cc.o"
  "/root/ceph/src/os/filestore/chain_xattr.cc" "/root/ceph/src/os/CMakeFiles/os.dir/filestore/chain_xattr.cc.o"
  "/root/ceph/src/os/fs/FS.cc" "/root/ceph/src/os/CMakeFiles/os.dir/fs/FS.cc.o"
  "/root/ceph/src/os/fs/XFS.cc" "/root/ceph/src/os/CMakeFiles/os.dir/fs/XFS.cc.o"
  "/root/ceph/src/os/kstore/KStore.cc" "/root/ceph/src/os/CMakeFiles/os.dir/kstore/KStore.cc.o"
  "/root/ceph/src/os/kstore/kstore_types.cc" "/root/ceph/src/os/CMakeFiles/os.dir/kstore/kstore_types.cc.o"
  "/root/ceph/src/os/memstore/MemStore.cc" "/root/ceph/src/os/CMakeFiles/os.dir/memstore/MemStore.cc.o"
  )
set(CMAKE_CXX_COMPILER_ID "GNU")

# Preprocessor definitions for this target.
set(CMAKE_TARGET_DEFINITIONS_CXX
  "HAVE_CONFIG_H"
  "_FILE_OFFSET_BITS=64"
  "_GNU_SOURCE"
  "_REENTRANT"
  "_THREAD_SAFE"
  "__CEPH__"
  "__STDC_FORMAT_MACROS"
  "__linux__"
  )

# The include file search paths:
set(CMAKE_CXX_TARGET_INCLUDE_PATH
  "boost/include"
  "src/include"
  "src"
  "include"
  "src/xxHash"
  "src/rapidjson/include"
  "src/fmt/include"
  "src/rocksdb/include"
  "/usr/include/fuse"
  )

# Targets to which this target links.
set(CMAKE_TARGET_LINKED_INFO_FILES
  "/root/ceph/src/blk/CMakeFiles/blk.dir/DependInfo.cmake"
  "/root/ceph/src/perfglue/CMakeFiles/heap_profiler.dir/DependInfo.cmake"
  "/root/ceph/src/kv/CMakeFiles/kv.dir/DependInfo.cmake"
  )

# Fortran module output directory.
set(CMAKE_Fortran_TARGET_MODULE_DIR "")
