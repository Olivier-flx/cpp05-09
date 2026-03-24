#include "Form.hpp"
#include "Bureaucrat.hpp"

std::ostream& operator<< (std::ostream& stream, const Form &src) {
	return (
		stream << "=== Form information ===\n"
				<< "Name : " << src.getName() << std::endl
				<< "Signed : " << src.getIsSigned() << std::endl
				<< "Grade to sign :\t " << src.getGradeToSign() << std::endl
				<< "Grade to execute :\t " << src.getGradeToExec() << std::endl
	);
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
Form::Form(std::string name, unsigned int gradeToSign, unsigned int gradeToExec) :
					_name(name),
					_isSigned(false),
					_gradeToSign(gradeValidation(gradeToSign)),
					_gradeToExec(gradeValidation(gradeToExec))
{
	std::cout << "Constructor called" << std::endl;
}

Form::Form(const Form &cpy) :
			_name(cpy._name),
			_isSigned(cpy._isSigned),
			_gradeToSign(cpy._gradeToSign),
			_gradeToExec(cpy._gradeToExec)
{
	std::cout << "Copy constructor has been called!" << std::endl;
};

Form &Form::operator= (const Form &src)
{
	if (this != &src) {
		_isSigned = src._isSigned;
	}
	std::cout << "Overload = assignment has been called!" << std::endl;
	return *this;
}

Form::~Form(){
	std::cout << "destructor called" << std::endl;
}

// GETTERS________________________
std::string		Form::getName() const			{ return (_name);};
bool			Form::getIsSigned() const		{ return (_isSigned);};
unsigned int	Form::getGradeToSign() const	{ return (_gradeToSign);};
unsigned int	Form::getGradeToExec() const	{ return (_gradeToExec);};


// SETTERS________________________
void	Form::beSigned(const Bureaucrat &B)
{
	if (B.getGrade() > this->getGradeToSign())
		throw Form::GradeTooLowException();
	_isSigned = true;
}


// EXCEPTIONS ________________________
const char* Form::GradeTooHighException::what() const throw() {
	return "Error: grade is too high (min is 1)";
}
const char* Form::GradeTooLowException::what() const throw() {
	return "Error: grade is too low to sign or execute";
}
