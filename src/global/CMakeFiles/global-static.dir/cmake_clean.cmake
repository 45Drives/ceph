file(REMOVE_RECURSE
  "../../lib/libglobal-static.pdb"
  "../../lib/libglobal-static.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/global-static.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
