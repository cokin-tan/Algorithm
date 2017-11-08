#include <cassert>
#include "Utils.h"
#include "CountSort.h"

CCountSort::CCountSort(int* pArr, int nLength, int nMax):
	m_pArr(pArr),
	m_nLength(nLength),
	m_nMax(nMax)
{
	assert(nullptr != m_pArr);

	Sort();
}

void CCountSort::Print() const
{
	for (int nIndex = 0; nIndex < m_nLength; ++nIndex)
	{
		std::cout << m_pArr[nIndex] << " ";
	}
	std::cout << std::endl;
}

void CCountSort::Sort()
{
	int* pCountArr = new int[m_nMax+1];
	int* pTempArr = new int[m_nLength];
	memset(pCountArr, 0, sizeof(int)*(m_nMax+1));
	memcpy(pTempArr, m_pArr, sizeof(int)*m_nLength);

	for (int nIndex = 0; nIndex < m_nLength; ++nIndex)
	{
		++pCountArr[m_pArr[nIndex]];
	}

	for (int nIndex = 1; nIndex <= m_nMax; ++nIndex)
	{
		pCountArr[nIndex] += pCountArr[nIndex - 1];
	}

	for (int nIndex = m_nLength-1; nIndex >= 0; --nIndex)
	{
		m_pArr[pCountArr[pTempArr[nIndex]]-1] = pTempArr[nIndex];
		pCountArr[m_pArr[nIndex]] -= 1;
	}

	SAFE_DELETE_ARR(pCountArr);
	SAFE_DELETE_ARR(pTempArr);
}