#ifndef ISSUE_H
#define ISSUE_H

#include "IConfirmable.h"
#include <string>
namespace Data
{
	using namespace crypto;
	class Issue : public IConfirmable
	{
		__int64 _ledgerId;
		double _amount;
		std::string _publicKey;

	public:
		Issue();
		Issue(__int64 ledgerId, double amount, std::string publickey);
		~Issue();
		double get_amount() const { return _amount; }
		void set_amount(double val) { _amount = val; }
		__int64 get_ledgerId() const { return _ledgerId; }
		void set_ledgerId(__int64 val) { _ledgerId = val; }
		std::string get_publicKey() const { return _publicKey; }
		void set_publicKey(std::string val) { _publicKey = val; }
	};
}
#endif