


This API adds cryptography functionality to the Ceph cluster through the “CephArmor” API. 

Instruction:

Clone the cepharmor branch, follow the Ceph repository install instruction and deploy a Ceph cluster. 
Add the “cepharmor” folder to the src/tools direction and enjoy the encrypted storage. 




For storing an encrypted file, try the following command:

 CephArmor put object_name file_name -p pool_name --pass insert_a_pass

This command stores a file encrypted into an object of the specified pool through the “CephArmor” API.




File retrieval:

CephArmor get object_name file_name -p pool_name --pass insert_the_pass

NOTE: The pass phrase must be the same as the encryption pass

This command retrieves a file, decrypts it, and stores it into the specified file_name.





___________________________________________________________________________________

{SUMMARY OF THE EXPERIMENTS REPORTED}
 
 The proposed method has been examined over servers with hardware and cluster specifications represented in the experiments section of the SC paper. Ceph integrates all three servers and provides a uniform namespace. The following steps represent the whole simulation procedure. 
 
 {Step 1:} Install the Ceph Pacific version.
 
 To simulate the experiment environment, clone the Ceph repository from the provided Github address and proceed to install the cepharmor branch on any number of servers. NOTE: The single server Ceph installation and deployment differ from the multiple models. Please refer to the Ceph documentation to access the proper instruction according to the hardware/configuration. 
 
 {Step 2:} Deploy Ceph on servers through containerized deployment. 
 
 Having installed the cepharmor branch, proceed to the cluster setup step according to the Ceph documentation. Containerized deployment is supported through Podman or Docker. Proceed with the following link’s instructions to deploy the installed application on all servers. (\url{https://docs.ceph.com/en/latest/cephadm/install/})
 Note: Change the crush rule from host to OSD before adding OSDs in one server setting.
 
 
 {Step 3:} Define pool and placement groups as explained in the paper’s “cluster environment” section. 
 
 {Step 4:} Set replicated/EC pool size/configuration according to the experimental environment.
 
 {Step 5:} Store encrypted data into the created pool.
 
 Following instructions are used for benchmarking. The --enc-bench parameter stores data encrypted into the cluster. The same rule applies to the read instruction. 
 
 
 
 
 
 $ CephArmor bench 100 write -b $message_size -t $thread -p pool_name --max-objects 1000 --no-cleanup --enc-bench
 

 
 \textbf{Step 6:} Retrieve the encrypted data from the pool.
 
 Sequential read: 

 $ CephArmor bench 100 seq -t $thread -p pool_name --max-objects 1000 --enc-bench
 
 
 Random read:
 
 $ CephArmor bench 100 rand -t $thread -p pool_name --max-objects 1000 --enc-bench
 

