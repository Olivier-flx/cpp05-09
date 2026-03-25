#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>

class AForm;

class Intern {
	private :

	public :
		Intern();
		Intern(const Intern &cpy);
		Intern &operator=(const Intern &src);
		~Intern();

		//member functions
			AForm	*makeForm(std::string name, std::string target);
};

#endif
