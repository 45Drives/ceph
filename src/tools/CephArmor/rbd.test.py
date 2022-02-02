
import rados, rbd, sys



cluster = rados.Rados(conffile='/etc/ceph/ceph.conf')
# try:
#     cluster.connect()
#     ioctx = cluster.open_ioctx('rbdpool')
#     try:
#         rbd_inst = rbd.RBD()
#         size = 4 * 1024**3  # 4 GiB
#         # rbd_inst.create(ioctx, 'rbd.image', size)
#         image = rbd.Image(ioctx, 'rbd.image')
#         try:
#             data = b'foo' * 2000000
#             image.write(data, 0)
#         finally:
#             image.close()
#     finally:
#         ioctx.close()
# finally:
#     cluster.shutdown()



cluster.connect()
ioctx = cluster.open_ioctx('rbdpool')
rbd_inst = rbd.RBD()
size = 4 * 1024**3  # 4 GiB
# rbd_inst.create(ioctx, 'rbd.image', size)
image = rbd.Image(ioctx, 'rbd.image')
data = b'foo' * 2000000
image.write(data, 0)
image.close()
ioctx.close()
cluster.shutdown()