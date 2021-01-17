# Install script for directory: /root/ceph/src/cls

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_sdk.so.1.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_sdk.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_sdk.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/rados-classes" TYPE SHARED_LIBRARY FILES
    "/root/ceph/lib/libcls_sdk.so.1.0.0"
    "/root/ceph/lib/libcls_sdk.so.1"
    "/root/ceph/lib/libcls_sdk.so"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_sdk.so.1.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_sdk.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_sdk.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_hello.so.1.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_hello.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_hello.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/rados-classes" TYPE SHARED_LIBRARY FILES
    "/root/ceph/lib/libcls_hello.so.1.0.0"
    "/root/ceph/lib/libcls_hello.so.1"
    "/root/ceph/lib/libcls_hello.so"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_hello.so.1.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_hello.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_hello.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_numops.so.1.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_numops.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_numops.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/rados-classes" TYPE SHARED_LIBRARY FILES
    "/root/ceph/lib/libcls_numops.so.1.0.0"
    "/root/ceph/lib/libcls_numops.so.1"
    "/root/ceph/lib/libcls_numops.so"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_numops.so.1.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_numops.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_numops.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_rbd.so.1.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_rbd.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_rbd.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/rados-classes" TYPE SHARED_LIBRARY FILES
    "/root/ceph/lib/libcls_rbd.so.1.0.0"
    "/root/ceph/lib/libcls_rbd.so.1"
    "/root/ceph/lib/libcls_rbd.so"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_rbd.so.1.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_rbd.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_rbd.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_lock.so.1.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_lock.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_lock.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/rados-classes" TYPE SHARED_LIBRARY FILES
    "/root/ceph/lib/libcls_lock.so.1.0.0"
    "/root/ceph/lib/libcls_lock.so.1"
    "/root/ceph/lib/libcls_lock.so"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_lock.so.1.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_lock.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_lock.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_otp.so.1.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_otp.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_otp.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/rados-classes" TYPE SHARED_LIBRARY FILES
    "/root/ceph/lib/libcls_otp.so.1.0.0"
    "/root/ceph/lib/libcls_otp.so.1"
    "/root/ceph/lib/libcls_otp.so"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_otp.so.1.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_otp.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_otp.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_refcount.so.1.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_refcount.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_refcount.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/rados-classes" TYPE SHARED_LIBRARY FILES
    "/root/ceph/lib/libcls_refcount.so.1.0.0"
    "/root/ceph/lib/libcls_refcount.so.1"
    "/root/ceph/lib/libcls_refcount.so"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_refcount.so.1.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_refcount.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_refcount.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_version.so.1.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_version.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_version.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/rados-classes" TYPE SHARED_LIBRARY FILES
    "/root/ceph/lib/libcls_version.so.1.0.0"
    "/root/ceph/lib/libcls_version.so.1"
    "/root/ceph/lib/libcls_version.so"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_version.so.1.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_version.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_version.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_log.so.1.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_log.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_log.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/rados-classes" TYPE SHARED_LIBRARY FILES
    "/root/ceph/lib/libcls_log.so.1.0.0"
    "/root/ceph/lib/libcls_log.so.1"
    "/root/ceph/lib/libcls_log.so"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_log.so.1.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_log.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_log.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_timeindex.so.1.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_timeindex.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_timeindex.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/rados-classes" TYPE SHARED_LIBRARY FILES
    "/root/ceph/lib/libcls_timeindex.so.1.0.0"
    "/root/ceph/lib/libcls_timeindex.so.1"
    "/root/ceph/lib/libcls_timeindex.so"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_timeindex.so.1.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_timeindex.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_timeindex.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_user.so.1.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_user.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_user.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/rados-classes" TYPE SHARED_LIBRARY FILES
    "/root/ceph/lib/libcls_user.so.1.0.0"
    "/root/ceph/lib/libcls_user.so.1"
    "/root/ceph/lib/libcls_user.so"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_user.so.1.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_user.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_user.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_journal.so.1.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_journal.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_journal.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/rados-classes" TYPE SHARED_LIBRARY FILES
    "/root/ceph/lib/libcls_journal.so.1.0.0"
    "/root/ceph/lib/libcls_journal.so.1"
    "/root/ceph/lib/libcls_journal.so"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_journal.so.1.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_journal.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_journal.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_rgw.so.1.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_rgw.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_rgw.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/rados-classes" TYPE SHARED_LIBRARY FILES
    "/root/ceph/lib/libcls_rgw.so.1.0.0"
    "/root/ceph/lib/libcls_rgw.so.1"
    "/root/ceph/lib/libcls_rgw.so"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_rgw.so.1.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_rgw.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_rgw.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_cephfs.so.1.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_cephfs.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_cephfs.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/rados-classes" TYPE SHARED_LIBRARY FILES
    "/root/ceph/lib/libcls_cephfs.so.1.0.0"
    "/root/ceph/lib/libcls_cephfs.so.1"
    "/root/ceph/lib/libcls_cephfs.so"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_cephfs.so.1.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_cephfs.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_cephfs.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_lua.so.1.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_lua.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_lua.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/rados-classes" TYPE SHARED_LIBRARY FILES
    "/root/ceph/lib/libcls_lua.so.1.0.0"
    "/root/ceph/lib/libcls_lua.so.1"
    "/root/ceph/lib/libcls_lua.so"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_lua.so.1.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_lua.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_lua.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_cas.so.1.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_cas.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_cas.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/rados-classes" TYPE SHARED_LIBRARY FILES
    "/root/ceph/lib/libcls_cas.so.1.0.0"
    "/root/ceph/lib/libcls_cas.so.1"
    "/root/ceph/lib/libcls_cas.so"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_cas.so.1.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_cas.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_cas.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_queue.so.1.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_queue.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_queue.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/rados-classes" TYPE SHARED_LIBRARY FILES
    "/root/ceph/lib/libcls_queue.so.1.0.0"
    "/root/ceph/lib/libcls_queue.so.1"
    "/root/ceph/lib/libcls_queue.so"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_queue.so.1.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_queue.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_queue.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_rgw_gc.so.1.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_rgw_gc.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_rgw_gc.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/rados-classes" TYPE SHARED_LIBRARY FILES
    "/root/ceph/lib/libcls_rgw_gc.so.1.0.0"
    "/root/ceph/lib/libcls_rgw_gc.so.1"
    "/root/ceph/lib/libcls_rgw_gc.so"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_rgw_gc.so.1.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_rgw_gc.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_rgw_gc.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_2pc_queue.so.1.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_2pc_queue.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_2pc_queue.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/rados-classes" TYPE SHARED_LIBRARY FILES
    "/root/ceph/lib/libcls_2pc_queue.so.1.0.0"
    "/root/ceph/lib/libcls_2pc_queue.so.1"
    "/root/ceph/lib/libcls_2pc_queue.so"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_2pc_queue.so.1.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_2pc_queue.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/rados-classes/libcls_2pc_queue.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/root/ceph/src/cls/cmpomap/cmake_install.cmake")

endif()

