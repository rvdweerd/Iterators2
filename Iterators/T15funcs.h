#pragma once
#include <iostream>
//#include <vector>
//#include <forward_list>
//#include <iterator>

template<typename Iterr>
void print(Iterr beg, Iterr end)
{
	for (; beg != end; ++beg)
	{
		std::cout << *beg << ", ";
	}
	std::cout << std::endl;
}

template<typename T>
void printX(T* L, T* R)
{
	for (; L < R; L++)
	{
		std::cout << *L << ", ";
	}
	std::cout << std::endl;
}


void printI(int* L, int* R)
{
	for (; L < R; L++)
	{
		std::cout << *L << ", ";
	}
	std::cout << std::endl;
}

template<typename Iter1, typename Iter2, typename Iter3>
void sum(Iter1 in1, Iter1 end1, Iter2 in2, Iter3 out)
{
	for (; in1 != end1; ++in1, ++in2, ++out)
	{
		*out = *in1 + *in2;
	}
}