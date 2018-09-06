#pragma once
#include <boost/bind.hpp>
//#include <boost/function.hpp>
#include "stdafx.h"

using namespace boost;
class DemoClass {
private:
	typedef function<void(int)> func_t;
	func_t func;
	int n;
public:
	DemoClass(int i) :n(i) {

	}
	//TODO:函数模板;
	template<typename CallBack>
	void Accept(CallBack f) {
		func = f;
	}
	void Run() {
		func(n);
	}
};
class CallBackFactory {
public:
	void CallBackFunc1(int x) {
		std::cout << x * 2 << endl;
	}
	void CallBackFunc2(int x, int y) {
		std::cout << x * y * 2 << endl;
	}
};

void CallBackFunction(int i) {
	std::cout << "call callbackfunction" << endl;
	std::cout << i * 2 << endl;
}

// 用于回调
class Function{
public:
	void Example1() {
		DemoClass dc(10);
		dc.Accept(CallBackFunction);
		dc.Run();
	}
	void Example2() {
		DemoClass dc(20);
		CallBackFactory cbf;
		dc.Accept(bind(&CallBackFactory::CallBackFunc1, cbf, 5));
		dc.Run();
		dc.Accept(bind(&CallBackFactory::CallBackFunc2, cbf, _1, 5));
		dc.Run();
	}
	void Call() {
		//Example1();
		Example2();
	}
};