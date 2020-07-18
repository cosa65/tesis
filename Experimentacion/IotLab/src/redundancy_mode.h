#pragma once

// shared_groups_replication sends one group of tasks to each node and then 
// individual_tasks_replication sends one task to each node and then resends as many tasks as possible to the rest of the idle nodes (if there are any)
enum RedundancyMode { shared_replication_by_groups, individual_tasks_replication };