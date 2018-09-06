#pragma once
#include "include_base_file.h"
using namespace std;
vector<string> getNames()
{
	vector<string> names;
	names.push_back("hello");
	names.push_back("world");
	return names;
}

#define LVAR(v) " "#v"=" << (v)
#define CONCATE(a,b) a##b 

#define SAFE_DEBUG(...) "debug:"__VA_ARGS__ << endl
#define SAFE_INFO(...) "info:"__VA_ARGS__ << endl
#define SAFE_ERROR(...) "error:"__VA_ARGS__ << endl

inline int Latoi(char const *s) {
	return s ? atoi(s) : 0;
}

inline long Latol(char const* s) {
	return s ? atol(s) : 0;
}

inline long long Latoll(char const *s) {
	return s ? atoll(s) : 0;
}

inline std::string Latos(char const *s) {
	return s ? s : "";
}

inline double Latof(char const *s) {
	return s ? atof(s) : 0;
}

inline void LSqlParseField(std::string &v, char const* s) {
	v = s ? s : "";
}

inline void LSqlParseField(int &v, char const* s) {
	v = s ? atoi(s) : 0;
}

inline void LSqlParseField(long &v, char const* s) {
	v = s ? atol(s) : 0;
}

inline void LSqlParseField(long long &v, char const* s) {
	v = s ? atoll(s) : 0;
}

inline void LSqlParseField(uint32_t &v, char const* s) {
	v = s ? (uint32_t)strtoul(s, NULL, 10) : 0;
}

inline void LSqlParseField(float &v, char const* s) {
	v = s ? strtof(s, NULL) : 0;
}

inline void LSqlParseField(double &v, char const* s) {
	v = s ? strtod(s, NULL) : 0;
}


class BaseClass
{
public:
	BaseClass() {
		cout << "call default BaseClass construction" << endl;
	}
	~BaseClass() {
		cout << "call default BaseClass deconstruction" << endl;
	}

private:

};

class DeriveClass:public BaseClass
{
public:
	DeriveClass() {
		cout << "call default DeriveClass construction" << endl;
	}
	~DeriveClass() {
		cout << "call default DeriveClass deconstruction" << endl;
	}

private:

};

class InterfaceClass
{
public:
	InterfaceClass(){
		cout << "call default InterfaceClass construction" << endl;
	}
	virtual ~InterfaceClass(){
		cout << "call default InterfaceClass deconstruction" << endl;
	}
	virtual void PrintName() {
		cout << "This class name is InterfaceClass" << endl;
	}
private:

};

class ImplementClass:public InterfaceClass
{
public:
	ImplementClass() {
		cout << "call default ImplementClass construction" << endl;
	}
	~ImplementClass() {
		cout << "call default ImplementClass deconstruction" << endl;
	}
	void PrintName() {
		cout << "This class name is ImplementClass" << endl;

	}

private:
};

struct LSqlQueryExecutor {
public:
	LSqlQueryExecutor() {
		m_row = {"-2147483648","2147483647","9223372036854775807","-9223372036854775808","0.456","0.123456789123456","abcde" };
		m_curr_cursor = 0;
	}
public:
	template<class T>
	LSqlQueryExecutor &operator << (T &field){

	}

	template<class T>
	LSqlQueryExecutor &operator >> (T &field){
		if(!m_row.empty() && m_curr_cursor < m_row.size()){
			cout << SAFE_DEBUG(<< LVAR(m_curr_cursor));
			LSqlParseField(field, m_row[m_curr_cursor].c_str());
		}
		m_curr_cursor++;
		return *this;
	}
private:
	std::vector<string> m_row;
	int m_count;
	int m_curr_cursor;
};


class GenernalClass
{
public:
	GenernalClass();
	~GenernalClass();
	void Start();
	void Func1();
	void Func2();
	void Func3();
	void Func4();
	void Func5();
	void Func6();
	void Func7();
	void Func8();
	void Func9();
private:

};

GenernalClass::GenernalClass()
{
}

GenernalClass::~GenernalClass()
{
}

void GenernalClass::Start()
{
	//Func6();
	//Func8();
	Func9();
// 	vector<string> realNames = getNames();
// 	for (auto &c : realNames)
// 	{
// 		cout << c << endl;
// 	}

	// 	vector<string> strs;
	// 	//strs.push_back("hello");
	// 	string str1 = strs.empty() ? "kong" : strs.front();
	// 	cout << str1 << endl;


}

void GenernalClass::Func1()
{
	cout << "after reset:" << endl;
	//memset(user, 2, sizeof(user));
// 	for (auto& c : user)
// 	{
// 		cout << c << " ";
// 	}
	cout << endl;
}

void GenernalClass::Func2()
{
	int i = 0, j = 0, x = 0;
	int a = 0, b = 0;
	int ab = 0;
// 	cout << LVAR(i) << LVAR(j) << LVAR(x);
// 	cout << endl;
// 	cout << CONCATE(a, b);
// 
// 	cout << SAFE_INFO(LVAR(i) << LVAR(j));
// 	cout << SAFE_DEBUG(LVAR(i) << LVAR(j));
// 	cout << SAFE_ERROR(LVAR(i) << LVAR(j));
}

