
echo "-----------------------------------------Compiling receivingNode--------------------------------------------"
arm-linux-gnueabi-g++ -Wl,--whole-archive -lpthread -Wl,--no-whole-archive -Wno-psabi -std=c++11 -pthread -static receivingNode.cpp message_helper.cpp network_organizer.cpp emulated_nodes/node_timer.cpp emulated_nodes/connection_interference_manager.cpp emulated_nodes/node_performance.cpp emulated_nodes/coordinator_node.cpp emulated_nodes/worker_node.cpp -g -o receivingNodeArm
echo "------------------------------------------Compiling sendingNode---------------------------------------------"
arm-linux-gnueabi-g++ -Wl,--whole-archive -lpthread -Wl,--no-whole-archive -Wno-psabi -std=c++11 -pthread -static sendingNode.cpp message_helper.cpp network_organizer.cpp emulated_nodes/node_timer.cpp emulated_nodes/connection_interference_manager.cpp emulated_nodes/node_performance.cpp emulated_nodes/coordinator_node.cpp emulated_nodes/worker_node.cpp -g -o sendingNodeArm
echo "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Everything compiled successfully!>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"

scp receivingNodeArm fosco@saclay.iot-lab.info:/senslab/users/fosco
# scp disconnection_intervals_for_all_nodes.txt fosco@saclay.iot-lab.info:/senslab/users/fosco
scp sendingNodeArm fosco@strasbourg.iot-lab.info:/senslab/users/fosco

ssh fosco@saclay.iot-lab.info "scp receivingNodeArm root@node-a8-1.saclay.iot-lab.info:/home/root"
ssh fosco@saclay.iot-lab.info "scp disconnection_intervals_for_all_nodes.txt root@node-a8-1.saclay.iot-lab.info:/home/root"

ssh fosco@strasbourg.iot-lab.info "scp -oStrictHostKeyChecking=no sendingNodeArm root@node-a8-1.strasbourg.iot-lab.info:/home/root"
ssh fosco@strasbourg.iot-lab.info "scp -oStrictHostKeyChecking=no sendingNodeArm root@node-a8-2.strasbourg.iot-lab.info:/home/root"
ssh fosco@strasbourg.iot-lab.info "scp -oStrictHostKeyChecking=no sendingNodeArm root@node-a8-3.strasbourg.iot-lab.info:/home/root"
ssh fosco@strasbourg.iot-lab.info "scp -oStrictHostKeyChecking=no sendingNodeArm root@node-a8-4.strasbourg.iot-lab.info:/home/root"
ssh fosco@strasbourg.iot-lab.info "scp -oStrictHostKeyChecking=no sendingNodeArm root@node-a8-5.strasbourg.iot-lab.info:/home/root"
ssh fosco@strasbourg.iot-lab.info "scp -oStrictHostKeyChecking=no sendingNodeArm root@node-a8-7.strasbourg.iot-lab.info:/home/root"
ssh fosco@strasbourg.iot-lab.info "scp -oStrictHostKeyChecking=no sendingNodeArm root@node-a8-8.strasbourg.iot-lab.info:/home/root"

disconnection_history=$(sed -n "1p" < disconnection_intervals_for_all_nodes.txt)
disconnection_intervals_content=$(cat disconnection_intervals_for_all_nodes.txt)
gnome-terminal --tab -- bash -c "ssh -t fosco@saclay.iot-lab.info 'ssh -t root@node-a8-1.saclay.iot-lab.info \"echo '\"'${disconnection_intervals_content}'\"' >> disconnection_intervals_for_all_nodes.txt; ./receivingNodeArm 7 1; bash\" '"

function execute_sender_number_with_disconnection_line {
	sender_command="echo '\"'${disconnection_intervals_content}'\"' >> disconnection_intervals_for_all_nodes.txt | ip addr show eth0 scope global | sed -e'\''s/^.*inet6 \([^ ]*\)\/.*$/\1/;t;d'\'' | xargs -I{} ./sendingNodeArm {} ${2}"
	gnome-terminal --tab -- bash -c "ssh -t -oStrictHostKeyChecking=no fosco@strasbourg.iot-lab.info 'ssh -t root@node-a8-${1}.strasbourg.iot-lab.info \"${sender_command}; bash\" '"
}

# gnome-terminal --tab -- bash -c "ssh -t -oStrictHostKeyChecking=no fosco@strasbourg.iot-lab.info 'ssh -t root@node-a8-1.strasbourg.iot-lab.info \"${sender_command}; bash\" '"
# gnome-terminal --tab -- bash -c "ssh -t -oStrictHostKeyChecking=no fosco@strasbourg.iot-lab.info 'ssh -t root@node-a8-2.strasbourg.iot-lab.info \"${sender_command}; bash\" '"
# gnome-terminal --tab -- bash -c "ssh -t -oStrictHostKeyChecking=no fosco@strasbourg.iot-lab.info 'ssh -t root@node-a8-3.strasbourg.iot-lab.info \"${sender_command}; bash\" '"
# gnome-terminal --tab -- bash -c "ssh -t -oStrictHostKeyChecking=no fosco@strasbourg.iot-lab.info 'ssh -t root@node-a8-4.strasbourg.iot-lab.info \"${sender_command}; bash\" '"
# gnome-terminal --tab -- bash -c "ssh -t -oStrictHostKeyChecking=no fosco@strasbourg.iot-lab.info 'ssh -t root@node-a8-5.strasbourg.iot-lab.info \"${sender_command}; bash\" '"
# gnome-terminal --tab -- bash -c "ssh -t -oStrictHostKeyChecking=no fosco@strasbourg.iot-lab.info 'ssh -t root@node-a8-7.strasbourg.iot-lab.info \"${sender_command}; bash\" '"

execute_sender_number_with_disconnection_line 1 2
execute_sender_number_with_disconnection_line 2 3
execute_sender_number_with_disconnection_line 3 4
execute_sender_number_with_disconnection_line 4 5 
execute_sender_number_with_disconnection_line 5 6 
execute_sender_number_with_disconnection_line 7 7
execute_sender_number_with_disconnection_line 8 8

#./receivingNodeArm

# gnome-terminal --tab -- bash -c "ssh -t fosco@grenoble.iot-lab.info 'ssh root@node-a8-100.grenoble.iot-lab.info' ; exec bash"
# gnome-terminal --tab -- bash -c "ssh -t fosco@strasbourg.iot-lab.info 'ssh root@node-a8-10.strasbourg.iot-lab.info' ; exec bash"
