#include "Bureaucrat.hpp"
#include "AForm.hpp"

std::ostream& operator<< (std::ostream& stream, const Bureaucrat &src) {
	return (stream << src.getName() << ", bureaucrat grade " << src.getGrade() << ".");
}

//PRIVATE____________________________
Bureaucrat::Bureaucrat() : _name("Default"), _grade(LOWEST_GRADE)
{
	std::cout << "Default constructor called" << std::endl;
}

unsigned int	Bureaucrat::gradeValidation(unsigned int grade)
{
	if (grade > LOWEST_GRADE )
		throw GradeTooLowException();
	if (grade < HIGHEST_GRADE)
		throw GradeTooHighException();
	return (grade);
};

//PUBLIC__________________________________
//PUBLIC CONSTRUCTORS_____________________
Bureaucrat::Bureaucrat(std::string name, unsigned int grade) :
					_name(name),
					_grade(gradeValidation(grade))
{
	std::cout << "Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy) :
			_name(cpy._name),
			_grade(cpy._grade)
{
	std::cout << "Copy constructor has been called!" << std::endl;
};

Bureaucrat &Bureaucrat::operator= (const Bureaucrat &src)
{
	if (this != &src) {
		//_name = src._name;
		_grade = src._grade;
	}
	std::cout << "Overload = assignment has been called!" << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Bureaucrat destructor called" << std::endl;
}

// GETTERS________________________
std::string		Bureaucrat::getName() const {
	return (_name);
};
unsigned int	Bureaucrat::getGrade() const {
	return (_grade);
};


// SETTERS________________________
void	Bureaucrat::incrementGrade( void ) {
	if (_grade == HIGHEST_GRADE)
		throw GradeTooHighException();
	_grade--;
};

void	Bureaucrat::decrementGrade( void ) {
	if (_grade == LOWEST_GRADE)
		throw GradeTooLowException();
	_grade++;
};

// METHODS______________________________
void	Bureaucrat::signForm( AForm &form )
{
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << this->getName() << " couldn’t sign " << form.getName()
		<< " because " << e.what() << "." << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form) const
{
	try {
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception &e) {
		std::cerr << "Error: " << e.what() << '\n';
	}
}

// EXCEPTIONS ________________________
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Error: grade is too high (min is 1)";
}
const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Error: grade is too low (max is 150)";
}
