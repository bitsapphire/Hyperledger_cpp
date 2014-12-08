#ifndef PREPARE_CONFIRMATION_H
#define PREPARE_CONFIRMATION_H

namespace Data
{
	class Prepare_Confirmation
	{
		std::string _node;
		std::string _signature;
		int _confirmable_id;
		std::string _confirmable_type;
	public:
		Prepare_Confirmation();
		~Prepare_Confirmation();
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