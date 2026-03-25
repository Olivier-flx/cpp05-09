#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm (std::string target)
		: AForm("Robotomy Creation", 72, 45),
		_target(target)
{
	std::cout << "Robotomy Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy)
		: AForm(cpy),
		_target(cpy._target)
{
	std::cout << "Robotomy Copy Constructor called" << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator= (const RobotomyRequestForm &src)
{
	if (this != &src) {
		AForm::operator=(src);
		this->_target = src._target;
	}
	std::cout << "RobotomyRequestForm Overload = assignment has been called!" << std::endl;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << "Robotomy Destructor called" << std::endl;
}

// METHODS_________________________
void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException();
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (this->getIsExecuted())
		throw AForm::AlreadyExecutedException();

	std::cout << _target << "   Drill starting---- " << std::endl;
	std::cout << "Driiiiiiiiiiiiillll Driiiiiiiiiiiiillll " << std::endl;

	std::srand(std::time(0));
	if (rand() % 2)
		std::cout << _target << " has been sucessfly robotomized!" << std::endl;
	else
		std::cout << _target << " failed to robotomize!" << std::endl;

	this->getIsExecuted();
}
//Random number function
//https://www.youtube.com/watch?v=-NA_B_vJP14
