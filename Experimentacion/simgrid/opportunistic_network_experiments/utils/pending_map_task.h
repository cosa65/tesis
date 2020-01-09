#include <chrono>
#include <string>
#include <list>

struct PendingMapTask {
	// map_index is an integer that represents the index of the subarray that is being mapped (so its value range is from 0 .. array_size/subarray_size - 1)
	PendingMapTask(int map_index, std::string worker_id, std::string task_data) {
		this -> map_index = map_index;
		this -> worker_ids.push_back(worker_id);
		this -> task_data = task_data;
		this -> time_created = std::chrono::steady_clock::now();
	}

	void add_worker_to_task(std::string worker_id) {
		worker_ids.push_back(worker_id);
	}

	int map_index;
	std::list<std::string> worker_ids;
	std::string task_data;
	std::chrono::steady_clock::time_point time_created;
};