#pragma once

#include <iostream>
#include <sstream>

#include "node_timer.h"

class LogKeeper {
public:
	LogKeeper(NodeTimer *node_timer): node_timer(node_timer)  {}

	void log(std::string message);

private:
	NodeTimer *node_timer;
};