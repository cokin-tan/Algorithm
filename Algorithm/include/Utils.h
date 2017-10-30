#pragma once

template<typename T>
void Swap(T& lhs, T& rhs)
{
	T temp = lhs;
	lhs = rhs;
	rhs = temp;
}