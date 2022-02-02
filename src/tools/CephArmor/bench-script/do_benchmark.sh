

    # write benchmark Ceph API (without encryption) 
    # for thread in 1  2  4  8  16 
    # do
    #     echo "------------------------- Thread $thread -------------------------------------"
    #     for message_size in 125K 256K 512K 1M 2M 3M 4M
    #     do
    #         echo "------------------------- Message_size $message_size -------------------------------------"
            # for iteration in 1 2 3 4 5 6 7 8 9 10
            # do
            # echo "CephArmor bench 500 write -b $message_size -t $thread -p benchpool --no-cleanup --max-objects 1000"
            # CephArmor bench 500 write -b $message_size -t $thread -p benchpool --no-cleanup --max-objects 1000
            # done
    #     done
    # done


    
    #----------------------------------------------------------------------------------------------------------


 # for thread in 1  2  4  8  16 
    # do
    #     echo "------------------------- Thread $thread -------------------------------------"
    #     for message_size in 125K 256K 512K 1M 2M 3M 4M
    #     do
    #         echo "------------------------- Message_size $message_size -------------------------------------"
            # for iteration in 1 2 3 4 5 6 7 8 9 10
            # do
            # echo "CephArmor bench 60 write -b $message_size -t $thread -p benchpool --no-cleanup"
            # CephArmor bench 500 write -b $message_size -t $thread -p benchpool --no-cleanup --max-objects 1000
            # done
    #     done
    # done

    #----------------------------------------------------------------------------------------------------------

       
    
    #----------------------------------------------------------------------------------------------------------

     # read benchmark Ceph API (with encryption) 
    #  for thread in 2  4  8  16
    #  do
    #     echo "------------------------- Thread $thread -------------------------------------"
    #     for iteration in 1 2 3 4 5 6 7 8 9 10
    #     do
    #     echo "CephArmor bench -p benchpool 60 seq -t $thread"
    #     CephArmor bench -p  benchpool 60 seq -t $thread
    #     done
    #  done

 #----------------------------------------------------------------------------------------------------------

    #  read benchmark Ceph API (with encryption) 
   #   for thread in 2  4  8  16
   #   do
   #      echo "------------------------- Thread $thread -------------------------------------"
   #      for iteration in 1 2 3 4 5 6 7 8 9 10
   #      do
   #      echo "CephArmor bench -p benchpool 60 rand -t $thread "
   #      CephArmor bench -p benchpool 60 rand -t $thread
   #      done
   #   done

    
 #----------------------------------------------------------------------------------------------------------


#   read benchmark Ceph API (with encryption) 
    #  for thread in 2  4  8  16
    #  do
    #     echo "------------------------- Thread $thread -------------------------------------"
    #     for iteration in 1 2 3 4 5 6 7 8 9 10
    #     do
    #     echo "CephArmor bench -p benchpool 60 seq -t $thread --enc-bench"
    #     CephArmor bench -p benchpool 60 seq -t $thread --enc-bench
    #     done
    #  done

 #----------------------------------------------------------------------------------------------------------

   # for thread in 2  4  8  16
   #   do
   #      echo "------------------------- Thread $thread -------------------------------------"
   #      for iteration in 1 2 3 4 5 6 7 8 9 10
   #      do
   #      echo "CephArmor bench -p benchpool 60 rand -t $thread --enc-bench"
   #      CephArmor bench -p benchpool 60 rand -t $thread --enc-bench
   #      done
   #   done






    #  CephArmor bench -p freepool 3 seq
    #  CephArmor bench -p freepool 3 rand

    #  CephArmor bench 1000 write -p freepool --no-cleanup

         #         CephArmor bench 5000 write  -p testpool --no-cleanup
        #   CephArmor bench 10 write  -p testpool --no-cleanup  --enc-bench --max-objects 1000
        # CephArmor bench -p benchpool 5 rand --enc-bench

            # CephArmor bench 500 write -b 4M -t 1 -p benchpool --no-cleanup  --max-objects 1000 --enc-bench

            # CephArmor bench 10 write -b 4M -t 1 -p benchpool --no-cleanup --enc-bench
 #----------------------------------------------------------------------------------------------------------


