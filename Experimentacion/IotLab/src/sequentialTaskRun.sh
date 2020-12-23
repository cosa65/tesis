arm-linux-gnueabi-g++ -static sequential_execution_map_reduce.cpp node_timer.cpp -o sequentialMapReduce
echo "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Everything compiled successfully!>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"

rsync -avzhe ssh sequentialMapReduce fosco@saclay.iot-lab.info:/senslab/users/fosco
rsync -avzhe ssh sequentialMapReduce fosco@strasbourg.iot-lab.info:/senslab/users/fosco

ssh fosco@saclay.iot-lab.info "rsync -avzhe ssh sequentialMapReduce root@node-a8-1.saclay.iot-lab.info:/home/root" &
wait
ssh fosco@saclay.iot-lab.info "rsync -avzhe ssh sequentialMapReduce root@node-a8-2.saclay.iot-lab.info:/home/root" & 
ssh fosco@saclay.iot-lab.info "rsync -avzhe ssh sequentialMapReduce root@node-a8-3.saclay.iot-lab.info:/home/root" & 
ssh fosco@saclay.iot-lab.info "rsync -avzhe ssh sequentialMapReduce root@node-a8-4.saclay.iot-lab.info:/home/root" & 
wait
ssh fosco@saclay.iot-lab.info "rsync -avzhe ssh sequentialMapReduce root@node-a8-5.saclay.iot-lab.info:/home/root" & 
ssh fosco@saclay.iot-lab.info "rsync -avzhe ssh sequentialMapReduce root@node-a8-6.saclay.iot-lab.info:/home/root" & 
ssh fosco@saclay.iot-lab.info "rsync -avzhe ssh sequentialMapReduce root@node-a8-7.saclay.iot-lab.info:/home/root" & 
# ssh fosco@saclay.iot-lab.info "rsync -avzhe ssh sequentialMapReduce root@node-a8-8.saclay.iot-lab.info:/home/root" & 
wait
ssh fosco@saclay.iot-lab.info "rsync -avzhe ssh sequentialMapReduce root@node-a8-9.saclay.iot-lab.info:/home/root" & 
ssh fosco@saclay.iot-lab.info "rsync -avzhe ssh sequentialMapReduce root@node-a8-10.saclay.iot-lab.info:/home/root" & 
ssh fosco@saclay.iot-lab.info "rsync -avzhe ssh sequentialMapReduce root@node-a8-11.saclay.iot-lab.info:/home/root" & 
wait
ssh fosco@saclay.iot-lab.info "rsync -avzhe ssh sequentialMapReduce root@node-a8-12.saclay.iot-lab.info:/home/root" & 
ssh fosco@saclay.iot-lab.info "rsync -avzhe ssh sequentialMapReduce root@node-a8-13.saclay.iot-lab.info:/home/root" & 
ssh fosco@saclay.iot-lab.info "rsync -avzhe ssh sequentialMapReduce root@node-a8-16.saclay.iot-lab.info:/home/root" &
wait

ssh fosco@strasbourg.iot-lab.info "rsync -avzhe ssh sequentialMapReduce root@node-a8-1.strasbourg.iot-lab.info:/home/root" & 
ssh fosco@strasbourg.iot-lab.info "rsync -avzhe ssh sequentialMapReduce root@node-a8-2.strasbourg.iot-lab.info:/home/root" & 
ssh fosco@strasbourg.iot-lab.info "rsync -avzhe ssh sequentialMapReduce root@node-a8-3.strasbourg.iot-lab.info:/home/root" & 
wait
ssh fosco@strasbourg.iot-lab.info "rsync -avzhe ssh sequentialMapReduce root@node-a8-4.strasbourg.iot-lab.info:/home/root" & 
ssh fosco@strasbourg.iot-lab.info "rsync -avzhe ssh sequentialMapReduce root@node-a8-5.strasbourg.iot-lab.info:/home/root" & 
wait

iterations=100
multiplier=100
function execute_sequential_map_reduce {
	gnome-terminal --tab -- bash -c "ssh -t -oStrictHostKeyChecking=no fosco@${1}.iot-lab.info 'ssh -t root@node-a8-${2}.${1}.iot-lab.info ./sequentialMapReduce ${iterations} ${multiplier} verbose; bash '"
}

execute_sequential_map_reduce saclay 1
execute_sequential_map_reduce saclay 2
execute_sequential_map_reduce saclay 3
execute_sequential_map_reduce saclay 4
execute_sequential_map_reduce saclay 5
execute_sequential_map_reduce saclay 6
execute_sequential_map_reduce saclay 7
execute_sequential_map_reduce saclay 9
execute_sequential_map_reduce saclay 10
execute_sequential_map_reduce saclay 11
execute_sequential_map_reduce saclay 12
execute_sequential_map_reduce saclay 13
execute_sequential_map_reduce saclay 16

execute_sequential_map_reduce strasbourg 1
execute_sequential_map_reduce strasbourg 2
execute_sequential_map_reduce strasbourg 3
execute_sequential_map_reduce strasbourg 4
execute_sequential_map_reduce strasbourg 5