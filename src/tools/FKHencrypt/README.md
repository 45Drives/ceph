


This library adds cryptography functionality to Ceph cluser through "rados" API. 

Instruction:

Clone "fkhpacific" git repository, install and deploy Ceph cluster. The "put-enc" keyword stores file encrypted in the cluster. 

Example: the following command stores the "file.txt" encrypted into testpool through object1

rados put-enc object1 file.txt -p testpool



