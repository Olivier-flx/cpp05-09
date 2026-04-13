#include "Base.hpp"
#include "ABC.hpp"

/////////////////////////////// PRIVATE ////////////////////////////////////////
// CONSTRUCTORS____________________________

Serializer::~Base() {
	std::cout << "destructor called" << std::endl;
}

///////////////////////////////////////////////////////////////////////
//  ________________________

Base	*generate(void)
{
	switch (std::rand() % 3)
	{
		case 0:
			std::cout << "A class created" << std::endl;
			return (new A());
		case 1:
			std::cout << "B class created" << std::endl;
			return (new B());
		case 2:
			std::cout << "C class created" << std::endl;
			return (new C());
		default:
			exit(1);
	}
}

void identify(Base* p);
{
	std::cout << "identify(Base* p)" << std::endl;
	if (dynamic_cast<A *> (p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B *> (p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C *> (p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Err : type not defined" << std::endl;
}

void identify(Base& p);
{
	std::cout << "identify(Base& p)" << std::endl;
	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return;
	} catch (const std::exception &e) {
	}
	try {
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return;
	} catch (const std::exception &e) {
	}
	try {
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return;
	} catch (const std::exception &e) {
		std::cout << "Err : type not identified" << std::endl;
	}
}


// DOCUMENTATION__________________
//https://www.linkedin.com/pulse/how-get-real-type-object-c-konstantin-nikitin
// Run-Time type information (RTTI)
