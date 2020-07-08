#pragma once

#include <string>
#include <list>

#include "../message_helper.h"

struct WorkerTask {
	static std::list<WorkerTask *> string_to_worker_tasks(std::string tasks_str, std::string binary_name) {
		std::list<WorkerTask *> tasks_list;

		std::cout << "<DEBUG>" << "SUP " << tasks_str << std::endl;

		std::list<std::string> tasks_str_list = MessageHelper::split_by_spaces(tasks_str);

		std::cout << "<DEBUG>" << "FINISHED SPLIT BY SPACES" << std::endl;

		for (std::string task_str : tasks_str_list) {
			int map_index = std::stoi(MessageHelper::get_value_for("map_index:", task_str));
			long iterations = std::stol(MessageHelper::get_value_for(",iterations:", task_str));

			std::cout << "<DEBUG>" << "IM IN THE FOR" << std::endl;

			tasks_list.push_back(new WorkerTask(map_index, iterations, binary_name));
		}

		return tasks_list;
	}

	WorkerTask(int map_index, long iterations, std::string binary_name) {
		this -> map_index = map_index;
		this -> iterations = iterations;
		this -> binary_name = binary_name;
	}
	
	int map_index;
	long iterations;
	std::string binary_name;
};