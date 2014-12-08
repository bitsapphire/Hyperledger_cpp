// BS_Ledger_Server.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <sqlite3.h>
#include "SqliteDataBase.h"
#include "Node.h"

int main()
{
	Data::DataBase *db = new Data::SqliteDataBase();
	db->checkCreateTables();

	return 0;
}