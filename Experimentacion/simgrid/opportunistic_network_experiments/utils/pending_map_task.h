#pragma once

#include <simgrid/s4u.hpp>
#include <chrono>
#include <string>
#include <map>

struct PendingMapTask {
	// map_index is an integer that represents the index of the subarray that is being mapped (so its value range is from 0 .. array_size/subarray_size - 1)
	PendingMapTask(int map_index, std::string task_data) {
		this -> map_index = map_index;
		this -> task_data = task_data;
		this -> finished = false;
	}

	double time_since_creation(std::string worker_id) {
		double now = simgrid::s4u::Engine::get_instance() -> get_clock();
		return now - start_times_by_worker_ids[worker_id];
	}

	void add_new_worker(std::string worker_id) {
		start_times_by_worker_ids[worker_id] = simgrid::s4u::Engine::get_instance() -> get_clock();
	}

	void mark_as_finished() {
		this -> finished = true;
	}

	int map_index;
	std::map<std::string, double> start_times_by_worker_ids;
	std::string task_data;
	bool finished;
};