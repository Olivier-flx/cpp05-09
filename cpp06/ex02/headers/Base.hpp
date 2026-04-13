#ifndef BASE_HPP
#define BASE_HPP

#include <cstdlib>
#include <string>
#include <iostream>

/* Inclusion de la bibliothèque standard pour uintptr_t  */
#include <stdint.h>


class Base {
	private :

	public :
		virtual ~Base();

		//member functions
		Base * generate(void);
		void identify(Base* p);
		void identify(Base& p);
};

#endif
