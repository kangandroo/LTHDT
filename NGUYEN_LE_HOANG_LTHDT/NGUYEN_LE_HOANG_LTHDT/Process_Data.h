#pragma once
#include "Header.h"
#include "Constant.h"
#include "Student.h"

class Process_Data
{
public:
	Process_Data();
	~Process_Data();
	ifstream dangkynv;
	ifstream csdl;
	string NguyenVong;
	string Csdl;
	void string_split_csv(string s, vector<string> & v);
	string creatQuery();
private:
	bool fileIsOpen();
	void openFile();
	void closeFile();
};

