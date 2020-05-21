#pragma once

#include <chrono>
#include <fstream>
#include <sstream>


#include "../message_helper.h"

class ConnectionInterferenceManager {
public:
	ConnectionInterferenceManager();
	void load_disconnection_intervals(std::list< std::tuple<double, double> > disconnection_intervals);
	void load_disconnection_intervals(int disconnections_line_number);
	
	void start();
	// Checks against the history of connections to devide whether message can be received or not
	bool can_receive_message(MessageHelper::MessageData received_message);
	bool is_connected_at_relative_time_in_ms(double time_point);

private:
	double begin_time_in_ms;
	std::list< std::tuple<double, double> > disconnection_intervals;
};