#pragma once

#include <string>
#include <map>
#include <list>

#include "task_index.h"

#include "../time_helper.h"

struct PendingMapTask {
	// map_index is an integer that represents the index of the subarray that is being mapped (so its value range is from 0 .. array_size/subarray_size - 1)
	PendingMapTask(TaskIndex task_index, long iterations) : 
	task_index(task_index),
	iterations(iterations) 
	{
		this -> finished = false;
	}

	std::string get_task_data() {
		std::string task_data = "task_index:" + this -> task_index.to_string() + ",iterations:" + std::to_string(this -> iterations);
		return task_data;
	}

	double time_since_creation(std::string worker_id) {
		return TimeHelper::now_in_milliseconds() - current_workers_by_worker_ids[worker_id];
	}

	void add_new_worker(std::string worker_id) {
		current_workers_by_worker_ids[worker_id] = TimeHelper::now_in_milliseconds();
	}

	void remove_worker(std::string worker_id) {
		current_workers_by_worker_ids.erase(worker_id);
	}

	void mark_as_finished(std::string finishing_worker) {
		current_workers_by_worker_ids.erase(finishing_worker);

		this -> finished = true;
	}

	TaskIndex task_index;
	long iterations;
	std::map<std::string, double> current_workers_by_worker_ids;
	bool finished;
};