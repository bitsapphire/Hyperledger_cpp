#ifndef TRANSFER_H
#define TRANSFER_H

#include "IConfirmable.h"
namespace Data
{
	using namespace crypto;
	class Transfer :
		public IConfirmable
	{
	private:
		double _amount;
		double _source_id;
		double _destination_id;
		int _prepared = 0;
		int _committed = 0;
		std::string _uuid;
		std::string _resource_signature;
	public:
		double get_amount() const { return _amount; }
		void set_amount(double val) { _amount = val; }
		__int64 get_source_id() const { return _source_id; }
		void set_source_id(__int64 val) { _source_id = val; }
		__int64 get_destination_id() const { return _destination_id; }
		void set_destination_id(__int64 val) { _destination_id = val; }
		int get_prepared() const { return _prepared; }
		void set_prepared(int val) { _prepared = val; }
		int get_commited() const { return _committed; }
		void set_commited(int val) { _committed = val; }
		std::string get_uuid() const { return _uuid; }
		void set_uuid(std::string val) { _uuid = val; }
		std::string get_resource_signature() const { return _resource_signature; }
		void set_resource_signature(std::string val) { _resource_signature = val; }
		Transfer();
		~Transfer();
	};
}
#endif