void GenernalClass::Func3()
{
	int i = 10;
	int j = 20;
	Swap<int>(i, j);
	cout << "i = " << i << ",j = " << j << endl;

	char* str1 = "hello";
	char* str2 = "world";
	Swap<char*>(str1, str2);
	cout << "str1 = " << str1 << ",str2 = " << str2 << endl;
}

void GenernalClass::Func4()
{
	string str1 = "World";
	string str2;
	str2.resize(str1.size());


	std::transform(str1.begin(), str1.end(), str2.begin(), toupper);

	cout << "print2 str2";
	for (auto &c : str2)
	{
		cout << c;
	}
	cout << endl;
}

void GenernalClass::Func5()
{
	std::vector<int> foo;
	std::vector<int> bar;
	// std::plus adds together its two arguments:
	std::transform(foo.begin(), foo.end(), bar.begin(), foo.begin(), std::plus<int>());
	// foo: 21 41 61 81 101

	std::cout << "foo contains:";
	for (std::vector<int>::iterator it = foo.begin(); it != foo.end(); ++it)
		std::cout << ' ' << *it;
}

void GenernalClass::Func6()
{
	//测试基类构造函数和派生类构造函数调用顺序
	{
		//DeriveClass dc1;
	}


	{
		InterfaceClass* ic1 = new ImplementClass();
		ic1->PrintName();
		delete ic1;
	}
}

void GenernalClass::Func7()
{
	std::vector<string> foo;
	std::vector<string> bar;

	// set some values:
	for (int i = 1; i < 6; i++)
		foo.push_back("Hello");                         // foo: 10 20 30 40 50

	bar.resize(foo.size());                         // allocate space

	std::cout << "print1 bar";
	for (auto &c : bar)
	{
		cout << c << " ";
	}
	std::cout << endl;
}

void GenernalClass::Func8()
{
	char* s_null = NULL;
	cout << SAFE_DEBUG(<< LVAR(Latoi(s_null)));
	cout << SAFE_DEBUG(<< LVAR(Latol(s_null)));
	cout << SAFE_DEBUG(<< LVAR(Latoll(s_null)));
	cout << SAFE_DEBUG(<< LVAR(Latos(s_null)));
	cout << SAFE_DEBUG(<< LVAR(Latof(s_null)));

	char* s_err_str = "\`123\\";
	cout << SAFE_DEBUG(<< LVAR(Latoi(s_err_str)));
	cout << SAFE_DEBUG(<< LVAR(Latol(s_err_str)));
	cout << SAFE_DEBUG(<< LVAR(Latoll(s_err_str)));
	cout << SAFE_DEBUG(<< LVAR(Latos(s_err_str)));
	cout << SAFE_DEBUG(<< LVAR(Latof(s_err_str)));

	char* s_int = "123";
	cout << SAFE_DEBUG(<< LVAR(Latoi(s_int)));

	char* s_16_int = "0xf";
	cout << SAFE_DEBUG(<< LVAR(Latoi(s_16_int)));

	char* s_err_int = "abcd";
	cout << SAFE_DEBUG(<< LVAR(Latoi(s_err_int)));

	char* s_float1 = "123";
	cout << SAFE_DEBUG(<< LVAR(Latof(s_float1)));

	char* s_float2 = "0.123333333333333";
	cout << SAFE_DEBUG(<< LVAR(Latof(s_float2)));

	char* s_float3 = "0.456";
	cout << SAFE_DEBUG(<< LVAR(Latof(s_float3)));

	char* s_ng_float4 = "-0.123";
	cout << SAFE_DEBUG(<< LVAR(Latof(s_ng_float4)));

	char* s_str = "123abc.";
	cout << SAFE_DEBUG(<< LVAR(Latos(s_str)));

	
	int l_int = 0;
	LSqlParseField(l_int, s_int);
	cout << SAFE_DEBUG(<< LVAR(l_int));

	float l_float1 = 0;
	LSqlParseField(l_float1, s_float1);
	cout << SAFE_DEBUG(<< LVAR(l_float1));

	float l_float2 = 0;
	LSqlParseField(l_float2, s_float2);
	cout << SAFE_DEBUG(<< LVAR(l_float2));

	float l_float3 = 0;
	LSqlParseField(l_float3, s_float3);
	cout << SAFE_DEBUG(<< LVAR(l_float3));

	float l_ng_float4 = 0;
	LSqlParseField(l_ng_float4, s_ng_float4);
	cout << SAFE_DEBUG(<< LVAR(l_ng_float4));

	double l_double = 0;
	LSqlParseField(l_double, s_float1);
	cout << SAFE_DEBUG(<< LVAR(l_double));

	uint32_t l_uint32 = 0;
	LSqlParseField(l_uint32, s_int);
	cout << SAFE_DEBUG(<< LVAR(l_uint32));

	std::string s_str1;
	LSqlParseField(s_str1, s_err_str);
	cout << SAFE_DEBUG(<< LVAR(s_str1));
}

void GenernalClass::Func9()
{
	LSqlQueryExecutor exetor;
	int i_1 = 0;
	int i_2 = 0;
	long long int l_1 = 0;
	long long int l_2 = 0;
	float f = 0;
	double d = 0;
	std::string s;
	exetor >> i_1 >> i_2 >> l_1 >> l_2 >> f >> d >> s;
	cout << SAFE_DEBUG(<< LVAR(i_1) << LVAR(i_2) << LVAR(l_1) << LVAR(l_2) << LVAR(f) << LVAR(d) << LVAR(s));
}

