#include "Base.hpp"
#include "ABC.hpp"

/////////////////////////////// PRIVATE ////////////////////////////////////////
// CONSTRUCTORS____________________________

Base::~Base() {
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

void identify(Base* p)
{
	std::cout << "identify(Base* p)" << std::endl;
	if (NULL != dynamic_cast<A *> (p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *> (p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *> (p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Err : type not defined" << std::endl;
}

void identify(Base& p)
{
	std::cout << "identify(Base& p)" << std::endl;
	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return;
	} catch (...) {
	}
	try {
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return;
	} catch (...) {
	}
	try {
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return;
	} catch (...) {
		std::cout << "Err : type not identified" << std::endl;
	}
}


// DOCUMENTATION__________________
//https://www.linkedin.com/pulse/how-get-real-type-object-c-konstantin-nikitin
// Run-Time type information (RTTI)

// https://en.cppreference.com/w/cpp/language/dynamic_cast.html

/**
 * manière dont dynamic_cast réagit en cas d'échec (c'est-à-dire quand tu essaies de caster vers le mauvais type). Son comportement change selon que tu l'utilises avec des pointeurs ou des références.

Avec des pointeurs (Base* p) :
Si dynamic_cast<A*>(p) échoue, il renvoie simplement un pointeur nul (NULL ou nullptr). Il suffit donc de faire un simple if (dynamic_cast<A*>(p)) pour vérifier si le cast a réussi. C'est propre et ça ne plante pas.

Avec des références (Base& p) :
En C++, une référence ne peut pas être nulle. Elle doit toujours pointer vers un objet valide. Par conséquent, si dynamic_cast<A&>(p) échoue, il ne peut pas renvoyer "une référence nulle" car cela n'existe pas. À la place, il lève une exception de type std::bad_cast.
 */

