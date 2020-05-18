
echo "-----------------------------------------Compiling receivingNode--------------------------------------------"
arm-linux-gnueabi-g++ -Wl,--whole-archive -lpthread -Wl,--no-whole-archive -Wno-psabi -std=c++11 -pthread -static receivingNode.cpp message_helper.cpp network_organizer.cpp emulated_nodes/node_performance.cpp emulated_nodes/coordinator_node.cpp emulated_nodes/worker_node.cpp -g -o receivingNodeArm
echo "------------------------------------------Compiling sendingNode---------------------------------------------"
arm-linux-gnueabi-g++ -Wl,--whole-archive -lpthread -Wl,--no-whole-archive -Wno-psabi -std=c++11 -pthread -static sendingNode.cpp message_helper.cpp network_organizer.cpp emulated_nodes/node_performance.cpp emulated_nodes/coordinator_node.cpp emulated_nodes/worker_node.cpp -g -o sendingNodeArm
echo "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Everything compiled successfully!>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"

scp receivingNodeArm fosco@saclay.iot-lab.info:/senslab/users/fosco
scp sendingNodeArm fosco@strasbourg.iot-lab.info:/senslab/users/fosco

ssh fosco@saclay.iot-lab.info "scp receivingNodeArm root@node-a8-1.saclay.iot-lab.info:/home/root"

ssh fosco@strasbourg.iot-lab.info "scp -oStrictHostKeyChecking=no sendingNodeArm root@node-a8-1.strasbourg.iot-lab.info:/home/root"
ssh fosco@strasbourg.iot-lab.info "scp -oStrictHostKeyChecking=no sendingNodeArm root@node-a8-2.strasbourg.iot-lab.info:/home/root"
ssh fosco@strasbourg.iot-lab.info "scp -oStrictHostKeyChecking=no sendingNodeArm root@node-a8-3.strasbourg.iot-lab.info:/home/root"
ssh fosco@strasbourg.iot-lab.info "scp -oStrictHostKeyChecking=no sendingNodeArm root@node-a8-4.strasbourg.iot-lab.info:/home/root"
ssh fosco@strasbourg.iot-lab.info "scp -oStrictHostKeyChecking=no sendingNodeArm root@node-a8-5.strasbourg.iot-lab.info:/home/root"
ssh fosco@strasbourg.iot-lab.info "scp -oStrictHostKeyChecking=no sendingNodeArm root@node-a8-7.strasbourg.iot-lab.info:/home/root"
ssh fosco@strasbourg.iot-lab.info "scp -oStrictHostKeyChecking=no sendingNodeArm root@node-a8-8.strasbourg.iot-lab.info:/home/root"

gnome-terminal --tab -- bash -c "ssh -t fosco@saclay.iot-lab.info 'ssh -t root@node-a8-1.saclay.iot-lab.info \"./receivingNodeArm 7; bash\" '"
 # ip -6 addr show scope global eth0 |  awk '/inet6/{print $2}' | sed -e "s/\/64//" | echo $(</dev/stdin)

# ip addr show eth0 scope global | sed -e's/^.*inet6 \([^ ]*\)\/.*$/\1/;t;d'

sender_command="ip addr show eth0 scope global | sed -e'\''s/^.*inet6 \([^ ]*\)\/.*$/\1/;t;d'\'' | xargs -I{} ./sendingNodeArm {}"

gnome-terminal --tab -- bash -c "ssh -t -oStrictHostKeyChecking=no fosco@strasbourg.iot-lab.info 'ssh -t root@node-a8-1.strasbourg.iot-lab.info \"${sender_command}; bash\" '"
gnome-terminal --tab -- bash -c "ssh -t -oStrictHostKeyChecking=no fosco@strasbourg.iot-lab.info 'ssh -t root@node-a8-2.strasbourg.iot-lab.info \"${sender_command}; bash\" '"
gnome-terminal --tab -- bash -c "ssh -t -oStrictHostKeyChecking=no fosco@strasbourg.iot-lab.info 'ssh -t root@node-a8-3.strasbourg.iot-lab.info \"${sender_command}; bash\" '"
gnome-terminal --tab -- bash -c "ssh -t -oStrictHostKeyChecking=no fosco@strasbourg.iot-lab.info 'ssh -t root@node-a8-4.strasbourg.iot-lab.info \"${sender_command}; bash\" '"
gnome-terminal --tab -- bash -c "ssh -t -oStrictHostKeyChecking=no fosco@strasbourg.iot-lab.info 'ssh -t root@node-a8-5.strasbourg.iot-lab.info \"${sender_command}; bash\" '"
gnome-terminal --tab -- bash -c "ssh -t -oStrictHostKeyChecking=no fosco@strasbourg.iot-lab.info 'ssh -t root@node-a8-7.strasbourg.iot-lab.info \"${sender_command}; bash\" '"
gnome-terminal --tab -- bash -c "ssh -t -oStrictHostKeyChecking=no fosco@strasbourg.iot-lab.info 'ssh -t root@node-a8-8.strasbourg.iot-lab.info \"${sender_command}; bash\" '"

#./receivingNodeArm

# gnome-terminal --tab -- bash -c "ssh -t fosco@grenoble.iot-lab.info 'ssh root@node-a8-100.grenoble.iot-lab.info' ; exec bash"
# gnome-terminal --tab -- bash -c "ssh -t fosco@strasbourg.iot-lab.info 'ssh root@node-a8-10.strasbourg.iot-lab.info' ; exec bash"