#ifndef DATABASE_H
#define DATABASE_H


#include "account.h"
#include "Commit_Confirmation.h"
#include "Consensus_Node.h"
#include "Issue.h"
#include "Ledger.h"
#include "Prepare_Confirmation.h"
#include "Transfer.h"

namespace Data
{
	class DataBase
	{
	public:
		DataBase();
		virtual ~DataBase();
		virtual void checkCreateTables() = 0;
		virtual void insertAccount(Account acc) = 0;
		virtual void insertCommitConfimation(Commit_Confirmation cmcf) = 0;
		virtual void insertConsensusNode(Consensus_Node cn) = 0;
		virtual void insertIssue(Issue is) = 0;
		virtual void insertLedger(Ledger ld) = 0;
		virtual void insertPrepareConfirmation(Prepare_Confirmation pc) = 0;
		virtual void insertTransfer(Transfer tr) = 0;
	};
}

#endif // !DATABASE_H