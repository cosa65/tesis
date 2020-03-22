#include "node_performance.h"
	// std::list<long> latest_response_times;

#define NOT_SET -1

// int NodePerformance::responses_history_max_size;
double NodePerformance::best_response_time = NOT_SET;
double NodePerformance::worse_response_time = NOT_SET;

NodePerformance::NodePerformance(std::string node_id) {
	this -> node_id = node_id;
}

void NodePerformance::add_response_time(double newest_response_time) {
	latest_response_times.push_back(newest_response_time);

	// // If we have a longer history than the maximum allowed, remove the oldest response time log
	// if (latest_response_times.size() > NodePerformance::responses_history_max_size) {
	// 	latest_response_times.pop_front();
	// }

	// The cases of best_response_time being NOT_SET and worse_response_time not or viceversa are impossible
	if (NodePerformance::best_response_time == NOT_SET && NodePerformance::worse_response_time == NOT_SET) {
		NodePerformance::best_response_time = newest_response_time;
		NodePerformance::worse_response_time = newest_response_time;
		return;
	}

	if (newest_response_time < NodePerformance::best_response_time) {
		NodePerformance::best_response_time = newest_response_time;
		return;
	}

	if (newest_response_time > NodePerformance::worse_response_time) {
		NodePerformance::worse_response_time = newest_response_time;
		return;
	}
}

double NodePerformance::get_node_performance() {
	double range_of_percentage = NodePerformance::worse_response_time - NodePerformance::best_response_time;

	// If we have no values or only one value (so range_of_percentage == 0) then return same thing for every node
	if (this -> latest_response_times.empty() || range_of_percentage == 0) {
		return 50.0;
	}

	double relative_response_time_mean = response_time_mean() - NodePerformance::best_response_time;

	double percentage_performance = 100 - (relative_response_time_mean / range_of_percentage) * 100;

	return percentage_performance;
}

std::string NodePerformance::get_node_id() {
	return this -> node_id;
}

bool NodePerformance::operator<(NodePerformance e1) {
	return get_node_performance() < e1.get_node_performance();
}

double NodePerformance::response_time_mean() {
	double sum = 0;

	for (double response_time : this -> latest_response_times) {
		sum += response_time;
	}

	return sum / (double)this -> latest_response_times.size();
}