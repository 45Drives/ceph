
# FKH start (FKHENC)

add_executable(FKHENC encrypt.cc)
install(TARGETS FKHENC DESTINATION bin)
target_link_libraries(FKHENC  global ceph-common ${CRYPTO_LIBS})



message(STATUS "@@@@@@@@@@@@@@@@@@@ ${FKHENC} @@@@@@@@@@@@@@@@@@@")


# FKH end (FKHENC)
