#ifndef SQLITEDATABASE_H
#define SQLITEDATABASE_H

#include "DataBase.h"
#include <sqlite3.h>
#include <stdexcept>

namespace Data
{
	static int callback(void *NotUsed, int argc, char **argv, char **azColName);

	class SqliteDataBase :
		public DataBase
	{
	public:
		SqliteDataBase();
		~SqliteDataBase();
		void checkCreateTables() override final;
		void insertAccount(Account acc) override final;
		void insertCommitConfimation(Commit_Confirmation cmcf) override final;
		void insertConsensusNode(Consensus_Node cn) override final;
		void insertIssue(Issue is) override final;
		void insertLedger(Ledger ld) override final;
		void insertPrepareConfirmation(Prepare_Confirmation pc) override final;
		void insertTransfer(Transfer tr) override final;
	};
}

#endif // !SQLITEDATABASE_H
