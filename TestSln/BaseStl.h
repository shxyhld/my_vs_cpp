#pragma once
#include "stdafx.h"
using namespace std;


class BaseStl {
public:

	void Example1() {
		std::vector<int> v1(10,1);
		std::vector<int> v2(9);
		v2.resize(v1.size());

		std::transform(v1.begin(), v1.end(), v2.begin(),[](int x){
			return x;
		});

		for (auto &c : v2) {
			cout << c << endl;
		}

		
	}
	void Call() {
		Example1();

	}
};