#include "ScalarConverter.hpp"

std::ostream& operator<< (std::ostream& stream, const ScalarConverter &src) {
	//return (stream << ScalarConverter);
}

//PRIVATE____________________________
ScalarConverter::ScalarConverter( void )
{
	std::cout << "Default constructor called" << std::endl;
}

//PUBLIC__________________________________
//PUBLIC CONSTRUCTORS_____________________
ScalarConverter::ScalarConverter(std::string name, int grade) :
					_name(name),
					_grade(gradeValidation(grade))
{
	std::cout << "Constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &cpy) :
			_name(cpy._name),
			_grade(cpy._grade)
{
	std::cout << "Copy constructor has been called!" << std::endl;
};

ScalarConverter &ScalarConverter::operator= (const ScalarConverter &src)
{
	if (this != &src) {
		//_name = src._name;
		_grade = src._grade;
	}
	std::cout << "Overload = assignment has been called!" << std::endl;
	return *this;
}

ScalarConverter::~ScalarConverter(){
	std::cout << "destructor called" << std::endl;
}

// METHODS ________________________
static void	ScalarConverter::convert()
{

}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Error: grade is too high (min is 1)";
}
const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Error: grade is too low (max is 150)";
}
