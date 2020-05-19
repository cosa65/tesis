#include "connection_interference_manager.h"

ConnectionInterferenceManager::ConnectionInterferenceManager() {}

ConnectionInterferenceManager::ConnectionInterferenceManager(std::list< std::tuple<double, double> > disconnection_intervals) {
	std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
	auto duration = now.time_since_epoch();
	
	this -> begin_time_in_ms = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
	this -> disconnection_intervals = disconnection_intervals;
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
			return true;
		}
	}

	return false;
}