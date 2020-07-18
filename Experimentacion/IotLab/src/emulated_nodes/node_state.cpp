#include "node_state.h"
	// std::list<long> latest_response_times;

#define NOT_SET -1

// int NodeState::responses_history_max_size;
double NodeState::best_response_time = NOT_SET;
double NodeState::worse_response_time = NOT_SET;

NodeState::NodeState(std::string node_id) {
	this -> node_id = node_id;
}

void NodeState::add_response_time(double newest_response_time) {
	latest_response_times.push_back(newest_response_time);

	// // If we have a longer history than the maximum allowed, remove the oldest response time log
	// if (latest_response_times.size() > NodeState::responses_history_max_size) {
	// 	latest_response_times.pop_front();
	// }

	// The cases of best_response_time being NOT_SET and worse_response_time not or viceversa are impossible
	if (NodeState::best_response_time == NOT_SET && NodeState::worse_response_time == NOT_SET) {
		NodeState::best_response_time = newest_response_time;
		NodeState::worse_response_time = newest_response_time;
		return;
	}

	if (newest_response_time < NodeState::best_response_time) {
		NodeState::best_response_time = newest_response_time;
		return;
	}

	if (newest_response_time > NodeState::worse_response_time) {
		NodeState::worse_response_time = newest_response_time;
		return;
	}
}

void NodeState::add_task(std::string task_id_str) {
	this -> current_tasks_set.insert(task_id_str);
}

void NodeState::remove_task(std::string task_id_str) {
	this -> current_tasks_set.erase(task_id_str);
}

bool NodeState::node_is_idle() {
	bool is_performing_benchmark = this -> current_tasks_set.find("-1") != this -> current_tasks_set.end();
	bool is_performing_only_benchmark = this -> current_tasks_set.size() == 1 && is_performing_benchmark;

	return this -> current_tasks_set.empty() || is_performing_only_benchmark;
}

double NodeState::get_node_performance() {
	double range_of_percentage = NodeState::worse_response_time - NodeState::best_response_time;

	// If we have no values or only one value (so range_of_percentage == 0) then return same thing for every node
	if (this -> latest_response_times.empty() || range_of_percentage == 0) {
		return 50.0;
	}

	double relative_response_time_mean = response_time_mean() - NodeState::best_response_time;

	double percentage_performance = 100 - (relative_response_time_mean / range_of_percentage) * 100;

	return percentage_performance;
}

std::string NodeState::get_node_id() {
	return this -> node_id;
}

bool NodeState::operator<(NodeState e1) {
	return get_node_performance() < e1.get_node_performance();
}

double NodeState::response_time_mean() {
	double sum = 0;

	for (double response_time : this -> latest_response_times) {
		sum += response_time;
	}

	return sum / (double)this -> latest_response_times.size();
}