#ifndef COMMIT_CONFIRMATION_H
#define COMMIT_CONFIRMATION_H
#include <string>
namespace Data
{
	class Commit_Confirmation
	{
		std::string _node;
		std::string _signature;
		int _confirmable_id;
		std::string _confirmable_type;
	public:
		Commit_Confirmation();
		Commit_Confirmation(std::string node, std::string signature, int confirmable_id, std::string confirmable_type);
		~Commit_Confirmation();

		std::string get_node() const { return _node; }
		void set_node(std::string val) { _node = val; }
		std::string get_signature() const { return _signature; }
		void set_signature(std::string val) { _signature = val; }
		int get_confirmable_id() const { return _confirmable_id; }
		void set_confirmable_id(int val) { _confirmable_id = val; }
		std::string get_confirmable_type() const { return _confirmable_type; }
		void set_confirmable_type(std::string val) { _confirmable_type = val; }
	};
}
#endif