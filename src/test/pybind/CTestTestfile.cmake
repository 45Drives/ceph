# CMake generated Testfile for 
# Source directory: /root/ceph/src/test/pybind
# Build directory: /root/ceph/src/test/pybind
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_ceph_daemon.py "/root/ceph/src/test/pybind/test_ceph_daemon.py")
set_tests_properties(test_ceph_daemon.py PROPERTIES  ENVIRONMENT "CEPH_ROOT=/root/ceph;CEPH_BIN=/root/ceph/bin;CEPH_LIB=/root/ceph/lib;CEPH_BUILD_DIR=/root/ceph;LD_LIBRARY_PATH=/root/ceph/lib;PATH=/root/ceph/bin:/root/ceph/src:/usr/lib64/ccache:/usr/local/sbin:/sbin:/bin:/usr/sbin:/usr/bin:/var/lib/snapd/snap/bin:/usr/local/lib/node_modules/@angular/cli/bin:/root/bin;PYTHONPATH=/root/ceph/lib/cython_modules/lib.3:/root/ceph/src/pybind;CEPH_BUILD_VIRTUALENV=/root/ceph" TIMEOUT "3600")
add_test(test_ceph_argparse.py "/root/ceph/src/test/pybind/test_ceph_argparse.py")
set_tests_properties(test_ceph_argparse.py PROPERTIES  ENVIRONMENT "CEPH_ROOT=/root/ceph;CEPH_BIN=/root/ceph/bin;CEPH_LIB=/root/ceph/lib;CEPH_BUILD_DIR=/root/ceph;LD_LIBRARY_PATH=/root/ceph/lib;PATH=/root/ceph/bin:/root/ceph/src:/usr/lib64/ccache:/usr/local/sbin:/sbin:/bin:/usr/sbin:/usr/bin:/var/lib/snapd/snap/bin:/usr/local/lib/node_modules/@angular/cli/bin:/root/bin;PYTHONPATH=/root/ceph/lib/cython_modules/lib.3:/root/ceph/src/pybind;CEPH_BUILD_VIRTUALENV=/root/ceph" TIMEOUT "3600")
