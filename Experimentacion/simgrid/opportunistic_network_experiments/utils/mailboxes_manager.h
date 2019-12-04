#include<iostream>
#include<map>
#include<set>

class MailboxesManager {
public:
	MailboxesManager();
	bool is_disconnected(std::string mailbox_id);
	void set_disconnected(std::string mailbox_id);
	void set_connected(std::string mailbox_id);

private:
	std::set<std::string> disconnected_mailboxes;
};