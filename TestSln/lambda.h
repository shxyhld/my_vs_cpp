#pragma once
#include "stdafx.h"

using namespace std;

struct Data1
{
public:
	int i;
	int j;
};

struct Data2
{
public:
	Data2()
	{
		cout << "call construct" << endl;
	}

	Data2(const Data2& d2)
	{
		cout << "call copy construct" << endl;
		k = d2.k;
		m = d2.m;
	}

	Data2& operator=(const Data2& d2)
	{
		cout << "call operator copy construct" << endl;
		k = d2.k;
		m = d2.m;
		return *this;
	}
public:
	int k;
	int m;
};

class Base1
{
public:
	Data1 data1;
};

class Base2
{
public:
	Data2 data2;
};

void PrintBase(Base1& b)
{
	//cout << b.i << b.j << endl;
}
void PrintBase(Base2& b)
{
	//cout << b.k << b.m << endl;
}


class Son :public Base1, public Base2
{
public:
	void Print1()
	{
		PrintBase((Base1)(*this));
	}
	void Print2()
	{
		PrintBase((Base2)(*this));
	}
};

void PrintData2(Data2& d2)
{
	cout << "k = " << d2.k << ",m = " << d2.m << endl;
	return;
}

void TestLambdaRefParamLife(Data2& d2)
{
	auto callFunc = [d2]()
	{
		cout << "callFunc" << endl;
		Data2& dref = const_cast<Data2&>(d2);
		PrintData2(dref);
	};
	callFunc();
}

//lambda���ʽ��ʽ��[capture list](params list)->return type{function body}

//����ʽ��

class CLambdaTest
{
public:
	CLambdaTest()
	{

	}

public:
	void Start()
	{
		//FuncCapture1();
		//FuncCapture2();
		//Func1();
	}

	// ���Լ��ֲ�ͬ�Ĳ���ʽ;
	void FuncCapture1()
	{
		int tmp_i = 1;
		//���ò���ģʽ;
		auto lam_func = [&tmp_i]() mutable{
			//tmp_i = 3;
			cout << "tmp_i:" << tmp_i << endl;
		};
		//����tmp_i������lambda���ʽ�����tmp_i����ֵҲ��仯��
		tmp_i = 2;

		lam_func();
	}

	void FuncCapture2()
	{
		int tmp_i = 1;
		int tmp_j = 10;

		tmp_i = 2;
		tmp_j = 20;
		//���������ʱ����lambda������λ���йأ������λ���޹�

		//��ϲ���ʽ��tmp_iΪֵ����tmp_jΪ���ò���;
		auto lam_func = [tmp_i,&tmp_j]() {
			cout << tmp_i << "," << tmp_j << endl;
		};
		lam_func();

		tmp_i = 3;
		tmp_j = 30;
		lam_func();
		
	}

	void Func1()
	{
		int m1 = [](int x) {
			return [](int y) {return y;}(6) + x;
		}(5);
		std::cout << "m1:" << m1 << std::endl;

		int m_2 = [](int x, int y) {return x + y;}(5, 6);
		cout << "m_2:" << m_2 << endl;

		auto gFunc = [](int x)->std::function<int(int)> {return [=](int y) {return x + y;};};
		auto lFunc = gFunc(5);
		lFunc = gFunc(6);
		cout << "l_func:" << lFunc(4) << endl;

		std::function<int(int, int)> tmpFunc = [](int x, int y) {return x + y;};
		cout <<"tmpFunc:" << tmpFunc(2, 3) << endl;

		//���벶��this�������õ�ǰ�Ķ��󣬲�����lambda�е���FuncCapture1������
		auto hFunc = [this](){
			FuncCapture1();
		};
		hFunc();
	}
	void Func2()
	{
		std::vector<std::vector<int>> vec;
		std::vector<int> elm1 = { 1,2,3,4,5 };
		std::vector<int> elm2 = { 1,2,3,4 };
		std::vector<int> elm3 = { 1,2,3 };

		vec.push_back(elm2);
		vec.push_back(elm1);
		vec.push_back(elm3);

		std::sort(vec.begin(), vec.end(), [](std::vector<std::vector<int>>::value_type &infoValue1, std::vector<std::vector<int>>::value_type &infoValue2)
		{
			int inforSize1 = infoValue1.size() * 1000;
			int inforSize2 = infoValue2.size() * 1000;
			return  inforSize1 < inforSize2;
		});

		for (auto&c : vec)
		{
			cout << c.size() << endl;
		}
	}

private:
	int i;
	int j;

};