# ----------------------------- benchmark AES Encryption and Decryptipn time -------------------------------



# CephArmor bench -p benchpool 5 write -t 1 --max-objects 1 -b 1K --enc-bench
# CephArmor bench -p benchpool 5 write -t 1 --max-objects 1 -b 2K --enc-bench
# CephArmor bench -p benchpool 5 write -t 1 --max-objects 1 -b 4K --enc-bench
# CephArmor bench -p benchpool 5 write -t 1 --max-objects 1 -b 8K --enc-bench
# CephArmor bench -p benchpool 5 write -t 1 --max-objects 1 -b 16K --enc-bench
# CephArmor bench -p benchpool 5 write -t 1 --max-objects 1 -b 32K --enc-bench
# CephArmor bench -p benchpool 5 write -t 1 --max-objects 1 -b 64K --enc-bench
# CephArmor bench -p benchpool 5 write -t 1 --max-objects 1 -b 128K --enc-bench
# CephArmor bench -p benchpool 5 write -t 1 --max-objects 1 -b 256K --enc-bench
# CephArmor bench -p benchpool 5 write -t 1 --max-objects 1 -b 512K --enc-bench
# CephArmor bench -p benchpool 5 write -t 1 --max-objects 1 -b 1M --enc-bench
# CephArmor bench -p benchpool 5 write -t 1 --max-objects 1 -b 2M --enc-bench
# CephArmor bench -p benchpool 5 write -t 1 --max-objects 1 -b 3M --enc-bench
# CephArmor bench -p benchpool 5 write -t 1 --max-objects 1 -b 4M --enc-bench





            #    Multi-Server-Constant-Object
            #    keep size of object constant, change thread and object size
            # ------------------------------------- WRITE (per thread) -------------------------------------
            # CephArmor bench 1000 write -b 4M -t 1 -p benchpool --no-cleanup --max-objects 1000
            # CephArmor bench 2000 write -b 4M -t 2 -p benchpool --no-cleanup --max-objects 2000
            # CephArmor bench 4000 write -b 4M -t 4 -p benchpool --no-cleanup --max-objects 4000
            # CephArmor bench 8000 write -b 4M -t 8 -p benchpool --no-cleanup --max-objects 8000
            # CephArmor bench 16000 write -b 4M -t 16 -p benchpool --no-cleanup --max-objects 16000


            # CephArmor bench 1000 write -b 4M -t 1 -p benchpool --no-cleanup --max-objects 1000 --enc-bench
            # CephArmor bench 2000 write -b 4M -t 2 -p benchpool --no-cleanup --max-objects 2000 --enc-bench
            # CephArmor bench 4000 write -b 4M -t 4 -p benchpool --no-cleanup --max-objects 4000 --enc-bench
            # CephArmor bench 8000 write -b 4M -t 8 -p benchpool --no-cleanup --max-objects 8000 --enc-bench
            # CephArmor bench 16000 write -b 4M -t 16 -p benchpool --no-cleanup --max-objects 16000 --enc-bench
            # ------------------------------------- WRITE (1000 Object in general) -------------------------------------
            # CephArmor bench 2000 write -b 4M -t 1 -p benchpool --no-cleanup --max-objects 1000 --enc-bench
            # CephArmor bench 2000 write -b 4M -t 2 -p benchpool --no-cleanup --max-objects 1000 --enc-bench
            # CephArmor bench 2000 write -b 4M -t 4 -p benchpool --no-cleanup --max-objects 1000 --enc-bench
            # CephArmor bench 2000 write -b 4M -t 8 -p benchpool --no-cleanup --max-objects 1000 --enc-bench
            # CephArmor bench 2000 write -b 4M -t 16 -p benchpool --no-cleanup --max-objects 1000 --enc-bench


            # CephArmor bench 2000 write -b 4M -t 1 -p benchpool --no-cleanup --max-objects 1000  
            # CephArmor bench 2000 write -b 4M -t 2 -p benchpool --no-cleanup --max-objects 1000  
            # CephArmor bench 2000 write -b 4M -t 4 -p benchpool --no-cleanup --max-objects 1000  
            # CephArmor bench 2000 write -b 4M -t 8 -p benchpool --no-cleanup --max-objects 1000  
            # CephArmor bench 2000 write -b 4M -t 16 -p benchpool --no-cleanup --max-objects 1000 








            # ------------------------------------- READ (sequential) (per thread) -------------------------------------
            # for i in 1 2 3 4 5 6 7 8 9 10:
            # do
            #     CephArmor bench 1000 seq -t 1 -p testpool --max-objects 1000
            # done

            # for i in 1 2 3 4 5 6 7 8 9 10:
            # do
            #     CephArmor bench 2000 seq -t 2 -p testpool  --max-objects 2000
            # done

            # for i in 1 2 3 4 5 6 7 8 9 10:
            # do
            #     CephArmor bench 4000 seq -t 4 -p testpool  --max-objects 4000
            # done

            # for i in 1 2 3 4 5 6 7 8 9 10:
            # do
            #     CephArmor bench 8000 seq -t 8 -p testpool  --max-objects 8000
            # done

            # for i in 1 2 3 4 5 6 7 8 9 10:
            # do
            #     CephArmor bench 16000 seq -t 16 -p testpool  --max-objects 16000
            # done

            # CephArmor bench 1000 seq -t 1 -p testpool --max-objects 1000
            # CephArmor bench 2000 seq -t 2 -p testpool  --max-objects 2000
            # CephArmor bench 4000 seq -t 4 -p testpool  --max-objects 4000
            # CephArmor bench 8000 seq -t 8 -p testpool  --max-objects 8000
            # CephArmor bench 16000 seq -t 16 -p testpool  --max-objects 16000
 

