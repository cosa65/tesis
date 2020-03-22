#include <iostream>
#include <list>

class NodePerformance {
public:
	NodePerformance(std::string node_id);

	void add_response_time(double newest_response_time);
	double get_node_performance();
	std::string get_node_id();

	bool operator<(NodePerformance e1);

	double response_time_mean();
private:
	static double best_response_time;
	static double worse_response_time;


	std::string node_id;
	// Maximum size 4 (we'll try changing this number), since network is very dynamic older values may not be accurate at all
	std::list<double> latest_response_times;
};