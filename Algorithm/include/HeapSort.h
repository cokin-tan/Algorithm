#pragma once

#include<iostream>

#include "Utils.h"

template<typename T>
class CHeapSort
{
	typedef void(CHeapSort<T>::*heapSortCallBack)(int, int);

public:
	CHeapSort(T* pArr, int nLength);
	void		BuildMaxHeap();
	void		BuildMinHeap();
	void		MaxHeapSort();
	void		MinHeapSort();

public:
	void		Print() const;

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
};

template<typename T>
CHeapSort<T>::CHeapSort(T* pArr, int nLength) :
	m_pArr(pArr),
	m_nLength(nLength),
	m_nHeapSize(nLength)
{}

template<typename T>
void CHeapSort<T>::BuildMaxHeap()
{
	BuildHeap(&CHeapSort<T>::MaxHeapify);
}

template<typename T>
void CHeapSort<T>::BuildMinHeap()
{
	BuildHeap(&CHeapSort<T>::MinHeapify);
}

template<typename T>
void CHeapSort<T>::MaxHeapSort()
{
	HeapSort(&CHeapSort<T>::MinHeapify);
}

template<typename T>
void CHeapSort<T>::MinHeapSort()
{
	HeapSort(&CHeapSort<T>::MaxHeapify);
}

template<typename T>
int CHeapSort<T>::Parent(int nIndex) const
{
	return (nIndex - 1) / 2;
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