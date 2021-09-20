

    # write benchmark Ceph API (without encryption) 
    for thread in 2  4  8  16 
    do
        echo "------------------------- Thread $thread -------------------------------------"
        for message_size in 1M 2M 3M 4M
        do
            echo "------------------------- Message_size $message_size -------------------------------------"
            # for iteration in 1 2 3 4 5 6  8 9 10
            # do
            echo "CephArmor bench 60 write -b $message_size -t $thread -p benchpool --no-cleanup"
            CephArmor bench 10 write -b $message_size -t $thread -p benchpool --no-cleanup
            # done
        done
    done


    # write benchmark CephArmor API (with encryption) 
    # for thread in  2  4  8  16
    # do
    #     echo "------------------------- Thread $thread -------------------------------------"
    #     for message_size in 1M 2M 3M 4M
    #     do
    #         echo "------------------------- Message_size $message_size -------------------------------------"
            # for iteration in 1 2 3 4 5 6  8 9 10
            # do
            # echo "CephArmor bench 60 write -b $message_size -t $thread -p benchpool --no-cleanup --enc-bench"
            # CephArmor bench 10 write -b $message_size -t $thread -p benchpool --no-cleanup --enc-bench
            # done
    #     done
    # done

    #----------------------------------------------------------------------------------------------------------

     # read benchmark Ceph API (with encryption) 
    #  for thread in 2  4  8  16
    #  do
    #     echo "------------------------- Thread $thread -------------------------------------"
    #     for iteration in 1 2 3 4 5 6  8 9 10
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
   #      for iteration in 1 2 3 4 5 6  8 9 10
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
    #     for iteration in 1 2 3 4 5 6  8 9 10
    #     do
    #     echo "CephArmor bench -p benchpool 60 seq -t $thread --enc-bench"
    #     CephArmor bench -p benchpool 60 seq -t $thread --enc-bench
    #     done
    #  done

 #----------------------------------------------------------------------------------------------------------

   # for thread in 2  4  8  16
   #   do
   #      echo "------------------------- Thread $thread -------------------------------------"
   #      for iteration in 1 2 3 4 5 6  8 9 10
   #      do
   #      echo "CephArmor bench -p benchpool 60 rand -t $thread --enc-bench"
   #      CephArmor bench -p benchpool 60 rand -t $thread --enc-bench
   #      done
   #   done







    #  CephArmor bench -p freepool 3 seq
    #  CephArmor bench -p freepool 3 rand

    #  CephArmor bench 1000 write -p freepool --no-cleanup

         #         CephArmor bench 5000 write  -p testpool --no-cleanup
        #   CephArmor bench 10 write  -p testpool --no-cleanup  --enc-bench
        # CephArmor bench -p benchpool 5 rand --enc-bench
