#pragma once

#include <simgrid/s4u.hpp>
#include "message_helper.h"
#include "mailboxes_manager.h"

class MapReduceWorker {
public:
	static void setup_map_worker_in_this_host(MailboxesManager *mailboxes_manager);

	static MailboxesManager *mailboxes_manager;

	MapReduceWorker(void *message_raw, simgrid::s4u::Mailbox* receive_mailbox);
	void operator()();

private:
	void *message_raw;
	simgrid::s4u::Mailbox* receive_mailbox;
};