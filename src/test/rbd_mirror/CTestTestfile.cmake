# CMake generated Testfile for 
# Source directory: /root/ceph/src/test/rbd_mirror
# Build directory: /root/ceph/src/test/rbd_mirror
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(unittest_rbd_mirror "/root/ceph/bin/unittest_rbd_mirror")
set_tests_properties(unittest_rbd_mirror PROPERTIES  ENVIRONMENT "CEPH_ROOT=/root/ceph;CEPH_BIN=/root/ceph/bin;CEPH_LIB=/root/ceph/lib;CEPH_BUILD_DIR=/root/ceph;LD_LIBRARY_PATH=/root/ceph/lib;PATH=/root/ceph/bin:/root/ceph/src:/usr/lib64/ccache:/usr/local/sbin:/sbin:/bin:/usr/sbin:/usr/bin:/var/lib/snapd/snap/bin:/usr/local/lib/node_modules/@angular/cli/bin:/root/bin;PYTHONPATH=/root/ceph/lib/cython_modules/lib.3:/root/ceph/src/pybind;CEPH_BUILD_VIRTUALENV=/root/ceph" TIMEOUT "3600")
