#pragma once


template <typename F>
void PerformTransform(int* beg, int* end, F func)
{
	std::transform(beg, end, beg, func);
}
