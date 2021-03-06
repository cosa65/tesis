#include "pending_map_reduce.h"

PendingMapReduce::PendingMapReduce(int index, int initial_threshold, int criticality, double start_time, std::list<std::shared_ptr<PendingMapTask>> pending_maps, NodeTimer *node_timer) :
	index(index),
	threshold(initial_threshold),
	criticality(criticality),
	start_time(start_time),
	pending_maps(pending_maps),
	node_timer(node_timer)
{
	this -> total_maps = pending_maps.size();
	this -> original_total_maps = this -> total_maps;
}

std::list<std::shared_ptr<std::list<std::shared_ptr<PendingMapTask>>>> PendingMapReduce::get_distributed_tasks_by_bucket(int buckets_available) {
	RedundancyMode redundancy_mode = get_redundancy_mode(buckets_available);

	std::list<std::shared_ptr<std::list<std::shared_ptr<PendingMapTask>>>> tasks_bucketed_by_worker;

	if (redundancy_mode == RedundancyMode::shared_replication_by_groups) {
		std::cout << "Index: " << this -> index << ", chose shared replication by groups, buckets_available: " << buckets_available << std::endl;
		tasks_bucketed_by_worker = distribute_replication_between_buckets(buckets_available, this -> pending_maps);
	} else if (redundancy_mode ==  RedundancyMode::individual_tasks_replication) {
		std::cout << "Index: " << this -> index << ", chose individual tasks replication, buckets_available: " << buckets_available << std::endl;
		tasks_bucketed_by_worker = distribute_tasks_individually_and_replicate_to_fill_empty_nodes(buckets_available, this -> pending_maps);
	}

	return tasks_bucketed_by_worker;
}

int PendingMapReduce::get_index() {
	return this -> index;
}

int PendingMapReduce::get_threshold() {
	return this -> threshold;
}

int PendingMapReduce::get_total_maps() {
	return this -> total_maps;
}

int PendingMapReduce::get_original_total_maps() {
	return this -> original_total_maps;
}

int PendingMapReduce::get_criticality() {
	return this -> criticality;
}

int PendingMapReduce::get_pending_maps_size() {
	return this -> pending_maps.size();
}

int PendingMapReduce::get_times_of_send() {
	return this -> times_of_send;
}

double PendingMapReduce::get_start_time() {
	return this -> start_time;
}

double PendingMapReduce::get_priority() {
	double start_time_in_seconds = this -> start_time / (double)1000;

	double adjusted_start_time_in_seconds = start_time_in_seconds >= 1.0 ? start_time_in_seconds : 1.0; 

	double priority = (this -> criticality * adjusted_start_time_in_seconds) * get_pending_maps_size();

	// std::cout << "--------------------------------- Priority of " << this -> index << " ---------------------------------" << std::endl;
	// std::cout << "criticality: " << this -> criticality << std::endl;
	// std::cout << "adjusted_start_time_in_seconds: " << adjusted_start_time_in_seconds << std::endl;
	// std::cout << "get_pending_maps_size(): " << get_pending_maps_size() << std::endl;
	// std::cout << "priority: " << priority << std::endl;
	// std::cout << "-----------------------------------------------------------------------------------------------------" << std::endl;

	return priority;
}

RedundancyMode PendingMapReduce::get_redundancy_mode(int workers_available) {
	return this -> pending_maps.size() > workers_available ? shared_replication_by_groups : individual_tasks_replication;
}

void PendingMapReduce::set_threshold(int threshold) {
	this -> threshold = threshold;
}

int PendingMapReduce::set_times_of_send(int times_of_send) {
	this -> times_of_send = times_of_send;
}

std::shared_ptr<PendingMapTask>PendingMapReduce::set_map_task_as_finished(int task_map_index) {
	auto task_it = std::find_if(
						this -> pending_maps.begin(),
						this -> pending_maps.end(),
						[task_map_index](std::shared_ptr<PendingMapTask> pending_task) {
							return pending_task -> task_index.map_index == task_map_index;
						}
					);

	std::shared_ptr<PendingMapTask>finished_task = (task_it != this -> pending_maps.end()) ? *task_it : NULL;

	// If finished task hasn't already been erased by another thread due to a different node finishing it first, then erase it
	if (finished_task != NULL) {
		this -> pending_maps.erase(task_it);
	}

	return finished_task;
}

// Lower priority value means more important
bool PendingMapReduce::operator<(PendingMapReduce &e1) {
	if (this -> get_priority() == e1.get_priority()) {
		return this -> get_index() < e1.get_index();
	}
	
	return this -> get_priority() > e1.get_priority();
}

double PendingMapReduce::get_lifetime() {
	return this -> node_timer -> current_time_in_ms() - this -> start_time;
}

// Distributes the tasks on the buckets as equally as possible
std::list<std::shared_ptr<std::list<std::shared_ptr<PendingMapTask>>>> PendingMapReduce::distribute_replication_between_buckets(
	int amount_of_partitions, 
	std::list<std::shared_ptr<PendingMapTask>> maps_in_buckets)
{
	std::list<std::shared_ptr<std::list<std::shared_ptr<PendingMapTask>>>> partitioned_tasks = Utils::separate_in_partitions(maps_in_buckets, amount_of_partitions);
	
	if (partitioned_tasks.size() > 100) {
		auto first_task = *partitioned_tasks.front();
		int a = 1;
	}

	// Each list in this list corresponds to one partition
	if (amount_of_partitions >= 3) {
		add_grouped_redundancy_to_bucketed_tasks(partitioned_tasks);
	}

	return partitioned_tasks;
}

