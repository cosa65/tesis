#pragma once

#include <iostream>
#include <list>
#include <unordered_set>

class NodeState {
public:
	NodeState(std::string node_id);

	void add_response_time(double newest_response_time);

	void add_task(std::string task_id_str);
	void remove_task(std::string task_id_str);
	void remove_all_tasks();
	bool node_is_idle();

	double get_node_performance();
	std::string get_node_id();
	int get_current_tasks_size();

	bool operator<(NodeState &e1);

	double response_time_mean();
private:
	static double best_response_time;
	static double worse_response_time;

	std::string node_id;

	// Maximum size 4 (we'll try changing this number), since network is very dynamic older values may not be accurate at all
	std::list<double> latest_response_times;
	std::unordered_set<std::string> current_tasks_set;
};