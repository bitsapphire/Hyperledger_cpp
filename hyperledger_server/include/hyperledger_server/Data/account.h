#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "ISignable.h"
#include "IConfirmable.h"
#include "Token.h"
#include <string>

namespace Data
{
	enum AccountEntryReason
	{
		LedgerChanged,
		Income,
		Outcome,
		Lock,
		Unlock
	};

	enum AccountType
	{
		Public = 0
	};

	using namespace crypto;
	class Account :
		public ISignable, public IConfirmable
	{
	private:
		std::string _code;
		AccountType _accountType;
		std::string _publicKey;
		__int64 _ledgerId;
		utility::Token _tokens;
		int _prepared = 0;
		int _committed = 0;
	public:
		std::string get_code() const { return _code; }
		void set_code(std::string val) { _code = val; }
		Data::AccountType get_accountType() const { return _accountType; }
		void set_accountType(Data::AccountType val) { _accountType = val; }
		std::string get_publicKey() const { return _publicKey; }
		void set_publicKey(std::string val) { _publicKey = val; }
		__int64 get_ledgerId() const { return _ledgerId; }
		void set_ledgerId(__int64 val) { _ledgerId = val; }
		utility::Token get_tokens() const { return _tokens; }
		void set_tokens(utility::Token val) { _tokens = val; }
		int get_prepared() const { return _prepared; }
		void set_prepared(int val) { _prepared = val; }
		int get_commited() const { return _committed; }
		void set_commited(int val) { _committed = val; }
		Account();
		Account(std::string code, AccountType accountType, std::string publickey, __int64 ledgerId, utility::Token tokens, bool prepared, bool committed);
		~Account();
	};
}


#endif