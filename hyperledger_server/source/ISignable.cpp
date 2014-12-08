#include "ISignable.h"
#include <stdexcept>

crypto::ISignable::ISignable()
{

}


crypto::ISignable::~ISignable()
{

}

int crypto::ISignable::encryptRSA(char* data, char** enc, char** iv, char** p)
{
	//TODO: Add method implementation here
	throw std::logic_error("This method or operation is under development.");
}