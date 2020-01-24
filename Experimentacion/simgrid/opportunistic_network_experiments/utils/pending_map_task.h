#pragma once

#include <chrono>
#include <string>
#include <list>

struct PendingMapTask {
	// map_index is an integer that represents the index of the subarray that is being mapped (so its value range is from 0 .. array_size/subarray_size - 1)
	PendingMapTask(int map_index, std::string worker_id, std::string task_data) {
		this -> map_index = map_index;
		this -> worker_id = worker_id;
		this -> task_data = task_data;
		this -> time_created = std::chrono::steady_clock::now();
	}

	PendingMapTask *copy_task(std::string worker_id) {
		return new PendingMapTask(this -> map_index, worker_id, this -> task_data);
	}

	std::chrono::seconds time_since_creation() {
		auto now = std::chrono::steady_clock::now();
		std::chrono::duration_cast<std::chrono::seconds>(now - time_created).count();
	}

	int map_index;
	std::string worker_id;
	std::string task_data;
	std::chrono::steady_clock::time_point time_created;
};