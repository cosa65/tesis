#pragma once

#include <chrono> 

class NodeTimer {
public:
	NodeTimer();

	void start();
	double current_time_in_ms();
private:
	double now_since_epoch();

	double begin_time_in_ms;
};