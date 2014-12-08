#ifndef TCP_LISTENER_H
#define TCP_LISTENER_H

#include <boost/asio.hpp>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/serialization/vector.hpp>


namespace hyperledger
{
	//class multithreaded_server;
	//class threaded_server;
	//class server;


	//Placeholder class
	class tcp_listener
	{
	private: 
		boost::asio::ip::tcp::socket _socket;
		std::vector<char> _data;
	public:
		boost::asio::ip::tcp::socket& socket()
		{
			return _socket;
		}

		void listen();
		tcp_listener(boost::asio::io_service& _service) : _socket(_service) { };
		~tcp_listener();
	};
}
#endif // !TCP_LISTENER_H