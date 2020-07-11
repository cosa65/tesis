#pragma once

#include <mutex>

// Idea taken from https://stackoverflow.com/a/11673600
class PrioritiesMutex {
public:

	enum PriorityOption { high, low };

	PrioritiesMutex() {}

	void lock() {
		lock(low);
	}

	void unlock() {
		unlock(low);
	}

	void lock(PriorityOption priority) {
		if (priority == high) {
			next_to_access_mutex.lock();
			data_mutex.lock();

			next_to_access_mutex.unlock();
		} else {
			low_priority_access_mutex.lock();
			next_to_access_mutex.lock();
			data_mutex.lock();

			next_to_access_mutex.unlock();
		}
	}

	void unlock(PriorityOption priority) {
		if (priority == high) {
			data_mutex.unlock();
		} else {
			data_mutex.unlock();
			low_priority_access_mutex.unlock();
		}
	}

	// Low-priority threads: lock L, lock N, lock M, unlock N, { do stuff }, unlock M, unlock L
	// High-priority thread: lock N, lock M, unlock N, { do stuff }, unlock M

private:

	// M
	std::mutex data_mutex;
	// N
	std::mutex next_to_access_mutex;
	// L
	std::mutex low_priority_access_mutex;
};