# for i in 1 2 3 4 5 6 7 8 9 10:
# do
# CephArmor bench 1000 seq -t 1 -p testpool --max-objects 1000   --enc-bench
# done


# for i in 1 2 3 4 5 6 7 8 9 10:
# do
# CephArmor bench 2000 seq -t 2 -p testpool  --max-objects 2000  --enc-bench
# done


# for i in 1 2 3 4 5 6 7 8 9 10:
# do
# CephArmor bench 4000 seq -t 4 -p testpool  --max-objects 4000  --enc-bench
# done


# for i in 1 2 3 4 5 6 7 8 9 10:
# do
# CephArmor bench 8000 seq -t 8 -p testpool  --max-objects 8000  --enc-bench
# done


# for i in 1 2 3 4 5 6 7 8 9 10:
# do
# CephArmor bench 16000 seq -t 16 -p testpool  --max-objects 16000  --enc-bench
# done


            # CephArmor bench 1000 seq -t 1 -p testpool --max-objects 1000   --enc-bench
            # CephArmor bench 1000 seq -t 1 -p testpool --max-objects 1000   


            # CephArmor bench 2000 seq -t 2 -p testpool  --max-objects 2000  --enc-bench
            # CephArmor bench 2000 seq -t 2 -p testpool  --max-objects 2000  


            # CephArmor bench 4000 seq -t 4 -p testpool  --max-objects 4000  --enc-bench
            # CephArmor bench 4000 seq -t 4 -p testpool  --max-objects 4000  



            # CephArmor bench 8000 seq -t 8 -p testpool  --max-objects 8000  --enc-bench
            # CephArmor bench 8000 seq -t 8 -p testpool  --max-objects 8000  


            # CephArmor bench 16000 seq -t 16 -p testpool  --max-objects 16000  --enc-bench
            # CephArmor bench 16000 seq -t 16 -p testpool  --max-objects 16000

            # ------------------------------------- READ (random) (per thread) -------------------------------------

            # for i in 1 2 3 4 5 6 7 8 9 10:
            # do
            # CephArmor bench 1000 rand -t 1 -p testpool --max-objects 1000
            # done

            # for i in 1 2 3 4 5 6 7 8 9 10:
            # do
            # CephArmor bench 2000 rand -t 2 -p testpool  --max-objects 2000
            # done

            # for i in 1 2 3 4 5 6 7 8 9 10:
            # do
            # CephArmor bench 4000 rand -t 4 -p testpool  --max-objects 4000
            # done

            # for i in 1 2 3 4 5 6 7 8 9 10:
            # do
            #  CephArmor bench 8000 rand -t 8 -p testpool  --max-objects 8000
            # done

            # for i in 1 2 3 4 5 6 7 8 9 10:
            # do
            # CephArmor bench 16000 rand -t 16 -p testpool  --max-objects 16000
            # done


            # CephArmor bench 1000 rand -t 1 -p testpool --max-objects 1000 --enc-bench
            # CephArmor bench 1000 rand -t 1 -p testpool --max-objects 1000



            # CephArmor bench 2000 rand -t 2 -p testpool  --max-objects 2000 --enc-bench
            # CephArmor bench 2000 rand -t 2 -p testpool  --max-objects 2000



            # CephArmor bench 4000 rand -t 4 -p testpool  --max-objects 4000 --enc-bench
            # CephArmor bench 4000 rand -t 4 -p testpool  --max-objects 4000



            # CephArmor bench 8000 rand -t 8 -p testpool  --max-objects 8000  --enc-bench
            # CephArmor bench 8000 rand -t 8 -p testpool  --max-objects 8000


            # CephArmor bench 16000 rand -t 16 -p testpool  --max-objects 16000 --enc-bench
            # CephArmor bench 16000 rand -t 16 -p testpool  --max-objects 16000








            # for i in 1 2 3 4 5 6 7 8 9 10:
            # do 
            # CephArmor bench 1000 rand -t 1 -p testpool --max-objects 1000   --enc-bench
            # done

            # for i in 1 2 3 4 5 6 7 8 9 10:
            # do 
            # CephArmor bench 2000 rand -t 2 -p testpool  --max-objects 2000  --enc-bench
            # done


            # for i in 1 2 3 4 5 6 7 8 9 10:
            # do 
            # CephArmor bench 4000 rand -t 4 -p testpool  --max-objects 4000  --enc-bench
            # done


            # for i in 1 2 3 4 5 6 7 8 9 10:
            # do 
            # CephArmor bench 8000 rand -t 8 -p testpool  --max-objects 8000  --enc-bench
            # done

            # for i in 1 2 3 4 5 6 7 8 9 10:
            # do 
            # CephArmor bench 16000 rand -t 16 -p testpool  --max-objects 16000  --enc-bench
            # done

            # CephArmor bench 1000 rand -t 1 -p benchpool --max-objects 1000   --enc-bench
            # CephArmor bench 2000 rand -t 2 -p benchpool  --max-objects 2000  --enc-bench
            # CephArmor bench 4000 rand -t 4 -p benchpool  --max-objects 4000  --enc-bench
            # CephArmor bench 8000 rand -t 8 -p benchpool  --max-objects 8000  --enc-bench
            # CephArmor bench 16000 rand -t 16 -p benchpool  --max-objects 16000  --enc-bench


           #   ---------------------------------------------------------------------------------


 # ------------------------------------- READ (sequential) (1000 OBJECT TOTAL) -------------------------------------

            # for i in 1 2 3 4 5 6 7 8 9 10:
            # do 
            # CephArmor bench 1000 seq -t 1 -p benchpool --max-objects 1000
            # done

            # for i in 1 2 3 4 5 6 7 8 9 10:
            # do 
            # CephArmor bench 1000 seq -t 2 -p benchpool  --max-objects 1000
            # done

            # for i in 1 2 3 4 5 6 7 8 9 10:
            # do 
            # CephArmor bench 1000 seq -t 4 -p benchpool  --max-objects 1000
            # done

            # for i in 1 2 3 4 5 6 7 8 9 10:
            # do 
            # CephArmor bench 1000 seq -t 4 -p benchpool  --max-objects 1000
            # done

            # for i in 1 2 3 4 5 6 7 8 9 10:
            # do 
            #  CephArmor bench 1000 seq -t 8 -p benchpool  --max-objects 1000
            # done

            # for i in 1 2 3 4 5 6 7 8 9 10:
            # do 
            # CephArmor bench 1000  seq -t 16 -p benchpool  --max-objects 1000
            # done

            # CephArmor bench 1000 seq -t 1 -p benchpool --max-objects 1000
            # CephArmor bench 1000 seq -t 2 -p benchpool  --max-objects 1000
            # CephArmor bench 1000 seq -t 4 -p benchpool  --max-objects 1000
            # CephArmor bench 1000 seq -t 8 -p benchpool  --max-objects 1000
            # CephArmor bench 1000  seq -t 16 -p benchpool  --max-objects 1000

            # for i in 1 2 3 4 5 6 7 8 9 10:
            # do 
            # CephArmor bench 1000 seq -t 1 -p benchpool --max-objects 1000 --enc-bench
            # done

            # for i in 1 2 3 4 5 6 7 8 9 10:
            # do 
            # CephArmor bench 1000 seq -t 2 -p benchpool  --max-objects 1000 --enc-bench
            # done

            # for i in 1 2 3 4 5 6 7 8 9 10:
            # do 
            # CephArmor bench 1000 seq -t 4 -p benchpool  --max-objects 1000 --enc-bench
            # done

            # for i in 1 2 3 4 5 6 7 8 9 10:
            # do 
            #  CephArmor bench 1000 seq -t 8 -p benchpool  --max-objects 1000 --enc-bench
            # done

            # for i in 1 2 3 4 5 6 7 8 9 10:
            # do 
            # CephArmor bench 1000  seq -t 16 -p benchpool  --max-objects 1000 --enc-bench
            # done


            # CephArmor bench 1000 seq -t 1 -p benchpool --max-objects 1000  --enc-bench
            # CephArmor bench 1000 seq -t 2 -p benchpool  --max-objects 1000 --enc-bench
            # CephArmor bench 1000 seq -t 4 -p benchpool  --max-objects 1000 --enc-bench
            # CephArmor bench 1000 seq -t 8 -p benchpool  --max-objects 1000 --enc-bench
            # CephArmor bench 1000  seq -t 16 -p benchpool  --max-objects 1000  --enc-bench

            # ------------------------------------- READ (random) (1000 OBJECT TOTAL) -------------------------------------

            # for i in 1 2 3 4 5 6 7 8 9 10:
            # do 
            # CephArmor bench 1000 rand -t 1 -p benchpool --max-objects 1000
            # done

            # for i in 1 2 3 4 5 6 7 8 9 10:
            # do 
            # CephArmor bench 1000 rand -t 2 -p benchpool  --max-objects 1000
            # done

            # for i in 1 2 3 4 5 6 7 8 9 10:
            # do 
            # CephArmor bench 1000 rand -t 4 -p benchpool  --max-objects 1000
            # done

            # for i in 1 2 3 4 5 6 7 8 9 10:
            # do 
            #  CephArmor bench 1000 rand -t 8 -p benchpool  --max-objects 1000
            # done

            # for i in 1 2 3 4 5 6 7 8 9 10:
            # do 
            # CephArmor bench 1000  rand -t 16 -p benchpool  --max-objects 1000
            # done


            # CephArmor bench 1000 rand -t 1 -p benchpool --max-objects 1000
            # CephArmor bench 1000 rand -t 2 -p benchpool  --max-objects 1000
            # CephArmor bench 1000 rand -t 4 -p benchpool  --max-objects 1000
            # CephArmor bench 1000 rand -t 8 -p benchpool  --max-objects 1000
            # CephArmor bench 1000 rand -t 16 -p benchpool  --max-objects 1000

            # for i in 1 2 3 4 5 6 7 8 9 10:
            # do 
            # CephArmor bench 1000 rand -t 1 -p benchpool --max-objects 1000  --enc-bench
            # done

            # for i in 1 2 3 4 5 6 7 8 9 10:
            # do 
            # CephArmor bench 1000 rand -t 2 -p benchpool  --max-objects 1000  --enc-bench
            # done

            # for i in 1 2 3 4 5 6 7 8 9 10:
            # do 
            # CephArmor bench 1000 rand -t 4 -p benchpool  --max-objects 1000  --enc-bench
            # done

            # for i in 1 2 3 4 5 6 7 8 9 10:
            # do 
            #  CephArmor bench 1000 rand -t 8 -p benchpool  --max-objects 1000    --enc-bench
            # done

            # for i in 1 2 3 4 5 6 7 8 9 10:
            # do 
            # CephArmor bench 1000  rand -t 16 -p benchpool  --max-objects 1000   --enc-bench
            # done


            # CephArmor bench 1000 rand -t 1 -p benchpool --max-objects 1000   --enc-bench
            # CephArmor bench 1000 rand -t 2 -p benchpool  --max-objects 1000  --enc-bench
            # CephArmor bench 1000 rand -t 4 -p benchpool  --max-objects 1000  --enc-bench
            # CephArmor bench 1000 rand -t 8 -p benchpool  --max-objects 1000  --enc-bench
            # CephArmor bench 1000 rand -t 16 -p benchpool  --max-objects 1000  --enc-bench


           #   ---------------------------------------------------------------------------------


