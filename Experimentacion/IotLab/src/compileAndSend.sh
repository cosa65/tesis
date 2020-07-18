
echo "-----------------------------------------Compiling receivingNode--------------------------------------------"
arm-linux-gnueabi-g++ -Wl,--whole-archive -lpthread -Wl,--no-whole-archive -Wno-psabi -std=c++11 -O0 -fno-inline-functions -pthread -static receivingNode.cpp message_helper.cpp nodes_destination_translator.cpp network_installer.cpp node_timer.cpp log_keeper.cpp node_shutdown_manager.cpp emulated_nodes/pending_map_reduce.cpp emulated_nodes/node_state.cpp emulated_nodes/coordinator_node.cpp emulated_nodes/worker_node.cpp -g -o receivingNodeArm
echo "------------------------------------------Compiling sendingNode---------------------------------------------"
arm-linux-gnueabi-g++ -Wl,--whole-archive -lpthread -Wl,--no-whole-archive -Wno-psabi -std=c++11 -O0 -fno-inline-functions -pthread -static sendingNode.cpp message_helper.cpp nodes_destination_translator.cpp network_installer.cpp node_timer.cpp log_keeper.cpp node_shutdown_manager.cpp emulated_nodes/pending_map_reduce.cpp emulated_nodes/node_state.cpp emulated_nodes/coordinator_node.cpp emulated_nodes/worker_node.cpp -g -o sendingNodeArm
echo "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Everything compiled successfully!>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"

rsync -avzhe ssh receivingNodeArm fosco@saclay.iot-lab.info:/senslab/users/fosco
rsync -avzhe ssh map_single_task.cpp fosco@saclay.iot-lab.info:/senslab/users/fosco
rsync -avzhe ssh sendingNodeArm fosco@saclay.iot-lab.info:/senslab/users/fosco

rsync -avzhe ssh sendingNodeArm fosco@strasbourg.iot-lab.info:/senslab/users/fosco


ssh fosco@saclay.iot-lab.info "rsync -avzhe ssh receivingNodeArm root@node-a8-1.saclay.iot-lab.info:/home/root" &
ssh fosco@saclay.iot-lab.info "rsync -avzhe ssh map_single_task.cpp root@node-a8-1.saclay.iot-lab.info:/home/root" &

