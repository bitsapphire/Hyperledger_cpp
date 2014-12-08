#include "Commit_Confirmation.h"


Data::Commit_Confirmation::Commit_Confirmation()
{
}

Data::Commit_Confirmation::Commit_Confirmation(std::string node, std::string signature, int confirmable_id, std::string confirmable_type)
{
	this->_node = node;
	this->_signature = signature;
	this->_confirmable_id = confirmable_id;
	this->_confirmable_type = confirmable_type;
}

Data::Commit_Confirmation::~Commit_Confirmation()
{
}

