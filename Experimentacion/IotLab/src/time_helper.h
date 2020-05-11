#pragma once

#include <chrono>

class TimeHelper {
public:
	static double now_in_milliseconds() {
		std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
		auto duration = now.time_since_epoch();
		return std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
	}
};
