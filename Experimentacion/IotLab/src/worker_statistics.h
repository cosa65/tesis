#pragma once

#include <string>

struct WorkerStatistics {
	WorkerStatistics() {};

	WorkerStatistics(double total_execution_time, double total_lifetime, int sent_messages): 
		total_execution_time(total_execution_time),
		total_lifetime(total_lifetime),
		sent_messages(sent_messages)
	{}

	double total_execution_time;
	double total_lifetime;
	int sent_messages;
};