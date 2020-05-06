#pragma once

#include <string.h>
#include <iostream>

#include <list>

class WorkerNode {
public:
	WorkerNode(std::string ip_to_coordinator);

private:
	std::string ip_to_coordinator;
};