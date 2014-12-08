#ifndef CONSENSUS_NODE
#define CONSENSUS_NODE


#include "ISignable.h"

namespace Data
{
	using namespace crypto;
	class Consensus_Node :
		public ISignable
	{
	private:
		std::string _url;
		std::string _publicKey;
	public:
		Consensus_Node();
		Consensus_Node(std::string url, std::string publickey);
		~Consensus_Node();
		std::string get_publicKey() const { return _publicKey; }
		void set_publicKey(std::string val) { _publicKey = val; }
		std::string get_url() const { return _url; }
		void set_url(std::string val) { _url = val; }
	};
}
#endif