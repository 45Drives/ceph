file(REMOVE_RECURSE
  "../../lib/libglobal.pdb"
  "../../lib/libglobal.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/global.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
