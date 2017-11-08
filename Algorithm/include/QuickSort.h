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
	void        HoareSort(int nStart, int nEnd);
	void		EqualSort(int nStart, int nEnd);
	void		RandomEqualSort(int nStart, int nEnd);
	void		TailRecursiveSort(int nStart, int nEnd);
	int 		PartitionSingle(int nStart, int nEnd);
	int 		PartitionDouble(int nStart, int nEnd);
	int			RandomPartition(int nStart, int nEnd);
	int			HoarePartition(int nStart, int nEnd);
	void        PartitionEqual(int nStart, int nEnd, int& nLeft, int& nRight);
	void		RandomPartitionEqual(int nStart, int nEnd, int& nLeft, int& nRight);

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
	int nStart = 0;
	TailRecursiveSort(nStart, m_nLength - 1);
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
	T nTemp = m_pArr[nEnd];
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
	T nTemp = m_pArr[nEnd];
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

template<typename T>
void CQuickSort<T>::HoareSort(int nStart, int nEnd)
{
	if (nStart < nEnd)
	{
		int nIndex = HoarePartition(nStart, nEnd);
		HoareSort(nStart, nIndex);
		HoareSort(nIndex + 1, nEnd);
	}
}

template<typename T>
int CQuickSort<T>::HoarePartition(int nStart, int nEnd)
{
	T temp = m_pArr[nStart];
	int nLeft = nStart - 1;
	int nRight = nEnd + 1;
	while (true)
	{
		do
		{
			--nRight;
		} while (m_pArr[nRight] > temp);

		do
		{
			++nLeft;
		} while (m_pArr[nLeft] < temp);
	
		if (nLeft < nRight)
		{
			Swap<T>(m_pArr[nLeft], m_pArr[nRight]);
		}
		else
		{
			return nRight;
		}
	}
}

template<typename T>
void CQuickSort<T>::EqualSort(int nStart, int nEnd)
{
	if (nStart < nEnd)
	{
		int nLeft, nRight;
		PartitionEqual(nStart, nEnd, nLeft, nRight);
		EqualSort(nStart, nLeft - 1);
		EqualSort(nRight + 1, nEnd);
	}
}

template<typename T>
void CQuickSort<T>::PartitionEqual(int nStart, int nEnd, int& nLeft, int& nRight)
{
	T temp = m_pArr[nEnd];
	nLeft = nStart - 1;
	int nRealEnd = nEnd - 1;
	for (int nIndex = nStart; nIndex <= nRealEnd;)
	{
		if (m_pArr[nIndex] == temp)
		{
			Swap<T>(m_pArr[nIndex], m_pArr[nRealEnd]);
			--nRealEnd;
		}
		else 
		{
			if (m_pArr[nIndex] < temp)
			{
				++nLeft;
				Swap<T>(m_pArr[nLeft], m_pArr[nIndex]);
			}
			++nIndex;
		}
	}

	nRight = nLeft;
	for (int nIndex = nEnd; nIndex > nRealEnd; --nIndex)
	{
		++nRight;
		Swap<T>(m_pArr[nRight], m_pArr[nIndex]);
	}
	++nLeft;
}

template<typename T>
void CQuickSort<T>::RandomEqualSort(int nStart, int nEnd)
{
	if (nStart < nEnd)
	{
		int nLeft, nRight;
		RandomPartitionEqual(nStart, nEnd, nLeft, nRight);
		RandomEqualSort(nStart, nLeft - 1);
		RandomEqualSort(nRight + 1, nEnd);
	}
}

template<typename T>
void CQuickSort<T>::RandomPartitionEqual(int nStart, int nEnd, int& nLeft, int& nRight)
{
	srand((unsigned)time(nullptr));
	int nRandomIndex = std::rand() % (nEnd - nStart + 1) + nStart;
	Swap<T>(m_pArr[nRandomIndex], m_pArr[nEnd]);
	return PartitionEqual(nStart, nEnd, nLeft, nRight);
}

template<typename T>
void CQuickSort<T>::TailRecursiveSort(int nStart, int nEnd)
{
	while (nStart < nEnd)
	{
		std::cout << nStart << std::endl;
		int nIndex = PartitionSingle(nStart, nEnd);
		TailRecursiveSort(nStart, nIndex - 1);
		nStart = nIndex + 1;
	}
}