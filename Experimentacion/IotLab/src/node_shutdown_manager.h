#pragma once

#include <fstream>
#include <sstream>


#include "node_timer.h"
#include "message_helper.h"

class NodeShutdownManager {
public:
	NodeShutdownManager(NodeTimer *node_timer);
	void load_disconnection_intervals(std::list< std::tuple<double, double> > disconnection_intervals);
	void load_disconnection_intervals(int disconnections_line_number);
	
	void start();
	// Checks against the history of connections to devide whether message can be received or not
	bool can_receive_message(MessageHelper::MessageData received_message);
	bool was_off_during(double start_time, double end_time);
	bool is_connected_now(double time_point);

	template <typename Function>
	void execute_on_turning_on(Function f) {
		for (auto interval : this -> disconnection_intervals) {
			this -> node_timer -> sleep_until(std::get<1>(interval));
			f();
		}
	}

private:
	NodeTimer *node_timer;
	std::list< std::tuple<double, double> > disconnection_intervals;
};