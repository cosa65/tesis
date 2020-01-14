#pragma once

#include <simgrid/s4u.hpp>
#include "message_helper.h"
#include "mailboxes_manager.h"

class MapReduceWorker {
public:
	MapReduceWorker(void *message_raw, simgrid::s4u::Mailbox* receive_mailbox, MailboxesManager *mailboxes_manager);
	void operator()();

private:
	void *message_raw;
	simgrid::s4u::Mailbox* receive_mailbox;
	MailboxesManager *mailboxes_manager;
};