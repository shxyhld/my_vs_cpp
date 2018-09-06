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
			A a;		//�˴������������һ��Ĭ�Ϲ��췽�� Flag1;
			throw a;	//�쳣�׳����ʽ���ƹ����һ���쳣���󣬵���һ�θ��ƹ��췽�� Flag2;

						//��������A��������������ӦFlag1��
		}
		catch (A a)		//�����쳣���ʽ�׳����쳣���󣬵���һ�θ��ƹ��췽����Flag3
		{
			//��������A��������������ӦFlag3
			//��������A��������������ӦFlag2
		}
	}

	void ConstructFunction3()
	{
		try
		{
			A* a = new A();	//�˴������������һ��Ĭ�Ϲ��췽�� Flag1;
			a->a = 10;
			throw *a;		//�쳣�׳����ʽ���ƹ����һ���쳣���󣬵���һ�θ��ƹ��췽�� Flag2;


							//Flag1�������Ķ��󣬱������ڶѿռ��У�try��������������ͷţ��������ڴ�й©��

		}
		catch (A a)			//�����쳣���ʽ�׳����쳣���󣬵���һ�θ��ƹ��췽����Flag3
		{
			cout << "In function:" << __FUNCTION__ << "a = " << a.a << endl;
			;
			//��������A��������������ӦFlag3
			//��������A��������������ӦFlag2��
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

