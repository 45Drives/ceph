

set(OPENSSL_USE_STATIC_LIBS TRUE)
set(CMAKE_CXX_FLAGS "-std=gnu++11 -g -ggdb -O0")

find_package(OpenSSL REQUIRED)


add_executable(CephArmor CephArmor.cc Crypt.cc KMS.cc ${PROJECT_SOURCE_DIR}/src/common/obj_bencher.cc)



target_link_libraries(CephArmor global librados ceph-common OpenSSL::Crypto OpenSSL::SSL )

if(WITH_LIBRADOSSTRIPER)
  target_link_libraries(CephArmor radosstriper)
else()
  target_link_libraries(CephArmor cls_lock_client)
endif()

install(TARGETS CephArmor DESTINATION bin)




message(STATUS " -----------------------[ CephArmor API ]------------------------ ")


