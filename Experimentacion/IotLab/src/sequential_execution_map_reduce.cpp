#include <iostream>
#include <string>

#include "node_timer.h"

#define VERBOSE "verbose"
#define SILENT "silent"

int run_operation(const long iterations, NodeTimer *node_timer, std::string verbosity) {
	if (verbosity == VERBOSE) {
		std::cout << node_timer -> time_log() << "----------------------------RUNNING OPERATION----------------------------" << std::endl;
	}

	double start_time = node_timer -> current_time_in_ms();
	int a;

	for (int j = 0; j < 1000000; j++) {
		for (int i = 0; i < iterations; i++) {
			a = i * 20 + 100;
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
	std::string verbosity = argv[2];

	NodeTimer *node_timer = new NodeTimer();
	node_timer -> start();

	int result = run_operation(iterations, node_timer, verbosity);

	return 0;
}