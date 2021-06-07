


This API adds cryptography functionality to the Ceph cluser through "FKHENC" API. 

Instruction:

Clone "fkhpacific" branch, follow the repository install instruction, afterward deploy a Ceph cluster. 
For storig a file encrypted, try following command:

 "FKHENC put object1 file1 -p pool01"

This command, stores the "file1" encrypted into the "object1" of "pool01"  through "FKHENC" API.





[IMPORTANT WARNING] The library is still in the development stage and errors are not  comprehensively handled! 
It also requires testing to validate the functionality, security, and performance.