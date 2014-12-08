#include "request.h"


hyperledger::request::request()
{
}

hyperledger::request::request(std::string message_type, std::vector< std::map<std::string, std::string> > parameters, std::string signature, request* original_request)
{
	this->message_type = message_type;
	this->parameters = parameters;
	this->signature = signature;
	this->original_request = original_request;
}

hyperledger::request::~request()
{
}