#include "log_keeper.h"

LogKeeper::LogKeeper(NodeTimer node_timer): node_timer(node_timer) {}

void LogKeeper::log(std::string message) {
	double current_time = node_timer.current_time_in_ms();

	std::string current_time_str = current_time > 0 ? std::to_string(current_time) : "EXPERIMENT NOT YET STARTED";

	std::cout << "[" << current_time_str << "]: " << message << std::endl;
}