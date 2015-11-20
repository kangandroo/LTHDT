// NGUYEN_LE_HOANG_LTHDT.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Header.h"
#include "Process_Data.h"
#include "DB_conect.h"

void main()
{
	try
	{
		DB_conect A;
		Process_Data Q;
		A.data_2_db(Q.creatQuery());
	}
	catch (const std::exception& e)
	{
		cerr << e.what();
	}
	system("pause");
}

