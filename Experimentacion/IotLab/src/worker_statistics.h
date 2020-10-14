#pragma once

#include <string>
#include <memory>

#include "message_helper.h"

struct WorkerStatistics {
	WorkerStatistics() {};

	WorkerStatistics(double total_execution_time, double total_lifetime, int sent_messages, int total_solved_tasks, int pending_tasks): 
		total_execution_time(total_execution_time),
		total_lifetime(total_lifetime),
		sent_messages(sent_messages),
		total_solved_tasks(total_solved_tasks),
		pending_tasks(pending_tasks)
	{}

	WorkerStatistics(MessageHelper::MessageData *message_data_ptr) {
		std::string total_execution_time_str = message_data_ptr -> get_value_for("total_execution_time:");
		std::string total_lifetime_str = message_data_ptr -> get_value_for("total_lifetime:");
		std::string sent_messages_str = message_data_ptr -> get_value_for("sent_messages:");
		std::string total_solved_tasks_str = message_data_ptr -> get_value_for("total_solved_tasks:");
		std::string pending_tasks_str = message_data_ptr -> get_value_for("pending_tasks:");

		long total_execution_time = stol(total_execution_time_str);
		long total_lifetime = stol(total_lifetime_str);
		int sent_messages = stoi(sent_messages_str);
		int total_solved_tasks = stoi(total_solved_tasks_str);
		int pending_tasks = stoi(pending_tasks_str);

		this -> total_execution_time = total_execution_time;
		this -> total_lifetime = total_lifetime;
		this -> sent_messages = sent_messages;
		this -> total_solved_tasks = total_solved_tasks;
		this -> pending_tasks = pending_tasks;
	}

	double total_execution_time;
	double total_lifetime;
	int sent_messages;
	int total_solved_tasks;
	int pending_tasks;
};