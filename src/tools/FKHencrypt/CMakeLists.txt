
set(OPENSSL_USE_STATIC_LIBS TRUE)
set(CMAKE_CXX_FLAGS "-std=gnu++11 -ggdb")

find_package(OpenSSL REQUIRED)


add_executable(FKHENC FKHENC.cc encrypt.cc )

target_link_libraries(FKHENC  global librados ceph-common OpenSSL::Crypto OpenSSL::SSL #${OpenSSL_LIB} 
 )

if(WITH_LIBRADOSSTRIPER)
  target_link_libraries(FKHENC radosstriper)
else()
  target_link_libraries(FKHENC cls_lock_client)
endif()
install(TARGETS FKHENC DESTINATION bin)




message(STATUS " -----------------------[ FKHENC API ]------------------------ ")


