#include "tcp_listener.h"



hyperledger::tcp_listener::~tcp_listener()
{

}


void hyperledger::tcp_listener::listen()
{
	try
	{
		while (true)
		{
			//_socket.async_read_some();
			//TODO: Add method implementation here
			throw std::logic_error("This method or operation is under development.");
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
}