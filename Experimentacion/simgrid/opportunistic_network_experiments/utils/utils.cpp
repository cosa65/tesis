#pragma once

#include <list>
#include <iterator>
#include <algorithm>
#include <memory>

namespace Utils {
	template <class T>
	std::list<std::shared_ptr<std::list<T>>> generate_list_with_empty_lists(int size) {
		// std::list<std::list<T>*> *result = new std::list<std::list<T>*>(size);
		std::shared_ptr<std::list<std::shared_ptr<std::list<T>>>> result = std::make_shared<std::list<std::shared_ptr<std::list<T>>>>(size);
		std::generate(result -> begin(), result -> end(), [](){ return std::make_shared<std::list<T>>(); });

		return *result;
	}

	// Takes a list of ints and returns the same elements separated in amount_of_partitions lists of roughly the same size (as much as possible)
	template <class T>
	std::list<std::shared_ptr<std::list<T>>> separate_in_partitions(std::list<T> list, int amount_of_partitions) {
		int partition_size = list.size() / amount_of_partitions;

		if (amount_of_partitions == 3 && list.size() == 4) {
			int a = 1;
		}

		// If list.size() < amount_of_partitions then we will have some empty partitions, that's why partitions_list is filled up first with empty lists
		if (partition_size == 0) { partition_size = 1; }
		std::list<std::shared_ptr<std::list<T>>> partitions_list = generate_list_with_empty_lists<T>(amount_of_partitions);

		auto list_it = list.begin();
		auto partitions_list_it = partitions_list.begin();

		// First, insert partition_size elements in each list
		for (; partition_size <= std::distance(list_it, list.end()) && partitions_list_it != partitions_list.end() ; std::advance(list_it, partition_size)) {
			std::shared_ptr<std::list<T>> partition = std::make_shared<std::list<T>>();

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
	template <class T>
	void join_lists(std::list<std::shared_ptr<std::list<T>>> list1, std::list<std::shared_ptr<std::list<T>>> list2) {
		if (list1.size() != list2.size()) {
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