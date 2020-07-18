#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <list>

#include <mutex>

#include "pending_map_task.h"

#include "../redundancy_mode.h"

#include "../../../simgrid/opportunistic_network_experiments/utils/utils.cpp"

class PendingMapReduce {
public:

	PendingMapReduce(int index, int initial_threshold, std::list<PendingMapTask *> pending_maps);

	std::list<std::list<PendingMapTask*>*> get_distributed_tasks_by_bucket(int buckets_available);

	int get_index();
	int get_threshold();
	int get_total_maps();
	int get_pending_maps_size();

	void set_threshold(int threshold);
	// Returns the finished map task or NULL if it wasn't found (which means that the task was already finished)
	PendingMapTask *set_map_task_as_finished(int map_task_index);

private:

	// Distributes the tasks on the buckets as evenly as possible in groups
	std::list<std::list<PendingMapTask*>*> distribute_replication_between_buckets(
		int amount_of_partitions,
		std::list<PendingMapTask *> maps_in_buckets
	);

	// One task for each bucket and then fill up any empty bucket with copies of the other buckets (as evenly as possible)
	std::list<std::list<PendingMapTask*>*> distribute_tasks_individually_and_replicate_to_fill_empty_nodes(
		int amount_of_partitions,
		std::list<PendingMapTask *> maps_in_buckets
	);

	RedundancyMode get_redundancy_mode(int workers_available);

	int index;
	int threshold;
	int total_maps;
	std::list<PendingMapTask *> pending_maps;

	std::mutex pending_maps_access_mutex;
};