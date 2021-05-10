
# FKH start (FKHENC)

#   find_library(LIBBOX2D Box2D DIRECTORY)
find_library(libcrypto crypto /libs/)
find_library(libssl ssl /libs/)



add_executable(FKHENC test_enc.cc encrypt.cc)
install(TARGETS FKHENC DESTINATION bin)
target_link_libraries(FKHENC  global ceph-common ${CRYPTO_LIBS} libcrypto libssl)



message(STATUS "@@@@@@@@@@@@@@@@@@@ ${FKHENC} @@@@@@@@@@@@@@@@@@@")


# FKH end (FKHENC)
