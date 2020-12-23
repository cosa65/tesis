#include <iostream>
#include <string>

#include "node_timer.h"

#define VERBOSE "verbose"
#define SILENT "silent"

int run_operation(const long performance_multiplier, const long iterations, NodeTimer *node_timer, std::string verbosity) {
	if (verbosity == VERBOSE) {
		std::cout << node_timer -> time_log() << "----------------------------RUNNING OPERATION----------------------------" << std::endl;
	}

	double start_time = node_timer -> current_time_in_ms();
	int a;

	float number = 1.5;

	for (int z = 0; z < performance_multiplier; z++) {
		for (int j = 0; j < 10000; j++) {
			for (long i = 0; i < iterations; i++) {
				number*=number;
			}
			number = 0;
		}
	}

	double end_time = node_timer -> current_time_in_ms();

	if (verbosity == VERBOSE) {
		std::cout << node_timer -> time_log() << "____________________________FINISHED OPERATION___________________________" << std::endl;
	}

	double execution_time = end_time - start_time;

	if (verbosity == VERBOSE) {
		std::cout << "Total execution time: " << execution_time << std::endl;
	}

	return a;
}

int main(int argc, char *argv[]) {
	long iterations = std::stol(argv[1]);
	long performance_multiplier = std::stol(argv[2]);
	std::string verbosity = argv[3];

	NodeTimer *node_timer = new NodeTimer();
	node_timer -> start();

	int result = run_operation(iterations, performance_multiplier, node_timer, verbosity);

	return 0;
}