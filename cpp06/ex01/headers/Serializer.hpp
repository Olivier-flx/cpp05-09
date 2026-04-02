#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdlib>
#include <string>
#include <iostream>

#include "data.hpp"

/* Inclusion de la bibliothèque standard pour uintptr_t  */
#include <stdint.h>


class Serializer {
	private :
		Serializer( void );
		Serializer(const Serializer &cpy);
		Serializer &operator=(const Serializer &src);
		~Serializer();

	public :
		//member functions
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif
