#ifndef LEDGER_H
#define LEDGER_H

#include "ISignable.h"
#include "IConfirmable.h"
#include "Account.h"
#include "Issue.h"
#include "stdafx.h"

namespace Data
{
	using namespace crypto;
	class Ledger : 
		public IConfirmable, public ISignable
	{
	private:
		void broadCastParameters();
		std::vector<Account> _accounts;
		std::vector<Issue> _issues;
		std::string	_url;
		std::string _name;
		std::string _publicKey;
		int _primary_account_id;
		int _prepared = 0;
		int _committed = 0;
	public:
		std::vector<Account> get_accounts() const { return _accounts; }
		void set_accounts(std::vector<Account> val) { _accounts = val; }
		std::vector<Issue> get_issues() const { return _issues; }
		void set_issues(std::vector<Issue> val) { _issues = val; }
		std::string get_name() const { return _name; }
		void set__name(std::string val) { _name = val; }
		std::string get_publicKey() const { return _publicKey; }
		void set_publicKey(std::string val) { _publicKey = val; }
		std::string get_url() const { return _url; }
		void set_url(std::string val) { _url = val; }
		int get_primary_account_id() const { return _primary_account_id; }
		void set_primary_account_id(int val) { _primary_account_id = val; }
		int get_prepared() const { return _prepared; }
		void set_prepared(int val) { _prepared = val; }
		int get_commited() const { return _committed; }
		void set_commited(int val) { _committed = val; }
		Ledger();
		~Ledger();
	};
}

#endif