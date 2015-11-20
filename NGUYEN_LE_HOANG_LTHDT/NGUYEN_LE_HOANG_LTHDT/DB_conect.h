#pragma once
#include "Constant.h"
#include "Header.h"

class DB_conect
{
public:
	DB_conect();
	~DB_conect();
	void data_2_db(string query);
private:
	static int callback(void *NotUsed, int argc, char **argv, char **azColName);
};
