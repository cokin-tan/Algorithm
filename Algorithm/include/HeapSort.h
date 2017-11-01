#pragma once

#include<iostream>

#include "Utils.h"

enum EHeapType
{
	EType_Max,
	EType_Min
};

template<typename T>
class CHeapSort
{
	typedef void(CHeapSort<T>::*heapSortCallBack)(int, int);

public:
	CHeapSort(T* pArr, int nLength, EHeapType type);
	void		BuildHeap();
	void		HeapSort();

public:
	void		Print() const;
	T			GetRoot() const;
	T           ExtraRoot();
	bool		IsEmpty() const;
	void		HeapModifyKey(int nIndex, T key);

private:
	int			Parent(int nIndex) const;
	int			Left(int nIndex) const;
	int			Right(int nIndex) const;
	void		MaxHeapify(int nIndex, int nHeapSize);
	void		MinHeapify(int nIndex, int nHeapSize);
	void		BuildHeap(heapSortCallBack pFunc);
	void		HeapSort(heapSortCallBack pFunc);

private:
	T*			m_pArr;
	int			m_nLength;
	int			m_nHeapSize;
	EHeapType   m_type;
};

template<typename T>
CHeapSort<T>::CHeapSort(T* pArr, int nLength, EHeapType type) :
	m_pArr(pArr),
	m_nLength(nLength),
	m_nHeapSize(nLength),
	m_type(type)
{}

template<typename T>
void CHeapSort<T>::BuildHeap()
{
	if (EType_Max == m_type)
	{
		BuildHeap(&CHeapSort<T>::MaxHeapify);
	}
	else
	{
		BuildHeap(&CHeapSort<T>::MinHeapify);
	}
}

template<typename T>
void CHeapSort<T>::HeapSort()
{
	if (EType_Max == m_type)
	{
		HeapSort(&CHeapSort<T>::MinHeapify);
	}
	else
	{
		HeapSort(&CHeapSort<T>::MaxHeapify);
	}
}

template<typename T>
int CHeapSort<T>::Parent(int nIndex) const
{
	int parent = (nIndex - 1) / 2;
	return parent >= 0 ? parent : 0;
}

template<typename T>
int CHeapSort<T>::Left(int nIndex) const
{
	return 2 * nIndex + 1;
}

template<typename T>
int CHeapSort<T>::Right(int nIndex) const
{
	return 2 * nIndex + 2;
}

template<typename T>
void CHeapSort<T>::BuildHeap(heapSortCallBack pFunc)
{
	if (nullptr == m_pArr)
	{
		std::cout << "The array is null" << std::endl;
		return;
	}

	for (int nIndex = m_nLength/2; nIndex >= 0; --nIndex)
	{
		(this->*pFunc)(nIndex, m_nHeapSize);
	}
}

template<typename T>
void CHeapSort<T>::MaxHeapify(int nIndex, int nHeapSize)
{
	int nLeft = Left(nIndex);
	int nRight = Right(nIndex);
	int nLargest = nIndex;
	if (nLeft < nHeapSize && m_pArr[nLeft] > m_pArr[nIndex])
	{
		nLargest = nLeft;
	}
	if (nRight < nHeapSize && m_pArr[nRight] > m_pArr[nLargest])
	{
		nLargest = nRight;
	}
	if (nLargest != nIndex)
	{
		Swap<T>(m_pArr[nIndex], m_pArr[nLargest]);
		MaxHeapify(nLargest, nHeapSize);
	}
}

template<typename T>
void CHeapSort<T>::MinHeapify(int nIndex, int nHeapSize)
{
	int nLeft = Left(nIndex);
	int nRight = Right(nIndex);
	int nSmallest = nIndex;
	if (nLeft < nHeapSize && m_pArr[nLeft] < m_pArr[nIndex])
	{
		nSmallest = nLeft;
	}
	if (nRight < nHeapSize && m_pArr[nRight] < m_pArr[nSmallest])
	{
		nSmallest = nRight;
	}
	if (nSmallest != nIndex)
	{
		Swap<T>(m_pArr[nIndex], m_pArr[nSmallest]);
		MinHeapify(nSmallest, nHeapSize);
	}
}

template<typename T>
void CHeapSort<T>::HeapSort(heapSortCallBack pFunc)
{
	int nHeapSize = m_nLength;
	BuildHeap(pFunc);
	for (int nIndex = m_nLength - 1; nIndex >= 0; --nIndex)
	{
		Swap<T>(m_pArr[nIndex], m_pArr[0]);
		--nHeapSize;
		(this->*pFunc)(0, nHeapSize);
	}
}

template<typename T>
void CHeapSort<T>::Print() const
{
	for (int nIndex = 0; nIndex < m_nLength; ++nIndex)
	{
		std::cout << m_pArr[nIndex] << " ";
	}
	std::cout << std::endl;
}

template<typename T>
T CHeapSort<T>::GetRoot() const
{
	if (!IsEmpty())
	{
		return m_pArr[0];
	}
	
	throw exception("heap overflow");
}

template<typename T>
T CHeapSort<T>::ExtraRoot()
{
	if (!IsEmpty())
	{
		T max = m_pArr[0];
		m_pArr[0] = m_pArr[m_nLength - 1];
		--m_nLength;
		if (EType_Max == m_type)
		{
			MaxHeapify(0, m_nLength);
		}
		else
		{
			MinHeapify(0, m_nLength);
		}
		return max;
	}

	throw exception("heap overflow");
}

template<typename T>
bool CHeapSort<T>::IsEmpty() const
{
	return nullptr == m_pArr || 0 >= m_nLength;
}

template<typename T>
void CHeapSort<T>::HeapModifyKey(int nIndex, T key)
{
	if (nIndex >= m_nLength || nIndex < 0)
	{
		throw exception("the index out of range");
	}

	if (EType_Max == m_type)
	{
		if (key < m_pArr[nIndex])
		{
			throw exception("the key must larget than index value");
		}
	}
	else
	{
		if (key > m_pArr[nIndex])
		{
			throw exception("the key must larget than index value");
		}
	}

	m_pArr[nIndex] = key;
	while (nIndex >= 0)
	{
		if ((EType_Min == m_type && m_pArr[Parent(nIndex)] > m_pArr[nIndex]) || (EType_Max == m_type && m_pArr[Parent(nIndex)] < m_pArr[nIndex]))
		{
			Swap<T>(m_pArr[Parent(nIndex)], m_pArr[nIndex]);
			nIndex = Parent(nIndex);
		}
		else
		{
			break;
		}
	}
}