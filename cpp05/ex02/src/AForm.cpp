#include "AForm.hpp"
#include "Bureaucrat.hpp"

std::ostream& operator<< (std::ostream& stream, const AForm &src) {
	return (
		stream << "=== Form information ===\n"
				<< "Name : " << src.getName() << std::endl
				<< "Signed : " << src.getIsSigned() << std::endl
				<< "Grade to sign :\t " << src.getGradeToSign() << std::endl
				<< "Grade to execute :\t " << src.getGradeToExec() << std::endl
	);
}

//PRIVATE____________________________
AForm::AForm() : _name("Default"), _isSigned(false), _gradeToSign(HIGHEST_GRADE), _gradeToExec(HIGHEST_GRADE)
{
	std::cout << "Default constructor called" << std::endl;
}

unsigned int	AForm::gradeValidation(unsigned int grade)
{
	if (grade > LOWEST_GRADE )
		throw GradeTooLowException();
	if (grade < HIGHEST_GRADE)
		throw GradeTooHighException();
	return (grade);
};

//PUBLIC__________________________________
//PUBLIC CONSTRUCTORS_____________________
AForm::AForm(std::string name, unsigned int gradeToSign, unsigned int gradeToExec) :
					_name(name),
					_isSigned(false),
					_gradeToSign(gradeValidation(gradeToSign)),
					_gradeToExec(gradeValidation(gradeToExec))
{
	std::cout << "Constructor called" << std::endl;
}

AForm::AForm(const AForm &cpy) :
			_name(cpy._name),
			_isSigned(cpy._isSigned),
			_gradeToSign(cpy._gradeToSign),
			_gradeToExec(cpy._gradeToExec)
{
	std::cout << "Copy constructor has been called!" << std::endl;
};

AForm &AForm::operator= (const AForm &src)
{
	if (this != &src) {
		_isSigned = src._isSigned;
	}
	std::cout << "Overload = assignment has been called!" << std::endl;
	return *this;
}

AForm::~AForm(){
	std::cout << "destructor called" << std::endl;
}

// GETTERS________________________
std::string		AForm::getName() const			{ return (_name);};
bool			AForm::getIsSigned() const		{ return (_isSigned);};
unsigned int	AForm::getGradeToSign() const	{ return (_gradeToSign);};
unsigned int	AForm::getGradeToExec() const	{ return (_gradeToExec);};


// SETTERS________________________
void	AForm::beSigned(const Bureaucrat &B)
{
	if (B.getGrade() > this->getGradeToSign())
		throw AForm::GradeTooLowException();
	_isSigned = true;
}


// EXCEPTIONS ________________________
const char* AForm::GradeTooHighException::what() const throw() {
	return "Error: grade is too high (min is 1)";
}
const char* AForm::GradeTooLowException::what() const throw() {
	return "Error: grade is too low to sign or execute";
}
