#pragma once

#include <iostream>

#include "Utils.h"

template<typename T>
class CStack
{
public:
	CStack(int nSize);
	virtual ~CStack();

public:
	void		Push(T item);
	T			Pop();
	bool		IsEmpty() const;
	bool		IsFull() const;

private:
	T*			m_pArr;
	int			m_nSize;
	int			m_nTop;
};

template<typename T>
CStack<T>::CStack(int nSize):
	m_nSize(nSize),
	m_nTop(0)
{
	m_pArr = new T[nSize];
}

template<typename T>
CStack<T>::~CStack()
{
	SAFE_DELETE_ARR(m_pArr);
}

template<typename T>
void CStack<T>::Push(T item)
{
	if (IsFull())
	{
		throw exception("stack is full");
	}

	m_pArr[m_nTop++] = item;
}

template<typename T>
bool CStack<T>::IsFull() const
{
	return m_nTop >= m_nSize;
}

template<typename T>
T CStack<T>::Pop()
{
	if (IsEmpty())
	{
		throw exception("stack is empty");
	}

	return m_pArr[--m_nTop];
}

template<typename T>
bool CStack<T>::IsEmpty() const
{
	return m_nTop <= 0;
}