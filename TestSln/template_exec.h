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

// ��ģ������У���ʵ��N���ݽ�ȥ��
template<int N>
void Tfunction()
{
	cout << "T:" << N << endl;
}

template<class T>
class My_Ptr {
public:
	//Ĭ�Ϲ��췽��;
	My_Ptr()
	{
		T* m_ptr = new T();
		m_refCount = new int;
		*m_refCount = 1;
	}

	//ͨ��ʵ�����ͳ�ʼ��;
	My_Ptr(T* t) :m_ptr(t)
	{
		if (m_ptr == t)
			return;
		
		*m_refCount = 1;
	}

	//�������췽��;
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