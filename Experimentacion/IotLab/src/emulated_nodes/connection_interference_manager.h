#pragma once

#include <fstream>
#include <sstream>


#include "node_timer.h"
#include "../message_helper.h"

class ConnectionInterferenceManager {
public:
	ConnectionInterferenceManager(NodeTimer node_timer);
	void load_disconnection_intervals(std::list< std::tuple<double, double> > disconnection_intervals);
	void load_disconnection_intervals(int disconnections_line_number);
	
	void start();
	// Checks against the history of connections to devide whether message can be received or not
	bool can_receive_message(MessageHelper::MessageData received_message);
	bool is_connected_now(double time_point);

private:
	NodeTimer node_timer;
	std::list< std::tuple<double, double> > disconnection_intervals;
};