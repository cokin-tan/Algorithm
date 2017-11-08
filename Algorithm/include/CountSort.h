#pragma once

#include<iostream>

class CCountSort
{
public:
	CCountSort(int* pArr, int nLength, int nMax);

public:
	void		Print() const;

private:
	void		Sort();

private:
	int*		m_pArr;
	int			m_nLength;
	int			m_nMax;
};