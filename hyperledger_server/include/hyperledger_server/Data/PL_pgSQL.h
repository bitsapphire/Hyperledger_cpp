#ifndef PL_PGSQL_H
#define PL_PGSQL_H

#include "DataBase.h"
#include <stdexcept>


namespace Data
{
	class PL_pgSQL : public Data::DataBase
	{
	public:
		PL_pgSQL();
		~PL_pgSQL();
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

#endif