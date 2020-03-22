#include "utils.h"

XBT_LOG_EXTERNAL_DEFAULT_CATEGORY(logging);

namespace Utils {
	std::list<std::list<long>*> generate_list_with_empty_lists(int size) {
		std::list<std::list<long>*> *result = new std::list<std::list<long>*>(size);
		std::generate(result -> begin(), result -> end(), [](){ return new std::list<long>(); });

		return *result;
	}

	// Takes a list of ints and returns the same elements separated in amount_of_partitions lists of roughly the same size (as much as possible)
	std::list<std::list<long>*> separate_in_partitions(std::list<long> list, int amount_of_partitions) {
		int partition_size = list.size() / amount_of_partitions;

		// If list.size() < amount_of_partitions then we will have some empty partitions, that's why partitions_list is filled up first with empty lists
		if (partition_size == 0) { partition_size = 1; }
		std::list<std::list<long>*> partitions_list = generate_list_with_empty_lists(amount_of_partitions);

		auto list_it = list.begin();
		auto partitions_list_it = partitions_list.begin();
		// First, insert partition_size elements in each list
		for (; partition_size <= std::distance(list_it, list.end()); std::advance(list_it, partition_size)) {
			std::list<long> *partition = new std::list<long>();

			partition -> insert(partition -> begin(), list_it, std::next(list_it, partition_size));
			
			// The ith empty list now is replaced with the partition we just generated with the next partition_size elements starting from list_it
			*partitions_list_it = partition;
			partitions_list_it++;
		}

		// If list size isn't perfectly divisible by amount_of_partitions, then some elements are going to have to be distributed one by one
		// (and we'll have lists that differ in size by 1)
		auto partitions_it = partitions_list.begin();
		for (; list_it != list.end(); list_it++) {
			
			(*partitions_it) -> push_back(*list_it);
			partitions_it++;
		}

		return partitions_list;
	}

	// Takes two partitions and concatenates each list of list1 with its corresponding (same index) list in list2
	void join_lists(std::list<std::list<long>*> list1, std::list<std::list<long>*> list2) {
		if (list1.size() != list2.size()) {
			XBT_INFO("At join_lists(), list sizes should be the same, list1: %i and list2: %i", list1.size(), list2.size());
			throw "At join_lists(), list sizes should be the same";
		}

		auto list1_it = list1.begin();
		auto list2_it = list2.begin();

		while (list1_it != list1.end()) {
			(*list1_it) -> splice((*list1_it) -> end(), **list2_it);

			list1_it++;
			list2_it++;
		}
	}
}