#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm (std::string target)
		: AForm("PresidentialPardon Creation", 25, 5),
		_target(target)
{
	std::cout << "PresidentialPardon Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpy)
		: AForm(cpy),
		_target(cpy._target)
{
	std::cout << "PresidentialPardon Copy Constructor called" << std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator= (const PresidentialPardonForm &src)
{
	if (this != &src) {
		AForm::operator=(src);
		this->_target = src._target;
	}
	std::cout << "PresidentialPardonForm Overload = assignment has been called!" << std::endl;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout << "PresidentialPardon Destructor called" << std::endl;
}

// METHODS_________________________
void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException();
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	// if (this->getIsExecuted())
	// 	throw AForm::AlreadyExecutedException();

	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	//this->setExecuted();
}
