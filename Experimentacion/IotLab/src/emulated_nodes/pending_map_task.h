#pragma once

#include <string>
#include <map>
#include <list>

#include "../time_helper.h"

struct PendingMapTask {
	// map_index is an integer that represents the index of the subarray that is being mapped (so its value range is from 0 .. array_size/subarray_size - 1)
	PendingMapTask(int map_index, long iterations) {
		this -> map_index = map_index;
		this -> iterations = iterations;
		this -> finished = false;
	}

	std::string get_task_data() {
		std::string task_data = "map_index:" + std::to_string(this -> map_index) + ",iterations:" + std::to_string(this -> iterations);
		return task_data;
	}

	double time_since_creation(std::string worker_id) {
		return TimeHelper::now_in_milliseconds() - start_times_by_worker_ids[worker_id];
	}

	void add_new_worker(std::string worker_id) {
		start_times_by_worker_ids[worker_id] = TimeHelper::now_in_milliseconds();
	}

	void mark_as_finished() {
		this -> finished = true;
	}

	int map_index;
	long iterations;
	std::map<std::string, double> start_times_by_worker_ids;
	bool finished;
};