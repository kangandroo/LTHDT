#include "stdafx.h"
#include "DB_conect.h"

DB_conect::DB_conect()
{
}


DB_conect::~DB_conect()
{
}

void DB_conect::data_2_db(string query)
{
	char *zErrMsg = 0;
	sqlite3 *db;
	int rc = sqlite3_open("14.db", &db);

	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		throw new exception(sqlite3_errmsg(db));
		return;
	}
	else {
		fprintf(stderr, "Opened database successfully\n");
	}
	/* Execute SQL statement */
	rc = sqlite3_exec(db, query.c_str(), NULL, 0, &zErrMsg);
	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Table created successfully\n");
	}
	sqlite3_close(db);
}

int DB_conect::callback(void * NotUsed, int argc, char ** argv, char ** azColName)
{
	int i;
	for (i = 0; i < argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}
