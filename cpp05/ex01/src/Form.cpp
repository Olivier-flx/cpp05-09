#include "Form.hpp"

std::ostream& operator<< (std::ostream& stream, const Form &src) {
	return (stream << src.getName() << ", Form grade " << src.getGrade() << ".");
}

//PRIVATE____________________________
Form::Form() : _name("Default"), _isSigned(false), _gradeToSign(HIGHEST_GRADE), _gradeToExec(HIGHEST_GRADE)
{
	std::cout << "Default constructor called" << std::endl;
}

unsigned int	Form::gradeValidation(unsigned int grade)
{
	if (grade > LOWEST_GRADE )
		throw GradeTooLowException();
	if (grade < HIGHEST_GRADE)
		throw GradeTooHighException();
	return (grade);
};

//PUBLIC__________________________________
//PUBLIC CONSTRUCTORS_____________________
Form::Form(std::string name, unsigned int grade) :
					_name(name),
					_grade(gradeValidation(grade))
{
	std::cout << "Constructor called" << std::endl;
}

Form::Form(const Form &cpy) :
			_name(cpy._name),
			_grade(cpy._grade)
{
	std::cout << "Copy constructor has been called!" << std::endl;
};

Form &Form::operator= (const Form &src)
{
	if (this != &src) {
		//_name = src._name;
		_grade = src._grade;
	}
	std::cout << "Overload = assignment has been called!" << std::endl;
	return *this;
}

Form::~Form(){
	std::cout << "destructor called" << std::endl;
}

// GETTERS________________________
std::string		Form::getName() const {
	return (_name);
};
unsigned int	Form::getGrade() const {
	return (_grade);
};


// SETTERS________________________
void	Form::incrementGrade(void) {
	if (_grade == HIGHEST_GRADE)
		throw GradeTooHighException();
	_grade--;
};

void	Form::decrementGrade(void) {
	if (_grade == LOWEST_GRADE)
		throw GradeTooLowException();
	_grade++;
};

// EXCEPTIONS ________________________
const char* Form::GradeTooHighException::what() const throw() {
	return "Error: grade is too high (min is 1)";
}
const char* Form::GradeTooLowException::what() const throw() {
	return "Error: grade is too low (max is 150)";
}
