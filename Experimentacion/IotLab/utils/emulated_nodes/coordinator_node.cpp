#include "coordinator_node.h"

CoordinatorNode::CoordinatorNode(std::list<std::string> worker_ips) {
	this -> worker_ips = worker_ips;
}