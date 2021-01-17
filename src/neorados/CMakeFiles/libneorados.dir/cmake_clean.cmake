file(REMOVE_RECURSE
  "../../lib/liblibneorados.pdb"
  "../../lib/liblibneorados.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/libneorados.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
