#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <list>

#include <mutex>

#include <memory>

#include "pending_map_task.h"

#include "../redundancy_mode.h"
#include "../node_timer.h"

#include "../../../simgrid/opportunistic_network_experiments/utils/utils.cpp"

class PendingMapReduce {
public:

	PendingMapReduce(int index, int initial_threshold, int criticality, double start_time, std::list<std::shared_ptr<PendingMapTask>> pending_maps, NodeTimer *node_timer);

	std::list<std::shared_ptr<std::list<std::shared_ptr<PendingMapTask>>>> get_distributed_tasks_by_bucket(int buckets_available);

	int get_index();
	int get_threshold();
	int get_total_maps();
	int get_original_total_maps();
	int get_criticality();
	int get_pending_maps_size();
	int get_times_of_send();
	double get_start_time();
	double get_priority();

	void set_threshold(int threshold);
	int set_times_of_send(int times_of_send);
	// Returns the finished map task or NULL if it wasn't found (which means that the task was already finished)
	std::shared_ptr<PendingMapTask> set_map_task_as_finished(int map_task_index);

	bool operator<(PendingMapReduce &e1);

private:

	double get_lifetime();

	// Distributes the tasks on the buckets as evenly as possible in groups
	std::list<std::shared_ptr<std::list<std::shared_ptr<PendingMapTask>>>> distribute_replication_between_buckets(
		int amount_of_partitions,
		std::list<std::shared_ptr<PendingMapTask>> maps_in_buckets
	);

	// One task for each bucket and then fill up any empty bucket with copies of the other buckets (as evenly as possible)
	std::list<std::shared_ptr<std::list<std::shared_ptr<PendingMapTask>>>> distribute_tasks_individually_and_replicate_to_fill_empty_nodes(
		int amount_of_partitions,
		std::list<std::shared_ptr<PendingMapTask>> maps_in_buckets
	);

	void add_grouped_redundancy_to_bucketed_tasks(std::list<std::shared_ptr<std::list<std::shared_ptr<PendingMapTask>>>> &partitioned_tasks);

	RedundancyMode get_redundancy_mode(int workers_available);

	int index;
	int threshold;
	int total_maps;
	int original_total_maps;
	int criticality;
	double start_time;
	std::list<std::shared_ptr<PendingMapTask>> pending_maps;

	NodeTimer *node_timer;

	// std::mutex pending_maps_access_mutex;

	int times_of_send = 0;
};