#pragma once

#include <string.h>
#include <iostream>

#include <list>

class CoordinatorNode {
public:
	CoordinatorNode(std::list<std::string> worker_ips);

private:
	std::list<std::string> worker_ips;
};