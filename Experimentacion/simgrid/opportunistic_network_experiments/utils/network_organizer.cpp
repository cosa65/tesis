#include<iostream>
#include<map>
#include<set>

class NetworkOrganizer {
public:
	NetworkOrganizer();
	bool is_link_active_for(std::string host_id, std::string link_id);
	void set_disconnected_from(std::string host_id, std::string link_id);
	void set_connected_from(std::string host_id, std::string link_id);

private:
	std::map<std::string, set<std::string> > disconnected_links;

	NetworkOrganizer() {}

	bool is_link_active_for(std::string host_id, std::string link_id) {
		auto disconnected_links_for_host = disconnected_links[host_id];

		is_link_in_disconnected_set = disconnected_links_for_host.find(link_id) != container.end();
		return !is_link_in_disconnected_set;
	}

	void set_disconnected_from(std::string host_id, std::string link_id) {
		auto disconnected_links_for_host = disconnected_links[host_id];

		disconnected_links_for_host.insert(link_id);
	}

	void set_connected_from(std::string host_id, std::string link_id) {
		auto disconnected_links_for_host = disconnected_links[host_id];

		disconnected_links_for_host.erase(link_id);
	}
}