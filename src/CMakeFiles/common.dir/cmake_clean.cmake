file(REMOVE_RECURSE
  "../lib/libcommon.pdb"
  "../lib/libcommon.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang C CXX)
  include(CMakeFiles/common.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
