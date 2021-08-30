

    # write benchmark Ceph API (without encryption) 
    # for thread in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
    # do
    #     echo "------------------------- Thread $thread -------------------------------------"
    #     for message_size in 1K 2K 4K 8K 16K 32K 64K 128K 256K 512K 1M 2M 3M 4M
    #     do
    #         echo "------------------------- Message_size $message_size -------------------------------------"
    #         for iteration in 1 2 3 4 5 6  8 9 10
    #         do
    #         echo "CephArmor bench 30 write -b $message_size -t $thread -p testpool --no-cleanup"
    #         CephArmor bench 30 write -b $message_size -t $thread -p testpool --no-cleanup
    #         done
    #     done
    # done


    # write benchmark CephArmor API (with encryption) 
    # for thread in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
    # do
    #     echo "------------------------- Thread $thread -------------------------------------"
    #     for message_size in 1K 2K 4K 8K 16K 32K 64K 128K 256K 512K 1M 2M 3M 4M
    #     do
    #         echo "------------------------- Message_size $message_size -------------------------------------"
    #         for iteration in 1 2 3 4 5 6  8 9 10
    #         do
    #         echo "CephArmor bench 30 write -b $message_size -t $thread -p testpool --no-cleanup --enc-bench"
    #         CephArmor bench 30 write -b $message_size -t $thread -p testpool --no-cleanup --enc-bench
    #         done
    #     done
    # done

    #----------------------------------------------------------------------------------------------------------

     # read benchmark Ceph API (with encryption) 
    #  for thread in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
    #  do
    #     echo "------------------------- Thread $thread -------------------------------------"
    #     for iteration in 1 2 3 4 5 6  8 9 10
    #     do
    #     echo "CephArmor bench -p freepool 30 seq -t $thread "
    #     CephArmor bench -p freepool 30 seq -t $thread
    #     done
    #  done

 #----------------------------------------------------------------------------------------------------------

     # read benchmark Ceph API (with encryption) 
    #  for thread in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
    #  do
    #     echo "------------------------- Thread $thread -------------------------------------"
    #     for iteration in 1 2 3 4 5 6  8 9 10
    #     do
    #     echo "CephArmor bench -p freepool 30 rand -t $thread "
    #     CephArmor bench -p freepool 30 rand -t $thread
    #     done
    #  done

    
 #----------------------------------------------------------------------------------------------------------


#   read benchmark Ceph API (with encryption) 
    #  for thread in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
    #  do
    #     echo "------------------------- Thread $thread -------------------------------------"
    #     for iteration in 1 2 3 4 5 6  8 9 10
    #     do
    #     echo "CephArmor bench -p freepool 30 seq -t $thread --enc-bench"
    #     CephArmor bench -p freepool 30 seq -t $thread --enc-bench
    #     done
    #  done

 #----------------------------------------------------------------------------------------------------------

        for thread in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
     do
        echo "------------------------- Thread $thread -------------------------------------"
        for iteration in 1 2 3 4 5 6  8 9 10
        do
        echo "CephArmor bench -p freepool 30 rand -t $thread --enc-bench"
        CephArmor bench -p freepool 30 rand -t $thread --enc-bench
        done
     done


    #  CephArmor bench -p freepool 3 seq
    #  CephArmor bench -p freepool 3 rand
# Total time run, Total reads made, Read size, Object size, Bandwidth (MB/sec), Average IOPS, Stddev IOPS, Max IOPS, Min IOPS, Average Latency(s), Max latency(s), Min latency(s)

     