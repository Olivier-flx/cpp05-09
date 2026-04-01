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

static void convertChar(char &c)
{
	if ( (c >= 20 && c < 127) 
		|| (c >= 9 && c <= 11) 
		|| c == 13 )
	{
		std::cout << "Char convert : " << c << std::endl; 

	}
	else
		throw ScalarConverter::CharNotDisplayableException();
}



static void	ScalarConverter::convert(std::string &str)
{
	if (str.lenght() == 0)
	{
		throw EmptyStringException();
		return;
	}
	if (str.lenght() >= 1)
	{
		if (str.lenght() == 1)
		{
			try {
				convertChar(str[0]);
			}
			catch (Exception &e)
			{
				std::cout << what(e) << std::endl;
			}
		}
		else 
		{
			try {
				convertInt(str);
			}
			try {
				convertFloat(str);
			}
			try {
				convertDouble(str);
			}
			catch (...)
			{
				std::cout << "Unexpected error" << std::endl;
			}
		}
	}
	return;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Error: grade is too high (min is 1)";
}
const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Error: grade is too low (max is 150)";
}
