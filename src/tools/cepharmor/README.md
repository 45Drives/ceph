


This API adds cryptography functionality to the Ceph cluster through the "CephArmor" API. 

Instruction:

Clone "CephArmor" branch, follow the repository install instruction and deploy a Ceph cluster. 



For storing an encrypted file, try the following command:

 "CephArmor put object_name file_name -p pool_name"

This command, stores a file encrypted into an object of the specified pool through the "CephArmor" API.




File retreival:

"CephArmor get object_name file_name -p pool_name"

This command retrieves a file, decrypts, and store into the specified file_name.



WARNING! At this point, 4MB is the maximum size of the file for encryption. Please check your file size before applying the API. 





___________________________________________________________________________________

{SUMMARY OF THE EXPERIMENTS REPORTED}
		
		The proposed method has been examined over servers with hardware and cluster specifications represented in the experiments section of the paper. Ceph integrates all three servers and provides a uniform namespace. The following steps represent the whole simulating procedure. The following Github account has been generated to provide the paper artifacts, including two repositories, ceph and cepharmor. The former contains the source code and the latter the API details. \url{https://github.com/cepharmor} 
		
		{Step 1:} Install the Ceph Pacific version.
		 
		To simulate the experiment environment, clone the ceph repository from the provided Github address and proceed to install the software on any number of servers. NOTE: The single server Ceph installation and deployment differ from the multiple models. Please refer to the Ceph documentation to access the proper instruction according to the hardware/ configuration. 
		
		{Step 2:} Deploy Ceph on servers through containerized deployment. 
		
		Having installed the Pacific version of Ceph, proceed to the cluster setup step according to the Ceph documentation. Containerized deployment is supported through Podman or Docker. Proceed with the provided instruction on the following link to deploy the installed application on all servers. (\url{https://docs.ceph.com/en/latest/cephadm/install/})
		NOTE: Change the crush rule from host to OSD before adding OSDs step.
		
		
		{Step 3:} Define pool and placement groups as explained in the paper’s “cluster environment” section. 
		
		{Step 4:} Set replicated/EC pool size/configuration according to the experimental environment.
		
		{Step 5:} Store encrypted data into the created pool.
		
		By the following instructions, data are stored encrypted into the cluster. Removing the \texttt{--enc-bench}  parameter helps us to store data normally, without encryption, into the cluster. The same rule applies for the read instruction. 
		
							
						
						
		
		$ CephArmor bench 100 write -b $message_size -t $thread -p pool_name --max-objects 1000  --no-cleanup --enc-bench
		

							
							\textbf{Step 6:} Retrieve the encrypted data from the pool.
							
							Sequential read: 

		$ CephArmor bench 100 seq -t $thread -p pool_name --max-objects 1000 --enc-bench
		
							
							Random read:
		
		$ CephArmor bench 100 rand -t $thread -p pool_name --max-objects 1000 --enc-bench
		

