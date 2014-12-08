#ifndef REQUEST_INTERPRETER
#define REQUEST_INTERPRETER
#include <string>

namespace hyperledger
{
	class request_interpreter
	{
	protected:
		request_interpreter();
	public:
		virtual ~request_interpreter();
		virtual void handle_request(std::string data) = 0;
		virtual void handle_request(char * data) = 0;
	};
}
#endif // !NODE_REQUEST_INTERPRETER