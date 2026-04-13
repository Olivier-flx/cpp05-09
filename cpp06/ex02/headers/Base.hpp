#ifndef BASE_HPP
#define BASE_HPP

#include <cstdlib>
#include <string>
#include <iostream>

#include <ctime>


class Base {
	private :
	public :
		virtual ~Base();
};

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif
