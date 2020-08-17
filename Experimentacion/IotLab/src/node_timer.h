#pragma once

#include <iostream>
#include <sstream>
#include <chrono> 
#include <thread>

class NodeTimer {
public:
	NodeTimer();

	void start();
	double current_time_in_ms();
	std::string time_log();

	void sleep_until(double wake_up_time_in_ms);

private:
	double now_since_epoch();

	bool started;
	double begin_time_in_ms;
};