#   CephArmor bench 16000 write -p testpool2 --no-cleanup  --max-objects 16000



#   --------------------------------------  EC POOL WRITE-------------------------------------------

#  the script for benchmarking the EC and replica pool WRITE without encryption

#  for thread in 1  2  4  8  16 
#     do
#             for iteration in 1 2 3 4 5 6 7 8 9 10 
#             do
#                         CephArmor bench 500 write -b 4M --max-objects 1000 -t  $thread -p ecp21  --no-cleanup 
#             done
#     done


#  ceph osd map rep4 benchmark_data_15drivesnode2_1525718_object554
#  ceph osd map rep4

# REPLICATED POOLS: rep2=> size=2, min_size=1, rep3=> size=3, min_size=2, rep4=> size=4, min_size=3

#  the script for benchmarking the EC and replica pool WRITE with encryption

 

# CephArmor bench 10 write -p ECP21 --no-cleanup --max-objects 10

#    CephArmor bench 300 write -p EC21 --no-cleanup --enc-bench
#    CephArmor bench 10 rand -p ECP21 --enc-bench --max-objects 10


#    ceph osd pool delete ec42 ec42  --yes-i-really-really-mean-it 

#    CephArmor bench 60 write -p ECK2M1 --no-cleanup --enc-bench
#    rados bench 60 rand -p ECK2M1

#  ------------------------------------------------------------------------------------------------------
#  ------------------------------------------- EC POOL  READ --------------------------------------------
#  ------------------------------------------------------------------------------------------------------


#     for thread in 1  2  4  8  16 
#     do
#             for iteration in 1 2 3 4 5 6 7 8 9 10
#             do
#                         # CephArmor bench 500 rand --max-objects 1000 -t $thread -p rep4 
#                         CephArmor bench 500 rand --max-objects 1000 -t $thread -p rep4 --enc-bench
#             done
#     done



    # for thread in 1  2  4  8  16 
    # do
    #         for iteration in 1 2 3 4 5 6 7 8 9 10
    #         do
                        # CephArmor bench 500 seq --max-objects 1000 -t $thread -p rep4 
    #                     CephArmor bench 500 seq --max-objects 1000 -t $thread -p rep4 --enc-bench
    #         done
    # done
#   -------------------------------------------------------------------------------------------------

