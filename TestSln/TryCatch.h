#pragma once
#include "stdafx.h"

using namespace std;

int TryCatchExec()
{
	try
	{
		std::string fileName = "test.cfg";
		std::ifstream f(fileName);
		if (f.fail())
		{
			throw std::runtime_error("file not found:" + fileName);
		}
	}
	catch (std::exception const &e)
	{
		std::cout << e.what();
	}
	return 0;
}

int TryCatchExec2()
{
	try
	{
		int a = 10;
		int b = 0;
		return a / b;
	}
	catch(std::exception const &e)
	{
		std::cout << e.what();
	}
	cout << "execTryCatchExec2";

}

void ConditionDefine()
{
#ifdef _DEBUG
	cout << "It's debug mode" << endl;
// 	cout << __FILE__ << '\n'
// 		<< __LINE__ << '\n'
// 		<< __TIME__ << '\n'
// 		<< __DATE__ << '\n'
// 		<< endl;
#else
	cout << "It's release mode" << endl;
#endif // _DEBUG
}

void AssertExec()
{
	assert(false);
	cout << "call " << __FUNCDNAME__ << endl;
	
}

class A
{
public:
	A() :a(0)
	{
		cout << "A construct" << endl;
	}

	A(const A& copyA)
	{
		a = copyA.a + 1;
		cout << "A copy construct" << endl;
	}

	~A()
	{
		cout << "A destruct" << "a  = "<< a << endl;
	}

public:
	int a;

};

class TryCatichClass
{
public:
	TryCatichClass();
	~TryCatichClass();

	void HanderObj(A a)
	{

	}

	void ConstructFunction1()
	{
		A a;
		HanderObj(a);
	}

	void ConstructFunction2()
	{
		try
		{
			A a;		//此处创建对象调用一次默认构造方法 Flag1;
			throw a;	//异常抛出表达式复制构造出一个异常对象，调用一次复制构造方法 Flag2;

						//调用类型A的析构方法，对应Flag1。
		}
		catch (A a)		//接受异常表达式抛出的异常对象，调用一次复制构造方法。Flag3
		{
			//调用类型A的析构方法，对应Flag3
			//调用类型A的析构方法，对应Flag2
		}
	}

	void ConstructFunction3()
	{
		try
		{
			A* a = new A();	//此处创建对象调用一次默认构造方法 Flag1;
			a->a = 10;
			throw *a;		//异常抛出表达式复制构造出一个异常对象，调用一次复制构造方法 Flag2;


							//Flag1出创建的对象，被分配在堆空间中，try语句块结束，不能释放，发生了内存泄漏。

		}
		catch (A a)			//接受异常表达式抛出的异常对象，调用一次复制构造方法。Flag3
		{
			cout << "In function:" << __FUNCTION__ << "a = " << a.a << endl;
			;
			//调用类型A的析构方法，对应Flag3
			//调用类型A的析构方法，对应Flag2。
		}
	}
private:

};

TryCatichClass::TryCatichClass()
{
}

TryCatichClass::~TryCatichClass()
{
}

