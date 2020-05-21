#include "connection_interference_manager.h"

ConnectionInterferenceManager::ConnectionInterferenceManager() {}

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

void ConnectionInterferenceManager::start() {
	std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
	auto duration = now.time_since_epoch();
	this -> begin_time_in_ms = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
}

bool ConnectionInterferenceManager::can_receive_message(MessageHelper::MessageData received_message) {
	std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
	auto duration = now.time_since_epoch();
	double now_in_ms = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();

	double relative_time_of_receipt_message = now_in_ms - (this -> begin_time_in_ms);

	return is_connected_at_relative_time_in_ms(relative_time_of_receipt_message);
}

bool ConnectionInterferenceManager::is_connected_at_relative_time_in_ms(double time_point) {
	for (auto interval : this -> disconnection_intervals) {
		if (time_point >= std::get<0>(interval) && time_point <= std::get<1>(interval)) {
			return false;
		}
	}

	return true;
}