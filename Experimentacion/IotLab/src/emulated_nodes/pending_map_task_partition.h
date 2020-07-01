#pragma once

#include <string>
#include <map>

#include "../time_helper.h"

struct PendingMapTaskPartition {
	// map_partition_index is an integer that represents the index of the subarray that is being mapped (so its value range is from 0 .. array_size/subarray_size - 1)
	PendingMapTaskPartition(int map_partition_index, std::list<long> iterations, int map_index_start) {
		this -> map_partition_index = map_partition_index;
		this -> finished = false;
		
		int map_index_it = map_index_start;

		for (long iteration : iterations) {
			map_tasks_by_index[map_index_it] = iteration;
			map_index_it++;
		}
	}

	// This is not currently working (and not under use anymore) TODO decide if remove this completely or not
	double time_since_creation(std::string worker_id) {
		return TimeHelper::now_in_milliseconds() - start_times_by_worker_ids[worker_id];
	}

	void add_new_worker(std::string worker_id) {
		start_times_by_worker_ids[worker_id] = TimeHelper::now_in_milliseconds();
	}

	void mark_as_finished() {
		this -> finished = true;
	}

	std::string get_task_data(int map_index) {
		std::string task_data = "iterations:" + std::to_string(map_tasks_by_index[map_index]) + ",index:" + std::to_string(map_index);
		return task_data;
	}

	int map_partition_index;
	std::map<std::string, double> start_times_by_worker_ids;
	std::map<int, long> map_tasks_by_index;
	bool finished;
};