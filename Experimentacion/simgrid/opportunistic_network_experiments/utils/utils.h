#pragma once

#include <simgrid/s4u.hpp>
#include <list>
#include <iterator>

namespace Utils {
	std::list<std::list<int>*> generate_list_with_empty_lists(int size); 
	// Returns a list with the elements in the original list separated amount_of_partitions times,
	std::list<std::list<int>*> separate_in_partitions(std::list<int> list, int amount_of_partitions);
	void join_lists(std::list<std::list<int>*> list1, std::list<std::list<int>*> list2);
}