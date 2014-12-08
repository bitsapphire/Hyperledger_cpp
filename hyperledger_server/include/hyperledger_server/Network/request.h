#ifndef REQUEST_H
#define REQUEST_H

#include <string>
#include <map>
#include <vector>
#include <prettywriter.h>
#include <filestream.h>
#include <cstdio>


namespace hyperledger
{
	class request
	{
	public:
		request();
		request(std::string message_type, std::vector< std::map<std::string, std::string> > parameters, std::string signature, request* original_request);
		~request();
		std::string message_type;
		request* original_request;
		std::vector< std::map<std::string, std::string> > parameters;
		std::string signature;
	};
}
#endif // !REQUEST_H