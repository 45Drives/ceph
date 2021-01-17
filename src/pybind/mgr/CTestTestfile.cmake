# CMake generated Testfile for 
# Source directory: /root/ceph/src/pybind/mgr
# Build directory: /root/ceph/src/pybind/mgr
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(run-tox-mgr "/root/ceph/src/script/run_tox.sh" "--source-dir" "/root/ceph" "--build-dir" "/root/ceph" "--tox-path" "/root/ceph/src/pybind/mgr" "--tox-envs" "py3,mypy" "--venv-path" "/root/ceph/mgr-virtualenv")
set_tests_properties(run-tox-mgr PROPERTIES  ENVIRONMENT "CEPH_ROOT=/root/ceph;CEPH_BIN=/root/ceph/bin;CEPH_LIB=/root/ceph/lib;CEPH_BUILD_VIRTUALENV=/root/ceph;LD_LIBRARY_PATH=/root/ceph/lib;PATH=/root/ceph/bin:/root/ceph/src:/usr/lib64/ccache:/usr/local/sbin:/sbin:/bin:/usr/sbin:/usr/bin:/var/lib/snapd/snap/bin:/usr/local/lib/node_modules/@angular/cli/bin:/root/bin;PYTHONPATH=/root/ceph/src/pybind")
subdirs("dashboard")
subdirs("rook")
