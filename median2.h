#ifndef GUARD_median_cpp
#define GUARD_median_cpp

#include <algorithm>
#include <stdexcept>
#include <vector>

double median(std::vector<double>)
{
	typedef vector<double>::size_type vec_sz;

	vec_sz size = vec.size();
	if (size == 0)
		throw std::domain_error("median of an empty vector");
	
	std::sort(vec.begin(), vec.end());

	vec_sz mid = size/2;

	return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}

#endif