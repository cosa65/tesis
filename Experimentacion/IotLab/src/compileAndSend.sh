
echo "-----------------------------------------Compiling receivingNode--------------------------------------------"
arm-linux-gnueabi-g++ -O0 -Wl,--whole-archive -lpthread -Wl,--no-whole-archive -Wno-psabi -std=c++11 -pthread -static receivingNode.cpp message_helper.cpp nodes_destination_translator.cpp network_organizer.cpp node_timer.cpp log_keeper.cpp connection_interference_manager.cpp emulated_nodes/node_performance.cpp emulated_nodes/coordinator_node.cpp emulated_nodes/worker_node.cpp -g -o receivingNodeArm
echo "------------------------------------------Compiling sendingNode---------------------------------------------"
arm-linux-gnueabi-g++ -O0 -Wl,--whole-archive -lpthread -Wl,--no-whole-archive -Wno-psabi -std=c++11 -pthread -static sendingNode.cpp message_helper.cpp nodes_destination_translator.cpp network_organizer.cpp node_timer.cpp log_keeper.cpp connection_interference_manager.cpp emulated_nodes/node_performance.cpp emulated_nodes/coordinator_node.cpp emulated_nodes/worker_node.cpp -g -o sendingNodeArm
echo "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Everything compiled successfully!>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"

rsync -avzhe ssh receivingNodeArm fosco@saclay.iot-lab.info:/senslab/users/fosco
rsync -avzhe ssh sendingNodeArm fosco@strasbourg.iot-lab.info:/senslab/users/fosco

ssh fosco@saclay.iot-lab.info "rsync -avzhe ssh receivingNodeArm root@node-a8-1.saclay.iot-lab.info:/home/root" &

ssh fosco@strasbourg.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-1.strasbourg.iot-lab.info:/home/root" &
ssh fosco@strasbourg.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-3.strasbourg.iot-lab.info:/home/root" &
ssh fosco@strasbourg.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-4.strasbourg.iot-lab.info:/home/root" &
ssh fosco@strasbourg.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-5.strasbourg.iot-lab.info:/home/root" &
ssh fosco@strasbourg.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-7.strasbourg.iot-lab.info:/home/root" &
ssh fosco@strasbourg.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-8.strasbourg.iot-lab.info:/home/root" &
ssh fosco@strasbourg.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-9.strasbourg.iot-lab.info:/home/root" &

wait

network_topology_content=$(cat network_topology.txt)
disconnection_intervals_content=$(cat disconnection_intervals_for_all_nodes.txt)
gnome-terminal --tab -- bash -c "ssh -t fosco@saclay.iot-lab.info 'ssh -t root@node-a8-1.saclay.iot-lab.info \"echo '\"'${disconnection_intervals_content}'\"' > disconnection_intervals_for_all_nodes.txt; echo '\"'${network_topology_content}'\"' > network_topology.txt; ./receivingNodeArm 7 1; bash\" '"

function execute_sender_number_with_disconnection_line {
	sender_command="echo '\"'${disconnection_intervals_content}'\"' > disconnection_intervals_for_all_nodes.txt | ip addr show eth0 scope global | sed -e'\''s/^.*inet6 \([^ ]*\)\/.*$/\1/;t;d'\'' | xargs -I{} ./sendingNodeArm {} ${2}"
	gnome-terminal --tab -- bash -c "ssh -t -oStrictHostKeyChecking=no fosco@strasbourg.iot-lab.info 'ssh -t root@node-a8-${1}.strasbourg.iot-lab.info \"${sender_command}; bash\" '"
}

spd-say 'bee'
sleep 30

execute_sender_number_with_disconnection_line 1 2
execute_sender_number_with_disconnection_line 3 3
execute_sender_number_with_disconnection_line 4 4 
execute_sender_number_with_disconnection_line 5 5 
execute_sender_number_with_disconnection_line 7 6
execute_sender_number_with_disconnection_line 8 7
execute_sender_number_with_disconnection_line 9 8

#./receivingNodeArm

# gnome-terminal --tab -- bash -c "ssh -t fosco@grenoble.iot-lab.info 'ssh root@node-a8-100.grenoble.iot-lab.info' ; exec bash"
# gnome-terminal --tab -- bash -c "ssh -t fosco@strasbourg.iot-lab.info 'ssh root@node-a8-10.strasbourg.iot-lab.info' ; exec bash"

spd-say 'boo'
# nunciado lince, despedite de tu cuenta maquinola'