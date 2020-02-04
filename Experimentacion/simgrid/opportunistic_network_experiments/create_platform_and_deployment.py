import sys
import random

def create_platform(amount_of_nodes):
	file = open("platform.xml","w")

	file.write("""<?xml version='1.0'?>
<!DOCTYPE platform SYSTEM "http://simgrid.gforge.inria.fr/simgrid/simgrid.dtd">
<platform version="4.1">
	<zone id="zone0" routing="Full">
	""")

	file.write("""
		<host id="Organizer" speed="76.296Mf"/>

		<host id="NodeCoordinator" speed="76.296Mf"/>
	""")

	for i in range(amount_of_nodes):
		file.write(f"""
		<host id="Node{i}" speed="76.296Mf"/>
	""")

	file.write(f"""<link id="loopback" bandwidth="100.0MBps" latency="0us"/>""")

	link_latencies = [random.randint(5, 100) for iter in range(amount_of_nodes)]
	link_latencies.sort()

	for i in range(amount_of_nodes):
		file.write(f"""
		<link id="link_coord_{i}" bandwidth="40MBps" latency="{link_latencies[i]}ms"/>
	""")


	file.write("""
	    <route src="Organizer" dst="Organizer">
	      <link_ctn id="loopback"/>
	    </route>
	""")

	for i in range(amount_of_nodes):
		file.write(f"""
		<route src="NodeCoordinator" dst="Node{i}">
			<link_ctn id="link_coord_{i}"/>
		</route>
	    """)

	file.write("""
	</zone>
""")
	file.write("</platform>")

def create_deployment(amount_of_nodes):
	file = open("deployment.xml","w")

	file.write("""<?xml version='1.0'?>
<!DOCTYPE platform SYSTEM "http://simgrid.gforge.inria.fr/simgrid/simgrid.dtd">
<platform version="4.1">
	<actor host="Organizer" function="mailboxes_manager_actor" />
	<actor host="NodeCoordinator" function="map_reduce_coordinator_host_setup" />
	<actor host="NodeCoordinator" function="map_reduce_worker_host_setup" />
	""")

	for i in range(amount_of_nodes):
		file.write(f"""
	<actor host="Node{i}" function="map_reduce_worker_host_setup" />
""")

	file.write("</platform>")

amount_of_nodes = int(sys.argv[1])

# The coordinator has to exist without exception, right now it always doubles as a worker node so it adds one to the amount_of_nodes
amount_of_nodes -= 1

create_platform(amount_of_nodes)
create_deployment(amount_of_nodes)

print("Copy and paste the following under \"static void map_reduce_coordinator_host_setup(std::vector<std::string> args) {\"")

print(f"""----------------------------------------------------------------------------------------------------------------------------
""")

print("""workers.push_back(simgrid::s4u::Mailbox::by_name("NodeCoordinator-worker"));""")

for i in range(amount_of_nodes):
	print(f"""workers.push_back(simgrid::s4u::Mailbox::by_name("Node{i}-worker"));""")

print(f"""----------------------------------------------------------------------------------------------------------------------------
""")

print("Now you have to manually set map_tasks_in_flops (of size = the size of nodes, and actual size of original array of tasks is set in array_size (array_size should be higher than size of map_tasks_in_flops))")