# ssh fosco@strasbourg.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-1.strasbourg.iot-lab.info:/home/root" &
# ssh fosco@strasbourg.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-3.strasbourg.iot-lab.info:/home/root" &
# ssh fosco@strasbourg.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-4.strasbourg.iot-lab.info:/home/root" &
# ssh fosco@strasbourg.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-5.strasbourg.iot-lab.info:/home/root" &
# ssh fosco@strasbourg.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-7.strasbourg.iot-lab.info:/home/root" &
# ssh fosco@strasbourg.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-8.strasbourg.iot-lab.info:/home/root" &
# ssh fosco@strasbourg.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-9.strasbourg.iot-lab.info:/home/root" &
wait
ssh fosco@saclay.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-2.saclay.iot-lab.info:/home/root" & 
ssh fosco@saclay.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-3.saclay.iot-lab.info:/home/root" & 
# x = $(ssh fosco@saclay.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-4.saclay.iot-lab.info:/home/root; x=$?; echo $x") &
wait
ssh fosco@saclay.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-5.saclay.iot-lab.info:/home/root" & 
ssh fosco@saclay.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-6.saclay.iot-lab.info:/home/root" & 
ssh fosco@saclay.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-7.saclay.iot-lab.info:/home/root" & 
# ssh fosco@saclay.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-8.saclay.iot-lab.info:/home/root" & 
wait
ssh fosco@saclay.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-9.saclay.iot-lab.info:/home/root" & 
ssh fosco@saclay.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-10.saclay.iot-lab.info:/home/root" & 
ssh fosco@saclay.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-11.saclay.iot-lab.info:/home/root" & 
wait
ssh fosco@saclay.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-12.saclay.iot-lab.info:/home/root" & 
ssh fosco@saclay.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-13.saclay.iot-lab.info:/home/root" & 
# ssh fosco@saclay.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-14.saclay.iot-lab.info:/home/root" & 
wait
# ssh fosco@saclay.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-15.saclay.iot-lab.info:/home/root" & 
ssh fosco@saclay.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-16.saclay.iot-lab.info:/home/root" & 
ssh fosco@saclay.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-17.saclay.iot-lab.info:/home/root" & 
wait
ssh fosco@saclay.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-18.saclay.iot-lab.info:/home/root" & 
ssh fosco@saclay.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-19.saclay.iot-lab.info:/home/root" & 
ssh fosco@saclay.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-20.saclay.iot-lab.info:/home/root" & 
wait
ssh fosco@saclay.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-21.saclay.iot-lab.info:/home/root" & 
ssh fosco@saclay.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-22.saclay.iot-lab.info:/home/root" & 
ssh fosco@saclay.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-23.saclay.iot-lab.info:/home/root" & 
wait
ssh fosco@saclay.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-24.saclay.iot-lab.info:/home/root" & 
ssh fosco@saclay.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-25.saclay.iot-lab.info:/home/root" & 
ssh fosco@strasbourg.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-1.strasbourg.iot-lab.info:/home/root" & 
wait
ssh fosco@strasbourg.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-2.strasbourg.iot-lab.info:/home/root" & 
ssh fosco@strasbourg.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-3.strasbourg.iot-lab.info:/home/root" & 
ssh fosco@strasbourg.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-4.strasbourg.iot-lab.info:/home/root" & 
wait
# ssh fosco@strasbourg.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-5.strasbourg.iot-lab.info:/home/root" & 
# ssh fosco@strasbourg.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-6.strasbourg.iot-lab.info:/home/root" & 
ssh fosco@strasbourg.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-7.strasbourg.iot-lab.info:/home/root" & 
ssh fosco@strasbourg.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-8.strasbourg.iot-lab.info:/home/root" & 
wait
ssh fosco@strasbourg.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-9.strasbourg.iot-lab.info:/home/root" & 
ssh fosco@strasbourg.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-10.strasbourg.iot-lab.info:/home/root" & 
ssh fosco@strasbourg.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-11.strasbourg.iot-lab.info:/home/root" & 
wait
ssh fosco@strasbourg.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-12.strasbourg.iot-lab.info:/home/root" & 
ssh fosco@strasbourg.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-13.strasbourg.iot-lab.info:/home/root" & 
ssh fosco@strasbourg.iot-lab.info "rsync -avzhe ssh sendingNodeArm root@node-a8-14.strasbourg.iot-lab.info:/home/root" & 
wait

network_topology_content=$(cat network_topology.txt)
network_performance_content=$(cat network_performance.txt)
shutdown_intervals_content=$(cat shutdown_intervals_for_all_nodes.txt)
	gnome-terminal --tab -- bash -c "ssh -t fosco@saclay.iot-lab.info 'ssh -t root@node-a8-1.saclay.iot-lab.info \"echo '\"'${shutdown_intervals_content}'\"' > shutdown_intervals_for_all_nodes.txt; echo '\"'${network_topology_content}'\"' > network_topology.txt; echo '\"'${network_performance_content}'\"' > network_performance.txt; gdb --args receivingNodeArm 28 1; bash\" '"

function execute_sender_number_with_disconnection_line {
	sender_command="echo '\"'${shutdown_intervals_content}'\"' > shutdown_intervals_for_all_nodes.txt | ip addr show eth0 scope global | sed -e'\''s/^.*inet6 \([^ ]*\)\/.*$/\1/;t;d'\'' | xargs -I{} ./sendingNodeArm {} ${3}"
	gnome-terminal --tab -- bash -c "ssh -t -oStrictHostKeyChecking=no fosco@${1}.iot-lab.info 'ssh -t root@node-${2} \"${sender_command}; bash\" '"
	((line++))
}

# function execute_sender_number_with_disconnection_line_debug {
# 	sender_command="echo '\"'${shutdown_intervals_content}'\"' > disconnection_intervals_for_all_nodes.txt | ip addr show eth0 scope global | sed -e'\''s/^.*inet6 \([^ ]*\)\/.*$/\1/;t;d'\'' | xargs -I{} -i gdb --args sendingNodeArm {} ${3}"
# 	gnome-terminal --tab -- bash -c "ssh -t -oStrictHostKeyChecking=no fosco@${1}.iot-lab.info 'ssh -t root@node-${2} \"${sender_command}\" '"
# }

echo "Press any key to continue"
spd-say "migomigomigomigo"
while [ true ] ; do
	read -t 3 -n 1
if [ $? = 0 ] ; then
	break;
else
	echo "waiting for the keypress"
fi
done

