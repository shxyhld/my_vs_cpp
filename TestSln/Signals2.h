#pragma once

#include "boost/signals2.hpp"
using namespace boost::signals2;

template<int N> 
struct Slots {
	//v1
	void operator()() {
		std::cout << "N:" << N << endl;
	}
};

template<int N>
struct Slots2 {
	//v2
	int operator()(int x) {
		std::cout << "N:" << N << endl;
		return x * N;
	}
};

void Slot1() {
	std::cout << "call slot1" << endl;
}

void Slot2() {
	std::cout << "call slot2" << endl;
}

class Signals2 {
public:
	void Example1() {
		signal<void()> sig;
		sig.connect(&Slot1);
		sig.connect(&Slot2);
		sig();
	}

	void Example2()
	{
		signal<void()> sig;
		sig.connect(Slots<1>(),at_front);
		sig.connect(Slots<100>(),at_front);

		sig.connect(5, Slots<50>());
		sig.connect(5, Slots<51>());

		sig.connect(3, Slots<30>());
		sig.connect(3, Slots<31>());

		sig.connect(10, Slots<10>());

		sig();
	}

	void Example3() {
		signal<int(int)> sig;
		sig.connect(Slots2<1>());
		sig.connect(Slots2<2>());
		cout << *sig(2);
	}

	// combiner
	void Example4() {
		//signal<int(int), combiner<int>> sig(combiner<int>());
	}
	void Call()
	{
		//Example1();
		//Example2();
		Example3();
	}

};