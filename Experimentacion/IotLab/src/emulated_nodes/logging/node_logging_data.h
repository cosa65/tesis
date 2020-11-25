#pragma once

#include <memory>

#include "../pending_map_reduce.h"

struct NodeLoggingData {
  NodeLoggingData(int index, double start_time, double execution_time, int amount_of_maps) {
    this -> index = index;
    this -> start_time = start_time;
    this -> execution_time = execution_time;
    this -> amount_of_maps = amount_of_maps;
  }

  static std::shared_ptr<NodeLoggingData> from(std::shared_ptr<PendingMapReduce> pending_map_reduce_ptr, double finish_time) {
    int index = pending_map_reduce_ptr -> get_index();
    int amount_of_maps = pending_map_reduce_ptr -> get_original_total_maps();
		double start_time = pending_map_reduce_ptr -> get_start_time();
		double execution_time = finish_time - start_time;


    return std::make_shared<NodeLoggingData>(index, start_time, execution_time, amount_of_maps);
  }

  int index;
  double start_time;
  int amount_of_maps;
  double execution_time;
};