#include "Array.hpp"

template <typename T>
Array<T>::Array() : _data(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(const Array &cpy) : _data(NULL), _size(0)
{
	*this = cpy;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &src)
{
	if (this == &src)
		return *this;
	delete[] _data;
	_size = src._size;
	_data = new T[_size]();
	for (unsigned int i = 0; i < _size; i++)
		_data[i] = src._data[i];
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] _data;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::out_of_range("Array: index out of range");
	return _data[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw std::out_of_range("Array: index out of range");
	return _data[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}
