add_executable(ceph-erasure-code-tool
  ${PROJECT_SOURCE_DIR}/src/osd/ECUtil.cc
  ceph-erasure-code-tool.cc)


#   find_library(LIBBOX2D Box2D DIRECTORY)
  find_library(libcrypto crypto /libs/)
  find_library(libssl ssl /libs/)


target_link_libraries(ceph-erasure-code-tool global ceph-common libcrypto libssl)
install(TARGETS ceph-erasure-code-tool DESTINATION bin)
