arm-linux-gnueabi-g++ receivingNode.cpp message_helper.cpp -static -o receivingNodeArm
arm-linux-gnueabi-g++ sendingNode.cpp message_helper.cpp -static -o sendingNodeArm

echo "Everything compiled successfully!"

scp receivingNodeArm fosco@grenoble.iot-lab.info:/senslab/users/fosco
scp sendingNodeArm fosco@strasbourg.iot-lab.info:/senslab/users/fosco

ssh fosco@grenoble.iot-lab.info "scp receivingNodeArm root@node-a8-100.grenoble.iot-lab.info:/home/root"
ssh fosco@strasbourg.iot-lab.info "scp sendingNodeArm root@node-a8-10.strasbourg.iot-lab.info:/home/root"

gnome-terminal --tab -- bash -c "ssh -t fosco@grenoble.iot-lab.info 'ssh root@node-a8-100.grenoble.iot-lab.info' ; exec bash"
gnome-terminal --tab -- bash -c "ssh -t fosco@strasbourg.iot-lab.info 'ssh root@node-a8-10.strasbourg.iot-lab.info' ; exec bash"