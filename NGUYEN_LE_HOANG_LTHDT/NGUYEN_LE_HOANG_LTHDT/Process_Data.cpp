#include "stdafx.h"
#include "Process_Data.h"

Process_Data::Process_Data()
{
}

Process_Data::~Process_Data()
{
}

void Process_Data::string_split_csv(string s, vector<string>& v)
{
	string ss;
	int i = 0;
	bool instring = false;
	while (i < s.size()) {
		if (s[i] == '\"')
			instring = !instring;
		else
			ss += s[i];

		++i;

		if ((ss.length()>0) && (ss[ss.length() - 1] == ',') && !instring)
		{
			ss = ss.substr(0, ss.length() - 1);
			boost::trim(ss);
			v.push_back(ss);
			ss = "";
		}
	}
	boost::trim(ss);
	v.push_back(ss);
}

string Process_Data::creatQuery()
{
	int i = 1;
	Student A;
	string Query = QUERY_CREAT_TABLE;
	openFile();
	if (fileIsOpen())
	{
		while (getline(dangkynv, NguyenVong) && getline(csdl, Csdl))
		{
			if (i > START_STUDENT&i < END_STUDENT)
			{
				vector<string> v_csdl;
				vector<string> v_NguyenVong;
				string_split_csv(Csdl, v_csdl);
				string_split_csv(NguyenVong, v_NguyenVong);
				for (int k = 2; k <= 8; k += 2)
				{
					if (v_NguyenVong[k] != "NA")
					{
						string s = "INSERT INTO nvxt VALUES ('";
						s += v_NguyenVong[0] + "',";
						s += k == 2 ? "1" : k == 4 ? "2" : k == 6 ? "3" : k == 8 ? "4" : 0;
						s += ",'" + v_NguyenVong[k - 1] + "',";
						float diemXT = A.tinhDiem(v_csdl, v_NguyenVong[k]);
						diemXT = roundf(diemXT * 100) / 100;
						s += to_string(diemXT);
						s += ");";
						Query += s;
					}
					else break;
				}
			}
			i++;
		}
	}
	return Query;
	closeFile();
}

bool Process_Data::fileIsOpen()
{
	return dangkynv.is_open() && csdl.is_open();
}

void Process_Data::openFile()
{
	dangkynv = ifstream("dangkynv-bk.csv");
	csdl = ifstream("csdl-bk.csv");
}

void Process_Data::closeFile()
{
	dangkynv.close();
	csdl.close();
}
