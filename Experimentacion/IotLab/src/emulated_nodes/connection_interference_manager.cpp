#include "connection_interference_manager.h"

ConnectionInterferenceManager::ConnectionInterferenceManager(NodeTimer node_timer):
	node_timer(node_timer) 
	{}

void ConnectionInterferenceManager::load_disconnection_intervals(std::list< std::tuple<double, double> > disconnection_intervals) {
	this -> disconnection_intervals = disconnection_intervals;
}

void ConnectionInterferenceManager::load_disconnection_intervals(int disconnections_line_number) {
	std::cout << "[CONNECTION_INTERFERENCE_MANAGER] About to load stuff" << std::endl;

	std::list< std::tuple<double, double> > disconnection_intervals;

	std::ifstream file;
	file.open("disconnection_intervals_for_all_nodes.txt");

	std::string line;
	// Get line specified in line_number (indexed from 1)
	for(int i = 1; i <= disconnections_line_number; ++i) {
       getline(file, line);
	}

	std::istringstream ss_intervals(line);

	std::cout << "[CONNECTION_INTERFERENCE_MANAGER] Intervals: " << line << std::endl;

	double interval_begin;
	double interval_end;

	while(ss_intervals >> interval_begin) {
		ss_intervals >> interval_end;

		std::cout << "[CONNECTION_INTERFERENCE_MANAGER] Added new interval of disconnection: " << interval_begin << " " << interval_end << std::endl;

		disconnection_intervals.push_back({interval_begin, interval_end});
	}

	std::cout << "[CONNECTION_INTERFERENCE_MANAGER] Finished loading stuff" << std::endl;

	this -> disconnection_intervals = disconnection_intervals;

	file.close();
}

void ConnectionInterferenceManager::start() {}

bool ConnectionInterferenceManager::can_receive_message(MessageHelper::MessageData received_message) {
	double time_of_receipt_message = this -> node_timer.current_time_in_ms();

	return is_connected_now(time_of_receipt_message);
}

bool ConnectionInterferenceManager::is_connected_now(double time_point) {
	for (auto interval : this -> disconnection_intervals) {
		if (time_point >= std::get<0>(interval) && time_point <= std::get<1>(interval)) {
			return false;
		}
	}

	return true;
}