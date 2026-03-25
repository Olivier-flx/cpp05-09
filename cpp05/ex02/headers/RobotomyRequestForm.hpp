#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include <string>
#include <cstdlib>
#include <ctime>

#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private :
		std::string	_target;

	public :
		RobotomyRequestForm (std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &cpy);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
		~RobotomyRequestForm();

		void execute(Bureaucrat const & executor) const;

};

#endif
