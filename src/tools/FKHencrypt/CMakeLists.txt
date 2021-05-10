
# FKH start (FKHENC)

add_executable(FKHENC test_enc.cc encrypt.cc)
install(TARGETS FKHENC DESTINATION bin)
target_link_libraries(FKHENC  global ceph-common ${CRYPTO_LIBS})



message(STATUS "@@@@@@@@@@@@@@@@@@@ ${FKHENC} @@@@@@@@@@@@@@@@@@@")


# FKH end (FKHENC)
