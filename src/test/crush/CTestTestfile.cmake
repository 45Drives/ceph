# CMake generated Testfile for 
# Source directory: /root/ceph/src/test/crush
# Build directory: /root/ceph/src/test/crush
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(unittest_crush_wrapper "/root/ceph/bin/unittest_crush_wrapper")
set_tests_properties(unittest_crush_wrapper PROPERTIES  ENVIRONMENT "CEPH_ROOT=/root/ceph;CEPH_BIN=/root/ceph/bin;CEPH_LIB=/root/ceph/lib;CEPH_BUILD_DIR=/root/ceph;LD_LIBRARY_PATH=/root/ceph/lib;PATH=/root/ceph/bin:/root/ceph/src:/usr/lib64/ccache:/usr/local/sbin:/sbin:/bin:/usr/sbin:/usr/bin:/var/lib/snapd/snap/bin:/usr/local/lib/node_modules/@angular/cli/bin:/root/bin;PYTHONPATH=/root/ceph/lib/cython_modules/lib.3:/root/ceph/src/pybind;CEPH_BUILD_VIRTUALENV=/root/ceph" TIMEOUT "3600")
add_test(unittest_crush "/root/ceph/bin/unittest_crush")
set_tests_properties(unittest_crush PROPERTIES  ENVIRONMENT "CEPH_ROOT=/root/ceph;CEPH_BIN=/root/ceph/bin;CEPH_LIB=/root/ceph/lib;CEPH_BUILD_DIR=/root/ceph;LD_LIBRARY_PATH=/root/ceph/lib;PATH=/root/ceph/bin:/root/ceph/src:/usr/lib64/ccache:/usr/local/sbin:/sbin:/bin:/usr/sbin:/usr/bin:/var/lib/snapd/snap/bin:/usr/local/lib/node_modules/@angular/cli/bin:/root/bin;PYTHONPATH=/root/ceph/lib/cython_modules/lib.3:/root/ceph/src/pybind;CEPH_BUILD_VIRTUALENV=/root/ceph" TIMEOUT "3600")
add_test(crush_weights.sh "/root/ceph/src/test/crush/crush_weights.sh")
set_tests_properties(crush_weights.sh PROPERTIES  ENVIRONMENT "CEPH_ROOT=/root/ceph;CEPH_BIN=/root/ceph/bin;CEPH_LIB=/root/ceph/lib;CEPH_BUILD_DIR=/root/ceph;LD_LIBRARY_PATH=/root/ceph/lib;PATH=/root/ceph/bin:/root/ceph/src:/usr/lib64/ccache:/usr/local/sbin:/sbin:/bin:/usr/sbin:/usr/bin:/var/lib/snapd/snap/bin:/usr/local/lib/node_modules/@angular/cli/bin:/root/bin;PYTHONPATH=/root/ceph/lib/cython_modules/lib.3:/root/ceph/src/pybind;CEPH_BUILD_VIRTUALENV=/root/ceph" TIMEOUT "3600")
