#include "Issue.h"


Data::Issue::Issue()
{
}

Data::Issue::Issue(__int64 ledgerId, double amount, std::string publickey)
{
	this->_ledgerId = ledgerId;
	this->_amount = amount;
	this->_publicKey = publickey;
}


Data::Issue::~Issue()
{
}
