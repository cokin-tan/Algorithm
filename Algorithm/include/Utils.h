#pragma once

#define SAFE_DELETE(p) if (nullptr != p) { delete p; p = nullptr; }
#define SAFE_DELETE_ARR(p) if (nullptr != p) { delete[] p; p = nullptr; }

template<typename T>
void Swap(T& lhs, T& rhs)
{
	T temp = lhs;
	lhs = rhs;
	rhs = temp;
}