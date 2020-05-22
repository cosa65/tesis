#include "node_timer.h"

NodeTimer::NodeTimer(): started(false) {}

void NodeTimer::start() {
	this -> begin_time_in_ms = now_since_epoch();
	this -> started = true;
}

double NodeTimer::current_time_in_ms() {
	if (!this -> started) { return -1; }

	return now_since_epoch() - (this -> begin_time_in_ms);
}

double NodeTimer::now_since_epoch() {
	std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
	auto duration = now.time_since_epoch();
	return std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
}