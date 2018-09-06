#pragma once
#include "stdafx.h"

using namespace std;
template<typename T>
void Swap(T& a, T& b)
{
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}

// 在模板参数中，将实参N传递进去；
template<int N>
void Tfunction()
{
	cout << "T:" << N << endl;
}

template<class T>
class My_Ptr {
public:
	//默认构造方法;
	My_Ptr()
	{
		T* m_ptr = new T();
		m_refCount = new int;
		*m_refCount = 1;
	}

	//通过实际类型初始化;
	My_Ptr(T* t) :m_ptr(t)
	{
		if (m_ptr == t)
			return;
		
		*m_refCount = 1;
	}

	//拷贝构造方法;
	My_Ptr(My_Ptr<T>& t)
	{
		if (m_ptr == t.m_ptr)
			return;

		m_ptr = t.m_ptr;
		*t.m_refCount++;
		RefCountSub();
		m_refCount = t.m_refCount;
	}

	~My_Ptr()
	{
		if (m_refCount != 0)
			return;

		delete m_ptr;
		m_ptr = NULL;

		delete m_refCount;
		m_refCount = NULL;
	}
	int UseCount()
	{
		return *m_refCount;
	}
private:
	void RefCountSub()
	{
		*m_refCount--;
		if (0 == *m_refCount)
			~My_Ptr();
	}

public:
	T* m_ptr;
	int* m_refCount;
};


class TestFlag
{
public:
	TestFlag() {

	}
	~TestFlag() {

	}
	void CallDelete()
	{
	}
};