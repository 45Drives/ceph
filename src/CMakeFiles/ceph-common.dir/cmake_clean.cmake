file(REMOVE_RECURSE
  "../lib/libceph-common.pdb"
  "../lib/libceph-common.so.2"
  "../lib/libceph-common.so"
)

# Per-language clean rules from dependency scanning.
foreach(lang C CXX)
  include(CMakeFiles/ceph-common.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
