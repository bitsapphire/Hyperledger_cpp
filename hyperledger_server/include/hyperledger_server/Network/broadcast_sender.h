#ifndef BROADCAST_SENDER_H
#define BROADCAST_SENDER_H

#include "request.h"
#include "consensus_node.h"
#include <vector>


namespace hyperledger
{
	class broadcast_sender
	{
	public:
		void broadcast_request(std::vector<Data::Consensus_Node> nodes, hyperledger::request req);
		broadcast_sender();
		~broadcast_sender();
	};
}

#endif // !BROADCAST_SENDER_H