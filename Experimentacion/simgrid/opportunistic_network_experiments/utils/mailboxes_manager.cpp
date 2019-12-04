#include"mailboxes_manager.h"

MailboxesManager::MailboxesManager() {}

bool MailboxesManager::is_disconnected(std::string mailbox_id) {
	return disconnected_mailboxes.find(mailbox_id) != disconnected_mailboxes.end();
}

void MailboxesManager::set_disconnected(std::string mailbox_id) {
	disconnected_mailboxes.insert(mailbox_id);
}

void MailboxesManager::set_connected(std::string mailbox_id) {
	disconnected_mailboxes.erase(mailbox_id);
}