#include "stdafx.h"
#include "Student.h"

Student::Student()
{
}

Student::~Student()
{
}

float Student::tinhDiem(vector<string> v_s, string s)
{
	Process_Data A;
	vector<string> mon;
	A.string_split_csv(s, mon);
	return (stod(v_s[diem(mon[0])])*tinhHeSo(mon[3]) + stod(v_s[diem(mon[1])]) + stod(v_s[diem(mon[2])])) / (2 + tinhHeSo(mon[3]))
		+ (tinhDiemDT(v_s[4]) + tinhDiemKV(v_s[3])) / 3 + tinhDiemUT(v_s[5]);
}

float Student::tinhDiemKV(string s)
{
	return s == "KV1" ? 1.5 : s == "KV2-NT" ? 1 : s == "KV2" ? 0.5 : 0;
}

float Student::tinhDiemDT(string s)
{
	return s == "NDT1" ? 2 : s == "NDT2" ? 1 : 0;
}

float Student::tinhDiemUT(string s)
{
	return s == "UT" ? 1 : 0;
}

float Student::tinhHeSo(string s)
{
	return s == "0" ? 1 : 2;
}

int Student::diem(string s)
{
	return s == "Toan" ? 6 :
		s == "Van" ? 7 :
		s == "Ly" ? 8 :
		s == "Hoa" ? 9 :
		s == "Sinh" ? 10 :
		s == "Su" ? 11 :
		s == "Dia" ? 12 :
		s == "Anh" ? 13 :
		s == "Nga" ? 14 :
		s == "Phap" ? 15 :
		s == "Trung" ? 16 :
		s == "Duc" ? 17 :
		s == "Nhat" ? 18 :
		0;
}
