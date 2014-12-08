#include "SqliteDataBase.h"

static int Data::callback(void *NotUsed, int argc, char **argv, char **azColName){
	int i;
	for (i = 0; i < argc; i++){
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}


Data::SqliteDataBase::SqliteDataBase()
{

}


Data::SqliteDataBase::~SqliteDataBase()
{

}

void Data::SqliteDataBase::checkCreateTables()
{
	if (utility::file_exists("data.db"))
	{
		sqlite3 *db;
		sqlite3_open("data.db", &db);

		char *zErrMsg = 0;
		int  rc;
		char *sql;

		sql = "DELETE	FROM ACCOUNTS;" \
			"DELETE		FROM COMMITCONFIRMATIONS;" \
			"DELETE		FROM CONSENSUSNODES;" \
			"DELETE		FROM ISSUES;" \
			"DELETE		FROM LEDGERS;" \
			"DELETE		FROM PREPARE_CONFIRMATIONS;" \
			"DELETE		FROM TRANSFERS; ";

		rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
		if (rc != SQLITE_OK){
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		}
	}
	else
	{
		sqlite3 *db;
		sqlite3_open("data.db", &db);
		char *zErrMsg = 0;
		int  rc;
		char *sql;

		sql = "CREATE TABLE ACCOUNTS("  \
			"IDAccount			INTEGER		PRIMARY KEY		AUTOINCREMENT," \
			"Code				TEXT		NOT NULL," \
			"PublicKey			TEXT		NOT NULL," \
			"LedgerID			INT			NOT NULL," \
			"Balance			REAL		NOT NULL," \
			"CreatedAt			TEXT		NOT NULL," \
			"UpdatedAt			TEXT		NOT NULL," \
			"Prepared			INT			NOT NULL," \
			"Committed			INT			NOT NULL);";

		rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
		if (rc != SQLITE_OK){
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		}

		sql = "CREATE TABLE COMMITCONFIRMATIONS("  \
			"IDCommitConfirmation	INTEGER		PRIMARY KEY		AUTOINCREMENT," \
			"Node				TEXT		NOT NULL," \
			"Signature			TEXT		NOT NULL," \
			"ConfirmableId		INT			NOT NULL," \
			"ConfirmableType	TEXT		NOT NULL," \
			"CreatedAt			TEXT		NOT NULL," \
			"UpdatedAt			TEXT		NOT NULL);";

		rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
		if (rc != SQLITE_OK){
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		}

		sql = "CREATE TABLE CONSENSUSNODES("  \
			"IDConsensusNode	INTEGER		PRIMARY KEY		AUTOINCREMENT," \
			"URL				TEXT		NOT NULL," \
			"PublicKey			TEXT		NOT NULL," \
			"CreatedAt			TEXT		NOT NULL," \
			"UpdatedAt			TEXT		NOT NULL);";

		rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
		if (rc != SQLITE_OK){
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		}

		sql = "CREATE TABLE ISSUES("  \
			"IDIssue			INTEGER		PRIMARY KEY		AUTOINCREMENT," \
			"LedgerID			INT			NOT NULL," \
			"Amount				INT			NOT NULL," \
			"PublicKey			TEXT		NOT NULL," \
			"CreatedAt			TEXT		NOT NULL," \
			"UpdatedAt			TEXT		NOT NULL);";

		rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
		if (rc != SQLITE_OK){
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		}

		sql = "CREATE TABLE LEDGERS("  \
			"IDLedger			INTEGER		PRIMARY KEY		AUTOINCREMENT," \
			"PublicKey			TEXT		NOT NULL," \
			"Name				TEXT		NOT NULL," \
			"URL				TEXT		NOT NULL," \
			"PrimaryAccountId	INT			NOT NULL," \
			"Prepared			INT			NOT NULL," \
			"Committed			INT			NOT NULL," \
			"CreatedAt			TEXT		NOT NULL," \
			"UpdatedAt			TEXT		NOT NULL);";

		rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
		if (rc != SQLITE_OK){
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		}

		sql = "CREATE TABLE PREPARE_CONFIRMATIONS("  \
			"IDPrepareConfirmation		INTEGER		PRIMARY KEY		AUTOINCREMENT," \
			"Node				TEXT		NOT NULL," \
			"Signature			TEXT		NOT NULL," \
			"ConfirmableId		INT			NOT NULL," \
			"ConfirmableType	TEXT		NOT NULL," \
			"CreatedAt			TEXT		NOT NULL," \
			"UpdatedAt			TEXT		NOT NULL);";

		rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
		if (rc != SQLITE_OK){
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		}

		sql = "CREATE TABLE TRANSFERS("  \
			"IDTransfer			INTEGER		PRIMARY KEY		AUTOINCREMENT," \
			"Amount				REAL		NOT NULL," \
			"SourceId			INT			NOT NULL," \
			"DestinationId		INT			NOT NULL," \
			"PrimaryAccountId	INT			NOT NULL," \
			"Prepared			INT			NOT NULL," \
			"Committed			INT			NOT NULL," \
			"ResourceSignature	TEXT		NOT NULL," \
			"UuId				TEXT		NOT NULL," \
			"CreatedAt			TEXT		NOT NULL," \
			"UpdatedAt			TEXT		NOT NULL);";

		rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
		if (rc != SQLITE_OK){
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		}

		sqlite3_close(db);
	}
}

void Data::SqliteDataBase::insertAccount(Account acc)
{
	int rc;
	sqlite3 *db;
	rc = sqlite3_open("data.db", &db);
	char *zErrMsg = 0;
	sqlite3_stmt *stmt;
	const char *pzTest;

	char *szSQL;

	szSQL = "INSERT INTO LEDGERSTATS (Code, PublicKey, LedgerID, Balance, CreatedAt, UpdatedAt, Prepared, Committed ) " \
				"VALUES (?,?,?,?,?,?,?,?);";

	int rc2 = sqlite3_prepare(db, szSQL, strlen(szSQL), &stmt, &pzTest);
	if (rc2 == SQLITE_OK)
	{
		//sqlite3_bind_text(stmt, 1, );
		//sqlite3_bind_int(stmt, 2, );
		//sqlite3_bind_int(stmt, 3, );
		//sqlite3_bind_double(stmt, ,);
		//sqlite3_bind_int(stmt, 5, );

		// commit 
		sqlite3_step(stmt);
		sqlite3_finalize(stmt);
	}

	sqlite3_close(db);

}

void Data::SqliteDataBase::insertCommitConfimation(Commit_Confirmation cmcf)
{
	//TODO: Add method implementation here
	//throw std::logic_error("The method or operation is not implemented.");
}

void Data::SqliteDataBase::insertConsensusNode(Consensus_Node cn)
{
	//TODO: Add method implementation here
	//throw std::logic_error("The method or operation is not implemented.");
}

void Data::SqliteDataBase::insertIssue(Issue is)
{
	//TODO: Add method implementation here
	//throw std::logic_error("The method or operation is not implemented.");
}

void Data::SqliteDataBase::insertLedger(Ledger ld)
{
	//TODO: Add method implementation here
	//throw std::logic_error("The method or operation is not implemented.");
}

void Data::SqliteDataBase::insertPrepareConfirmation(Prepare_Confirmation pc)
{
	//TODO: Add method implementation here
	//throw std::logic_error("The method or operation is not implemented.");
}

void Data::SqliteDataBase::insertTransfer(Transfer tr)
{
	//TODO: Add method implementation here
	//throw std::logic_error("The method or operation is not implemented.");
}