#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T, typename F>
void iter( T *arr_add, const size_t len, F func )
{
	size_t i = 0;
	while (i < len)
	{
		func(arr_add[i]);
		i++;
	}
};

#endif
