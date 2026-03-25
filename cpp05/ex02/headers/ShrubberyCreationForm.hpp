#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include <string>
#include <iostream>
#include <exception>

#include "AForm.hpp"
class Bureaucrat;

class ShrubberyCreationForm : public AForm{
	private :
		std::string	_target;


	public :
		ShrubberyCreationForm (std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &cpy);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
		~ShrubberyCreationForm();

		void execute(Bureaucrat const & executor) const;
};

#endif
