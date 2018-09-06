#pragma once
#include <boost/bind.hpp>
#include "stdafx.h"

using namespace std;
using namespace boost;
// bind普通函数;



// bind结合for_each打印数组成员;

// bind成员变量;


// bind函数对象;
int f(int x, int y)
{
	return x + y;
}

int g(int x, int y, int z)
{
	return x + y + z;
}

void bind_print(int x) {
	cout << x << endl;
}
typedef int(*f_type)(int, int);
typedef int(*g_type)(int, int, int);

class Bind{
	struct Demo	{
		int f(int a, int b)
		{
			return a + b;
		}
	};
	struct Point {
		int x;
		int y;
		void print()
		{
			cout << "x=" << x << ",y=" << y << endl;
		}
		
	};

public:
	// bind普通函数;
	void Example1()
	{
		cout << "bind f() function:" << endl;
		cout << bind(f, 1, 2)() << endl;
		cout << bind(f, _2, 3)(1, 2) << endl;
		cout << bind(f, _2, _2)(1, 2) << endl;
		//cout << bind(f, 1, _2)(1) << endl; //没有参数_2，编译报错。

		cout << "bind g() function:" << endl;
		cout << bind(g, 1, 2, 3)() << endl;
		cout << bind(g, 1, _1, _2)(1, 2) << endl;

		f_type pf = f;
		g_type pg = g;
		cout << "bind pf() function:" << endl;
		cout << bind(pf, 1, _1)(2) << endl;
		cout << "bind pg() function:" << endl;
		cout << bind(pg, 1, 2, _2)(1, 2) << endl;
	}

	// bind成员函数;
	void Example2()
	{
		Demo a, &ra = a;
		Demo *pa = &a;
		cout << bind(&Demo::f, a, 1, 2)() << endl;
		cout << bind(&Demo::f, ra, 1, _1)(1, 2) << endl;
		cout << bind(&Demo::f, pa, 2, _2)(1, 2) << endl;

		vector<Point> points(10);
		for_each(points.begin(), points.end(), bind(&Point::print, _1));
	}

	// bind成员变量;
	void Example3()
	{
		vector<Point> points(10);
		vector<int> nums(10, 1);
// 		BOOST_FOREACH(int x, nums)
// 			cout << x << ",";

		//TODO
		//transform(nums.begin(), nums.end(), points.begin(), bind(&Point::x, _1));
		for_each(points.begin(), points.end(), bind(&Point::print, _1));
	}

	// 
	void Example4() {
		auto f = bind(bind_print, 3);
		f();
	}
	void Call()
	{
		//Example1();
		//Example2();
		//Example3();
		Example4();

	}
};