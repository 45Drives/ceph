# CMake generated Testfile for 
# Source directory: /root/ceph/src/test/ObjectMap
# Build directory: /root/ceph/src/test/ObjectMap
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(ceph_test_object_map "/root/ceph/bin/ceph_test_object_map")
set_tests_properties(ceph_test_object_map PROPERTIES  ENVIRONMENT "CEPH_ROOT=/root/ceph;CEPH_BIN=/root/ceph/bin;CEPH_LIB=/root/ceph/lib;CEPH_BUILD_DIR=/root/ceph;LD_LIBRARY_PATH=/root/ceph/lib;PATH=/root/ceph/bin:/root/ceph/src:/usr/lib64/ccache:/usr/local/sbin:/sbin:/bin:/usr/sbin:/usr/bin:/var/lib/snapd/snap/bin:/usr/local/lib/node_modules/@angular/cli/bin:/root/bin;PYTHONPATH=/root/ceph/lib/cython_modules/lib.3:/root/ceph/src/pybind;CEPH_BUILD_VIRTUALENV=/root/ceph" TIMEOUT "3600")
