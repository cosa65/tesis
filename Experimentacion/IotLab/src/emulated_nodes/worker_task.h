#pragma once

#include <string>
#include <list>

#include "../message_helper.h"

struct WorkerTask {
	static std::list<WorkerTask *> string_to_worker_tasks(std::string tasks_str, std::string binary_name) {
		std::list<WorkerTask *> tasks_list;

		std::list<std::string> tasks_str_list = MessageHelper::split_by_spaces(tasks_str);

		for (std::string task_str : tasks_str_list) {
			std::string task_index = MessageHelper::get_value_for("task_index:", task_str);
			long iterations = std::stol(MessageHelper::get_value_for(",iterations:", task_str));

			tasks_list.push_back(new WorkerTask(task_index, iterations, binary_name));
		}

		return tasks_list;
	}

	WorkerTask(std::string task_index, long iterations, std::string binary_name) {
		this -> task_index = task_index;
		this -> iterations = iterations;
		this -> binary_name = binary_name;
	}
	
	std::string task_index;
	long iterations;
	std::string binary_name;
};