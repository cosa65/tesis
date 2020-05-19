#pragma once

#include <chrono>

#include "../message_helper.h"

class ConnectionInterferenceManager {
public:
	ConnectionInterferenceManager();
	ConnectionInterferenceManager(std::list< std::tuple<double, double> > disconnection_intervals);

	void start();
	// Checks against the history of connections to devide whether message can be received or not
	bool can_receive_message(MessageHelper::MessageData received_message);
	bool is_connected_at_relative_time_in_ms(double time_point);

private:
	double begin_time_in_ms;
	std::list< std::tuple<double, double> > disconnection_intervals;
};