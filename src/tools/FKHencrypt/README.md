


This API adds cryptography functionality to the Ceph cluster through the "FKHENC" API. 

Instruction:

Clone "fkhpacific" branch, follow the repository install instruction and deploy a Ceph cluster. 



For storing an encrypted file, try the following command:

 "FKHENC put object_name file_name -p pool_name"

This command, stores a file encrypted into an object of the specified pool through the "FKHENC" API.




File retreival:

"FKHENC get object_name file_name -p pool_name"

This command retrieves a file, decrypts, and store into the specified file_name.



WARNING! At this point, 4MB is the maximum size of the file for encryption. Please check your file size before applying the API. 