std::list<std::shared_ptr<std::list<std::shared_ptr<PendingMapTask>>>> PendingMapReduce::distribute_tasks_individually_and_replicate_to_fill_empty_nodes(
	int amount_of_partitions,
	std::list<std::shared_ptr<PendingMapTask>> maps_in_buckets) 
{
	std::list<std::shared_ptr<std::list<std::shared_ptr<PendingMapTask>>>> partitioned_tasks = Utils::separate_in_partitions(maps_in_buckets, amount_of_partitions);

	auto tasks_to_replicate_it = partitioned_tasks.begin();

	for(std::shared_ptr<std::list<std::shared_ptr<PendingMapTask>>> partition_ptr : partitioned_tasks) {
		if (partition_ptr -> empty()) {
			partition_ptr -> push_back((*tasks_to_replicate_it) -> front());

			tasks_to_replicate_it++;
		}
	}

	return partitioned_tasks;
}

void PendingMapReduce::add_grouped_redundancy_to_bucketed_tasks(std::list<std::shared_ptr<std::list<std::shared_ptr<PendingMapTask>>>> &partitioned_tasks) {
	// This index is used to know where to insert the empty list that matches the current partition 
	// (we don't want redundancy of a task list in its own list)

	int amount_of_redundancy_partitions = partitioned_tasks.size() - 1;
	int index_of_current_partition = 0;

	std::list<std::shared_ptr<std::list<std::shared_ptr<PendingMapTask>>>> redundancy_tasks_to_distribute = Utils::generate_list_with_empty_lists<std::shared_ptr<PendingMapTask>>(partitioned_tasks.size());

	// If map_tasks_in_flops aren´t perfectly split by amount_of_redundancy_partitions, then we should vary the brunt of redundancy in different partitions
	// We can do this by having each partition_to_make_redundant_separated's redundancy tasks begin in different indexes
	// (with splice looking at the % of the partitioned_tasks, which we will call remainder_of_tasks)
	int remainder_of_tasks = amount_of_redundancy_partitions - (partitioned_tasks.size() % amount_of_redundancy_partitions);
	int index_redundancy_splice = remainder_of_tasks % amount_of_redundancy_partitions;

	// We will iterate over all partitions, separating each one into subpartitions to be ditributed into the rest of the partitions
	for (std::shared_ptr<std::list<std::shared_ptr<PendingMapTask>>> partition_to_make_redundant : partitioned_tasks) {
		// Begin distributing redundancy subpartitions at the index where the partitions end,
		// This is to avoid stacking all subpartitions on only a few partitions
		// Each iteration we change the index from which to begin distributing subpartitions with this same logic
		int partition_to_make_redundant_size = partition_to_make_redundant -> size();

		// Separate the current partition in subpartitions to distribute in each of the other partitions
		std::list<std::shared_ptr<std::list<std::shared_ptr<PendingMapTask>>>> partition_to_make_redundant_separated = Utils::separate_in_partitions(*partition_to_make_redundant, amount_of_redundancy_partitions);

		auto start_it = std::next(partition_to_make_redundant_separated.begin(), amount_of_redundancy_partitions - index_redundancy_splice);

		std::list<std::shared_ptr<std::list<std::shared_ptr<PendingMapTask>>>> partition_to_make_redundant_separated_temp;
		// First take the part that goes in the beginning
		partition_to_make_redundant_separated_temp.splice(
			partition_to_make_redundant_separated_temp.begin(),
			partition_to_make_redundant_separated,
			start_it,
			partition_to_make_redundant_separated.end()
		);

		// Then add the rest of the list in the end
		partition_to_make_redundant_separated_temp.splice(
			partition_to_make_redundant_separated_temp.end(),
			partition_to_make_redundant_separated
		);

		// This splice had to be done in two steps with a temp variable because in one in the same list it doesn't have expected behaviour
		partition_to_make_redundant_separated = partition_to_make_redundant_separated_temp;

		// Insert empty subpartition at current partition to make list sizes match when calling join_lists()
		partition_to_make_redundant_separated.insert(std::next(partition_to_make_redundant_separated.begin(), index_of_current_partition), std::make_shared<std::list<std::shared_ptr<PendingMapTask>>>());

		Utils::join_lists(redundancy_tasks_to_distribute, partition_to_make_redundant_separated);

		index_of_current_partition++;

		int nonempty_amount_of_redundancy_subpartitions = std::max((partition_to_make_redundant_size / amount_of_redundancy_partitions), 1);

		// Sizes may not be perfectly split due to redundancy distribution of partitions that weren't perfectly divided
		index_redundancy_splice += nonempty_amount_of_redundancy_subpartitions;
		index_redundancy_splice = index_redundancy_splice % amount_of_redundancy_partitions;
	}

	// Now each list in redundancy_tasks_to_distribute should be joined with its corresponding list in partitioned_tasks
	Utils::join_lists(partitioned_tasks, redundancy_tasks_to_distribute);
}