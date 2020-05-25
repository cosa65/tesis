#pragma once

#include <iostream>
#include <sstream>
#include <chrono> 

class NodeTimer {
public:
	NodeTimer();

	void start();
	double current_time_in_ms();
	std::string time_log();

private:
	double now_since_epoch();

	bool started;
	double begin_time_in_ms;
};