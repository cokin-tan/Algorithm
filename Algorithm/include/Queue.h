#pragma once

#include "Utils.h"

template<typename T>
class CQueue
{
public:
	CQueue(int nSize);
	virtual ~CQueue();

public:
	void		EnQueue(T item);
	bool		IsFull() const;
	T			DeQueue();
	bool		IsEmpty() const;

private:
	int			m_nHead;
	int			m_nTail;
	int			m_nLength;
	T*			m_pArr;
};

template<typename T>
CQueue<T>::CQueue(int nSize):
	m_nLength(nSize + 1),
	m_nHead(0),
	m_nTail(0)
{
	m_pArr = new T[nSize];
}

template<typename T>
CQueue<T>::~CQueue()
{
	SAFE_DELETE_ARR(m_pArr);
}

template<typename T>
void CQueue<T>::EnQueue(T item)
{
	if (IsFull())
	{
		throw exception("the queue is full");
	}

	m_pArr[m_nTail++] = item;
	m_nTail %= m_nLength;
}

template<typename T>
bool CQueue<T>::IsFull() const
{
	return (m_nTail + 1) % m_nLength == m_nHead;
}

template<typename T>
T CQueue<T>::DeQueue()
{
	if (IsEmpty())
	{
		throw exception("the queue is empty");
	}

	T item = m_pArr[m_nHead++];
	m_nHead %= m_nLength;
	return item;
}

template<typename T>
bool CQueue<T>::IsEmpty() const
{
	return m_nHead == m_nTail;
}