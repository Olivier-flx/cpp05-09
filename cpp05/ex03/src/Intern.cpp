#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

//PUBLIC__________________________________
//PUBLIC CONSTRUCTORS_____________________
Intern::Intern(){
	std::cout << "Intern default constructor called" << std::endl;
}


Intern::Intern(const Intern &cpy) {
	*this = cpy;
	std::cout << "Copy constructor has been called!" << std::endl;
};

Intern &Intern::operator= (const Intern &src)
{
	(void) src;
	std::cout << "Overload = assignment has been called!" << std::endl;
	return *this;
}

Intern::~Intern(){
	std::cout << "Intern destructor called" << std::endl;
}

// METHODS______________________________
AForm	*Intern::makeForm(std::string name, std::string target)
{
	std::string	accepted_type_form[3] = {
										"shrubbery creation",
										"robotomy request",
										"presidential pardon form"
										};

	int	formIndex = -1;
	for (size_t i = 0; i < 3; i++)
	{
		if (name == accepted_type_form[i]) {
			formIndex = i;
			break;
		}
	}

	AForm* newForm = NULL;
	switch (formIndex)
	{
	case 0:
		newForm = new ShrubberyCreationForm(target);
		break;
	case 1:
		newForm = new RobotomyRequestForm(target);
		break;
	case 2:
		newForm = new PresidentialPardonForm(target);
		break;

	default:
		std::cerr << "Error: Intern cannot create '" << name << "' because this form doesn't exist." << std::endl;
		return NULL;
	}

	std::cout << "Intern creates " << name << std::endl;
	return (newForm);
}
