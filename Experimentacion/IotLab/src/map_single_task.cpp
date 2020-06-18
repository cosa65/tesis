#include <string>
#include <iostream>

int main(int argc, char *argv[]) {
	long iterations = std::stol(argv[1]);
	int performance_multiplier = std::stoi(argv[2]);

	int a = 0;

	for (int z = 0; z < performance_multiplier; z++) {
		for (int j = 0; j < 1000000; j++) {
			for (long i = 0; i < iterations; i++) {
				a = i * 20 + 100;
			}
		}
	}

	return 0;
}