#pragma once

#include <string>

struct TaskIndex {
	TaskIndex(int map_reduce_index, int map_index) : map_index(map_index), map_reduce_index(map_reduce_index) {}

	TaskIndex(std::string task_index_str) {
		// "<map_index>|<map_reduce_index>";
		auto delimiter_pos = task_index_str.find("|");

		int map_reduce_index = std::stoi(task_index_str.substr(0, delimiter_pos));
		int map_index = std::stoi(task_index_str.substr(delimiter_pos + 1, task_index_str.length()));

		this -> map_index = map_index;
		this -> map_reduce_index = map_reduce_index;
	}

	bool operator ==(const TaskIndex &other) { 
		return this -> map_index == other.map_index && this -> map_reduce_index == other.map_reduce_index; 
	}

	std::string to_string() {
		return std::to_string(map_reduce_index) + "|" + std::to_string(map_index);
	}

	int map_reduce_index;
	int map_index;
};