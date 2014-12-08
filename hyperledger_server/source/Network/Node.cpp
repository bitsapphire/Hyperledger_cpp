#include "Node.h"


hyperledger::Node::Node()
{

}


hyperledger::Node::~Node()
{

}

void hyperledger::Node::handle_request(std::string data)
{
	char * chardata = new char[data.length() + 1];
	std::strcpy(chardata, data.c_str());
	handle_request(chardata);
}

void hyperledger::Node::handle_request(char * data)
{
	try
	{
		rapidjson::Document document;
		document.Parse(data);
		rapidjson::Value& message_type = document["type"];
		std::string message_type_string = message_type.GetString();

		if (message_type_string == "createuser")
		{
			//TODO: Call method
		}
		else if (message_type_string == "createledger")
		{
			//TODO: Call method
		}
		else if (message_type_string == "transfer")
		{
			//TODO: Call method
		}
		else if (message_type_string == "bc_createuser")
		{
			//TODO: Call method
		}
		else if (message_type_string == "bc_createledger")
		{
			//TODO: Call method
		}
		else if (message_type_string == "bc_transfer")
		{
			//TODO: Call method
		}
		else if (message_type_string == "cf_transfer")
		{
			//TODO: Call method
		}

	}
	catch (std::exception e) {
		//TODO: Handle exception
	};

}


void hyperledger::Node::create_user(rapidjson::Document document)
{
	//TODO: Add method implementation here
	throw std::logic_error("This method or operation is under development.");
}

void hyperledger::Node::create_ledger(rapidjson::Document document)
{
	//TODO: Add method implementation here
	throw std::logic_error("This method or operation is under development.");
}

void hyperledger::Node::create_transfer(rapidjson::Document document)
{
	//TODO: Add method implementation here
	throw std::logic_error("This method or operation is under development.");
}

void hyperledger::Node::bc_create_user(rapidjson::Document document)
{
	//TODO: Add method implementation here
	throw std::logic_error("This method or operation is under development.");
}

void hyperledger::Node::bc_create_ledger(rapidjson::Document document)
{
	//TODO: Add method implementation here
	throw std::logic_error("This method or operation is under development.");
}

void hyperledger::Node::bc_create_transfer(rapidjson::Document document)
{
	//TODO: Add method implementation here
	throw std::logic_error("This method or operation is under development.");
}

void hyperledger::Node::bc_cf_transfer(rapidjson::Document document)
{
	//TODO: Add method implementation here
	throw std::logic_error("This method or operation is under development.");
}