execute_sender_number_with_disconnection_line saclay a8-2.saclay.iot-lab.info 2
execute_sender_number_with_disconnection_line saclay a8-3.saclay.iot-lab.info 3
# execute_sender_number_with_disconnection_line saclay a8-4.saclay.iot-lab.info 4
execute_sender_number_with_disconnection_line saclay a8-22.saclay.iot-lab.info 4
execute_sender_number_with_disconnection_line saclay a8-5.saclay.iot-lab.info 5 
sleep 5
execute_sender_number_with_disconnection_line saclay a8-6.saclay.iot-lab.info 6
execute_sender_number_with_disconnection_line saclay a8-7.saclay.iot-lab.info 7
# execute_sender_number_with_disconnection_line saclay a8-8.saclay.iot-lab.info 8
execute_sender_number_with_disconnection_line saclay a8-9.saclay.iot-lab.info 8
sleep 5
execute_sender_number_with_disconnection_line saclay a8-10.saclay.iot-lab.info 9
execute_sender_number_with_disconnection_line saclay a8-11.saclay.iot-lab.info 10
execute_sender_number_with_disconnection_line saclay a8-12.saclay.iot-lab.info 11
sleep 5
execute_sender_number_with_disconnection_line saclay a8-13.saclay.iot-lab.info 12
# execute_sender_number_with_disconnection_line saclay a8-14.saclay.iot-lab.info 13
execute_sender_number_with_disconnection_line saclay a8-24.saclay.iot-lab.info 13
execute_sender_number_with_disconnection_line saclay a8-16.saclay.iot-lab.info 14
execute_sender_number_with_disconnection_line saclay a8-17.saclay.iot-lab.info 15
sleep 5
execute_sender_number_with_disconnection_line saclay a8-18.saclay.iot-lab.info 16
execute_sender_number_with_disconnection_line saclay a8-19.saclay.iot-lab.info 17
execute_sender_number_with_disconnection_line saclay a8-20.saclay.iot-lab.info 18
sleep 5
execute_sender_number_with_disconnection_line saclay a8-21.saclay.iot-lab.info 19
execute_sender_number_with_disconnection_line saclay a8-23.saclay.iot-lab.info 20
# execute_sender_number_with_disconnection_line saclay a8-25.saclay.iot-lab.info 19
execute_sender_number_with_disconnection_line strasbourg a8-1.strasbourg.iot-lab.info 21
sleep 5
execute_sender_number_with_disconnection_line strasbourg a8-2.strasbourg.iot-lab.info 22
execute_sender_number_with_disconnection_line strasbourg a8-3.strasbourg.iot-lab.info 23
execute_sender_number_with_disconnection_line strasbourg a8-4.strasbourg.iot-lab.info 24
sleep 5
# execute_sender_number_with_disconnection_line strasbourg a8-5.strasbourg.iot-lab.info 24
# execute_sender_number_with_disconnection_line strasbourg a8-6.strasbourg.iot-lab.info 24
execute_sender_number_with_disconnection_line strasbourg a8-7.strasbourg.iot-lab.info 25
execute_sender_number_with_disconnection_line strasbourg a8-8.strasbourg.iot-lab.info 26
sleep 5
execute_sender_number_with_disconnection_line strasbourg a8-9.strasbourg.iot-lab.info 27
# execute_sender_number_with_disconnection_line strasbourg a8-10.strasbourg.iot-lab.info 27
execute_sender_number_with_disconnection_line strasbourg a8-11.strasbourg.iot-lab.info 28
execute_sender_number_with_disconnection_line strasbourg a8-12.strasbourg.iot-lab.info 29
# execute_sender_number_with_disconnection_line strasbourg a8-13.strasbourg.iot-lab.info 28
# execute_sender_number_with_disconnection_line strasbourg a8-14.strasbourg.iot-lab.info 28
# execute_sender_number_with_disconnection_line strasbourg a8-15.strasbourg.iot-lab.info 28


#./receivingNodeArm

# gnome-terminal --tab -- bash -c "ssh -t fosco@grenoble.iot-lab.info 'ssh root@node-a8-100.grenoble.iot-lab.info' ; exec bash"
# gnome-terminal --tab -- bash -c "ssh -t fosco@strasbourg.iot-lab.info 'ssh root@node-a8-10.strasbourg.iot-lab.info' ; exec bash"

# spd-say -l es 'ahi va el capitan beto por el espacio'
# nunciado lince, despedite de tu cuenta maquinola'