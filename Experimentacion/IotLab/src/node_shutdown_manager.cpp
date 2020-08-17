#include "node_shutdown_manager.h"

NodeShutdownManager::NodeShutdownManager(NodeTimer *node_timer):
	node_timer(node_timer) 
	{}

void NodeShutdownManager::load_disconnection_intervals(std::list< std::tuple<double, double> > disconnection_intervals) {
	this -> disconnection_intervals = disconnection_intervals;
}

void NodeShutdownManager::load_disconnection_intervals(int disconnections_line_number) {
	std::cout << "[NODE_SHUTDOWN_MANAGER] About to load stuff" << std::endl;

	std::list< std::tuple<double, double> > disconnection_intervals;

	std::ifstream file;
	file.open("shutdown_intervals_for_all_nodes.txt");

	std::string line;
	// Get line specified in line_number (indexed from 1)
	for(int i = 1; i <= disconnections_line_number; ++i) {
       getline(file, line);
	}

	std::istringstream ss_intervals(line);

	std::cout << "[NODE_SHUTDOWN_MANAGER] Intervals: " << line << std::endl;

	double interval_begin;
	double interval_end;

	while(ss_intervals >> interval_begin) {
		ss_intervals >> interval_end;

		std::cout << "[NODE_SHUTDOWN_MANAGER] Added new interval of disconnection: " << interval_begin << " " << interval_end << std::endl;

		disconnection_intervals.push_back({interval_begin, interval_end});
	}

	std::cout << "[NODE_SHUTDOWN_MANAGER] Finished loading stuff" << std::endl;

	this -> disconnection_intervals = disconnection_intervals;

	file.close();
}

void NodeShutdownManager::start() {}

bool NodeShutdownManager::can_receive_message(MessageHelper::MessageData received_message) {
	double time_of_receipt_message = this -> node_timer -> current_time_in_ms();

	return is_connected_now(time_of_receipt_message);
}

bool NodeShutdownManager::was_off_during(double start_time, double end_time) {
	for (auto interval : this -> disconnection_intervals) {

		double start_shutdown = std::get<0>(interval);
		double end_shutdown = std::get<1>(interval);

		bool started_shutdown_during_interval = start_shutdown >= start_time && start_shutdown <= end_time;
		bool ended_shutdown_during_interval = end_shutdown >= start_time && end_shutdown <= end_time;

		if (started_shutdown_during_interval || ended_shutdown_during_interval) {
			return true;
		}
	}

	return false;
}

bool NodeShutdownManager::is_connected_now(double time_point) {
	for (auto interval : this -> disconnection_intervals) {
		std::cout << "[NODE_SHUTDOWN_MANAGER] Checking if can receive time_point: " << time_point << " interval: " << std::get<0>(interval) << " " << std::get<1>(interval) << std::endl;
		if (time_point >= std::get<0>(interval) && time_point <= std::get<1>(interval)) {
			return false;
		}
	}

	return true;
}

// template <typename Function>
// void NodeShutdownManager::execute_on_turning_on(Function f) {
// 	for (auto interval : this -> disconnection_intervals) {
// 		this -> node_timer -> sleep_until(std::get<1>(interval));
// 		f();
// 	}
// }