#include "Serializer.hpp"

/////////////////////////////// PRIVATE ////////////////////////////////////////
// CONSTRUCTORS____________________________
Serializer::Serializer( void ) {
	std::cout << "Default constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &cpy) {
	(void) cpy;
};

Serializer &Serializer::operator=(const Serializer &src) {
	(void) src;
	return *this;
}

Serializer::~Serializer() {
	std::cout << "destructor called" << std::endl;
}

/////////////////////////////// PUBLIC ////////////////////////////////////////
// METHODS ________________________

uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

//DOCUMENTATION__________________
//https://www.geeksforgeeks.org/cpp/serialize-and-deserialize-an-object-in-cpp/
//https://en.cppreference.com/w/cpp/language/reinterpret_cast.html
