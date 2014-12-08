#include "Account.h"


Data::Account::Account()
{

}

Data::Account::Account(std::string code, AccountType accountType, std::string publickey, __int64 ledgerId, utility::Token tokens, bool prepared, bool committed)
{
	this->_code = code;
	this->_accountType = accountType;
	this->_publicKey = publickey;
	this->_ledgerId = ledgerId;
	this->_tokens = tokens;
	this->_prepared = prepared;
	this->_committed = committed;
}

Data::Account::~Account()
{

}