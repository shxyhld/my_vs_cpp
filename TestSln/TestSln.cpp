// TestSln.cpp : 定义控制台应用程序的入口点。
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
	string m_name;			//书名;
	string m_isbn;			//书号;
	float m_price;			//书价;
	string m_writer;		//作家;
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

	//有关异常处理;
	//TryCatchExec();
	//TryCatchExec2();

	//有关调试编译;
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

