#pragma once

#include "HeapSort.h"

template<typename T>
class CPrirotyQueue
{
public:
	CPrirotyQueue(T* arr, int nLength, EHeapType type);
	T		HeapFirstPriority() const;
	T       HeapExtractFirstPriority();
	void    HeapModifyKey(int nIndex, T key);

public:
	bool	IsEmpty() const;

private:
	CHeapSort<T> m_heap;
};

template<typename T>
CPrirotyQueue<T>::CPrirotyQueue(T* pArr, int nLength, EHeapType type) :
	m_heap(pArr, nLength, type)
{
	m_heap.HeapSort();
}

template<typename T>
T CPrirotyQueue<T>::HeapFirstPriority() const
{
	return m_heap.GetRoot();
}

template<typename T>
T CPrirotyQueue<T>::HeapExtractFirstPriority()
{
	return m_heap.ExtraRoot();
}

template<typename T>
bool CPrirotyQueue<T>::IsEmpty() const
{
	return m_heap.IsEmpty();
}

template<typename T>
void CPrirotyQueue<T>::HeapModifyKey(int nIndex, T key)
{
	m_heap.HeapModifyKey(nIndex, key);
}