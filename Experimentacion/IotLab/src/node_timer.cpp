#include "node_timer.h"

NodeTimer::NodeTimer(): started(false) {}

void NodeTimer::start() {
	this -> started = true;
	this -> begin_time_in_ms = now_since_epoch();
}

double NodeTimer::current_time_in_ms() {
	if (!this -> started) { 
		return -1;
	}

	return now_since_epoch() - (this -> begin_time_in_ms);
}

std::string NodeTimer::time_log() {
	double current_time = current_time_in_ms();

	std::ostringstream ostr;
	ostr.precision(12);

	std::string current_time_str = this -> started ? std::to_string(current_time) : "EXPERIMENT NOT YET STARTED";

	ostr << "[" << std::fixed << current_time_str << "] ";

	return ostr.str();
}

double NodeTimer::now_since_epoch() {
	std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
	auto duration = now.time_since_epoch();
	return std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
}

void NodeTimer::sleep_until(double wake_up_time_in_ms) {
	int sleep_time = wake_up_time_in_ms - current_time_in_ms();

	if (sleep_time > 0) {
		std::this_thread::sleep_for(std::chrono::milliseconds((long)sleep_time));
	}
}