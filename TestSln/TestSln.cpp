// TestSln.cpp : �������̨Ӧ�ó������ڵ㡣
//
#pragma warning(disable:4996)  
#include "stdafx.h"
#include "include_base_file.h"
#include "include_file.h"
//#include "boost/signals2.hpp"
//compile with: /clr

using namespace std;



int op_increase(int i) { return ++i; }


class Book:boost::noncopyable
{
public:
	string m_name;			//����;
	string m_isbn;			//���;
	float m_price;			//���;
	string m_writer;		//����;
};
bool GetFree(int i)
{
	return i;
}

int main()
{

// 	Bind bd;
// 	bd.Call();

// 	Function fc;
// 	fc.Call();

// 	BaseStl bs;
// 	bs.Call();

// 	Signals2 sg2;
// 	sg2.Call();

	//�й��쳣����;
	//TryCatchExec();
	//TryCatchExec2();

	//�йص��Ա���;
	//ConditionDefine();
	//AssertExec();

	//GenernalClass g1;
	//g1.Start();

	char *s = "hello";
	cout << SAFE_DEBUG(<< LVAR(s));

	
// 	{
// 		if (free)
// 		{
// 			cout << "flag1" << endl;
// 		}
// 		if (!free)
// 		{
// 			cout << "flag2" << endl;
// 		}
// 	}


	getchar();
	return 0;
}

