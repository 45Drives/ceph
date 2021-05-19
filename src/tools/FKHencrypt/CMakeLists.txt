
set(OPENSSL_USE_STATIC_LIBS TRUE)
find_package(OpenSSL REQUIRED)


add_executable(FKHENC test_enc.cc encrypt.cc)
install(TARGETS FKHENC DESTINATION bin)
target_link_libraries(FKHENC  global ceph-common OpenSSL::Crypto OpenSSL::SSL #${OpenSSL_LIB} 
 )



message(STATUS "@@@@@@@@@@@@@@@@@@@ ${FKHENC} @@@@@@@@@@@@@@@@@@@")


