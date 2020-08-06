#include <iostream>
#include <sstream>
#include <list>
#include <memory>

#include "utils.cpp"

std::string list_to_string(std::list<int> list) {
	std::ostringstream buffer; 
    // buffer << "Product name: "<< description << " Units left: " << on_hand << " Price: "<< price << " Revenue: $" << generated_revenue;

	buffer << "[ ";
	for (int elem : list) {
		buffer << elem << " , ";
	}

	buffer << "]";

    return buffer.str();
}

void print_list_of_lists(std::list<std::shared_ptr<std::list<int>>> list_of_lists) {
	std::cout << "[ " << std::endl;
	for (auto list_ptr : list_of_lists) {
		std::cout << "    " << list_to_string(*list_ptr) << " , " << std::endl;
	}

	std::cout << "]" << std::endl;
}

int main() {
	std::list<int> taskslist = {1,2,3,4,5,6,7,8,9,10,11,12,13};
	std::list<std::shared_ptr<std::list<int>>> empty_lists = Utils::generate_list_with_empty_lists<int>(13);

	auto partitioned_list = Utils::separate_in_partitions(taskslist, 50);
	print_list_of_lists(partitioned_list);

	return 0;
}