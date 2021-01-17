#!/bin/bash




echo " $(tput setab 13) install-deps  ............................. $(tput sgr 0)";
./install-deps.sh


echo " $(tput setab 13) make-dist  ............................. $(tput sgr 0)";
./make-dist


CEPH_TAR=ceph*.tar.bz2

echo " $(tput setab 13) making rpmbuild ............................. $(tput sgr 0)";
cp ceph-15.0.0-19793-g2f7077e243.tar.bz2 ~/rpmbuild/SOURCES/
cp $CEPH_TAR ~/rpmbuild/SOURCES/

tar --strip-components=1 -C ~/rpmbuild/SPECS/ --no-anchored -xvjf ~/rpmbuild/SOURCES/ceph-15.0.0-19793-g2f7077e243.tar.bz2 "ceph.spec"
tar --strip-components=1 -C ~/rpmbuild/SPECS/ --no-anchored -xvjf ~/rpmbuild/SOURCES/$CEPH_TAR "ceph.spec"

rpmbuild  -ba ~/rpmbuild/SPECS/ceph.spec

cd ~/rpmbuild/RPMS/x86_64
fuser -k 3300/tcp
yum --allowerasing --nogpgcheck --skip-broken localinstall *.rpm


echo " $(tput setab 13) starting cluster configuration ............................. $(tput sgr 0)";

uid=$(uuidgen)
host=$(hostname)

mkdir /etc/ceph
rm -rf /etc/ceph/ceph.conf
touch /etc/ceph/ceph.conf
echo "[global]" > ./ceph.conf
echo "fsid = ${uid}" >> ./ceph.conf
echo "mon initial members=${host}" >> ./ceph.conf




PRIMARY_IP=$(ip route get 1 | head -1 | awk '{print $7}')

cephadm bootstrap  --mon-ip $PRIMARY_IP --fsid $uid --skip-dashboard --skip-firewalld --skip-ssh  --allow-overwrite
cephadm bootstrap  --mon-ip $PRIMARY_IP --fsid $uid --skip-firewalld --skip-ssh  --allow-overwrite


echo $(ceph -s)





# ceph mgr module enable cephadm

 #ceph orch set backend cephadm

 #ceph config set mon public_network 10.31.0.0/16

 #ceph cephadm generate-key

 #ceph cephadm get-pub-key > ~/ceph.pub

 #ssh-copy-id -f -i ~/ceph.pub root@${host}

 #ceph orch host add ${host}

 #ceph orch apply osd --all-available-devices

 echo " $(tput setab 13) Deployment completed!!!!!!! :) ............................. $(tput sgr 0)";


























