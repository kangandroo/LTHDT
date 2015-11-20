#pragma once
#include "Header.h"
#include "Constant.h"
#include "Process_Data.h"

class Student
{
public:
	Student();
	~Student();
	float tinhDiem(vector<string> v_s, string s);
private:
	float tinhDiemKV(string s);
	float tinhDiemDT(string s);
	float tinhDiemUT(string s);
	float tinhHeSo(string s);
	int diem(string s);
};