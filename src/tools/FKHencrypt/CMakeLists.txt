
# FKH start (FKHENC)

#   find_library(LIBBOX2D Box2D DIRECTORY)
# find_library(libcrypto crypto ${CMAKE_CURRENT_SOURCE_DIR}/libs/)
# find_library(libssl ssl ${CMAKE_CURRENT_SOURCE_DIR}/libs/)

find_library(OpenSSL_LIB  libcrypto.a libssl.a)
find_package(OpenSSL)

add_executable(FKHENC test_enc.cc encrypt.cc)
install(TARGETS FKHENC DESTINATION bin)
target_link_libraries(FKHENC  global ceph-common ${OpenSSL_LIB}  )



message(STATUS "@@@@@@@@@@@@@@@@@@@ ${FKHENC} @@@@@@@@@@@@@@@@@@@")


# FKH end (FKHENC)
