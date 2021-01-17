import sys, rados, rbd

def connectceph():
    cluster = rados.Rados(conffile='etc/ceph/ceph.conf')
    cluster.connect()
    ioctx = cluster.open_ioctx('pool_name')
    rbd_inst = rbd.RBD()
    size = 4 * 1024 ** 3  # 4 GiB
    rbd_inst.create(ioctx, 'image_name', size)
    image = rbd.Image(ioctx, 'image_name')
    data = b'making some data'
    image.write(data, 0)
    image.close()
    ioctx.close()
    cluster.shutdown()


if __name__ == "__main__":
    connectceph()