#include <string>
#include <iostream>

int main(int argc, char *argv[]) {
	std::cout << "Task started" << std::endl;
	
	int iterations = std::stoi(argv[1]);
	int performance_multiplier = std::stoi(argv[2]);

	std::cout << "Iterations: " << iterations << ", performance_multiplier: " << performance_multiplier << std::endl;

	float number = 1.5;

	for (int z = 0; z < performance_multiplier; z++) {
		for (int j = 0; j < 10000; j++) {
			for (long i = 0; i < iterations; i++) {
				number*=number;
			}
			number = 0;
		}
	}

	std::cout << "Finished fors" << std::endl;

	std::cout << "iterations: " << iterations << ", number: " << number << std::endl;

	return 0;
}