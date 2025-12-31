#include "Bureaucrat.hpp"

std::ostream& operator<< (std::ostream& stream, const Bureaucrat &src) {
	return (stream << src.getName() << ", bureaucrat grade " << src.getGrade());
}

Bureaucrat::Bureaucrat(){
	std::cout << "Default constructor called" << std::endl;
}

unsigned int	Bureaucrat::gradeValidation(unsigned int grade)
{
	if (grade > LOWEST_GRADE )
		GradeTooLowException();
	if (grade < HIGHEST_GRADE)
		GradeTooHighException();
	return (grade);
};

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name), _grade(gradeValidation(grade))
{
	std::cout << "Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy) {
	*this = cpy;
	std::cout << "Copy constructor has been called!" << std::endl;
};


Bureaucrat &Bureaucrat::operator= (const Bureaucrat &src)
{
	if (this != &src) {
		_name = src._name;
		_grade = src._grade;
	}
	std::cout << "Overload = assignment has been called!" << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat(){
	std::cout << "destructor called" << std::endl;
}

//////////
std::string		Bureaucrat::getName() const {
	return (_name);
};
unsigned int	Bureaucrat::getGrade() const {
	return (_grade);
};

void	Bureaucrat::incrementGrade(void) {
	if (_grade == HIGHEST_GRADE)
		GradeTooHighException();
	_grade--;
};

void	Bureaucrat::decrementGrade(void) {
	if (_grade == LOWEST_GRADE)
		GradeTooLowException();
	_grade++;
};

/// ERRORS ///
void	Bureaucrat::GradeTooHighException() {
	throw std::out_of_range("Error : grade is too high");
};
void 	Bureaucrat::GradeTooLowException() {
	throw std::out_of_range("Error : grade is too low");
}
