#include <iostream>
#include "iter.hpp"

template <typename T>
void print(const T &elem)
{
	std::cout << elem << " ";
}

template <typename T>
void increment(T &elem)
{
	elem++;
}

int main(void)
{
	int ints[] = {1, 2, 3, 4, 5};
	std::cout << "Before : ";
	iter(ints, 5, print<int>);
	std::cout << std::endl;

	iter(ints, 5, increment<int>);

	std::cout << "After  : ";
	iter(ints, 5, print<int>);
	std::cout << std::endl;

	const int consts[] = {10, 20, 30};
	std::cout << "Const  : ";
	iter(consts, 3, print<int>);
	std::cout << std::endl;

	double doubles[] = {1.1, 2.2, 3.3};
	std::cout << "Doubles: ";
	iter(doubles, 3, print<double>);
	std::cout << std::endl;

	return 0;
}
