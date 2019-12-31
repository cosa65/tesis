#include <chrono>
#include <string>

struct PendingMapTask {
	// map_index is an integer that represents the index of the subarray that is being mapped (so its value range is from 0 .. array_size/subarray_size - 1)
	int map_index;
	std::string worker_id;
	std::chrono::steady_clock::time_point time_created;

	PendingMapTask(int map_index, std::string worker_id) {
		this -> map_index = map_index;
		this -> worker_id = worker_id;
		this -> time_created = std::chrono::steady_clock::now();
	}
};