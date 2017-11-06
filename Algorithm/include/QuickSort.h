#pragma once

#include<cassert>
#include<ctime>

#include "Utils.h"

template<typename T>
class CQuickSort
{
public:
	CQuickSort(T* pArr, int nLength);
	void		Print() const;

private:
	void		Sort(int nStart, int nEnd);
	void		RandomSort(int nStart, int nEnd);
	int 		PartitionSingle(int nStart, int nEnd);
	int 		PartitionDouble(int nStart, int nEnd);
	int			RandomPartition(int nStart, int nEnd);

private:
	T*			m_pArr;
	int			m_nLength;
};

template<typename T>
CQuickSort<T>::CQuickSort(T* pArr, int nLength):
	m_pArr(pArr),
	m_nLength(nLength)
{
	assert(nullptr != m_pArr);
	RandomSort(0, m_nLength - 1);
}

template<typename T>
void CQuickSort<T>::Sort(int nStart, int nEnd)
{
	if (nStart < nEnd)
	{
		int nIndex = PartitionDouble(nStart, nEnd);
		Print();
		Sort(nStart, nIndex - 1);
		Sort(nIndex + 1, nEnd);
	}
}

template<typename T>
int CQuickSort<T>::PartitionSingle(int nStart, int nEnd)
{
	int nTemp = m_pArr[nEnd];
	int nPart = nStart - 1;
	for (int nIndex = nStart; nIndex < nEnd; ++nIndex)
	{
		if (m_pArr[nIndex] <= nTemp)
		{
			++nPart;
			Swap<T>(m_pArr[nPart], m_pArr[nIndex]);
		}
	}

	++nPart;
	Swap<T>(m_pArr[nPart], m_pArr[nEnd]);

	return nPart;
}

template<typename T>
int CQuickSort<T>::PartitionDouble(int nStart, int nEnd)
{
	int nTemp = m_pArr[nEnd];
	int nLeft = nStart;
	int nRight = nEnd - 1;
	while (nLeft <= nRight)
	{
		while (m_pArr[nLeft] <= nTemp)
		{
			++nLeft;
		}
		while (m_pArr[nRight] >= nTemp)
		{
			--nRight;
		}
		if (nLeft > nRight)
		{
			break;
		}

		Swap<T>(m_pArr[nLeft], m_pArr[nRight]);
	}

	++nRight;
	Swap<T>(m_pArr[nRight], m_pArr[nEnd]);

	return nRight;
}

template<typename T>
void CQuickSort<T>::Print() const
{
	for (int nIndex = 0; nIndex < m_nLength; ++nIndex)
	{
		std::cout << m_pArr[nIndex] << " ";
	}
	std::cout << std::endl;
}

template<typename T>
void CQuickSort<T>::RandomSort(int nStart, int nEnd)
{
	if (nStart < nEnd)
	{
		int nIndex = RandomPartition(nStart, nEnd);
		RandomSort(nStart, nIndex - 1);
		RandomSort(nIndex + 1, nEnd);
	}
}

template<typename T>
int CQuickSort<T>::RandomPartition(int nStart, int nEnd)
{
	srand((unsigned)time(nullptr));
	int nRandomIndex = std::rand() % (nEnd - nStart + 1) + nStart;
	Swap<T>(m_pArr[nRandomIndex], m_pArr[nEnd]);
	return PartitionSingle(nStart, nEnd);
}