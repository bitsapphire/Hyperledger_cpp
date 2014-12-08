#ifndef NODE_H
#define NODE_H

#include "Ledger.h"
#include "account.h"
#include "request.h"
#include "broadcast_sender.h"
#include "DataBase.h"
#include "SqliteDataBase.h"
#include "PL_pgSQL.h"
#include "request_interpreter.h"
#include <rapidjson.h>
#include <document.h>
#include <writer.h>
#include <stringbuffer.h>
#include <vector>

namespace hyperledger
{
	class Node :
		public hyperledger::request_interpreter
	{
	private:
		std::vector < Data::Ledger > _ledgers;
		std::vector < hyperledger::request > _requests;
		hyperledger::broadcast_sender _broadcast_sender;
		void create_user(rapidjson::Document document);
		void create_ledger(rapidjson::Document document);
		void create_transfer(rapidjson::Document document);
		void bc_create_user(rapidjson::Document document);
		void bc_create_ledger(rapidjson::Document document);
		void bc_create_transfer(rapidjson::Document document);
		void bc_cf_transfer(rapidjson::Document document);
		std::string _private_key;
	public:
		void handle_request(std::string data);
		void handle_request(char * data);
		Node();
		~Node();
	};
}
#endif