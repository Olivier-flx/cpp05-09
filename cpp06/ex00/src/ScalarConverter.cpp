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



// HELPERS

bool	ScalarConverter::isChar(const std::string &str) const
{
	if (str.size() == 1)
	{
		char c = str[0];
		return(!std::isdigit(c))
	}
	else
		return (false);
}

bool	ScalarConverter::isInterger(const std::string &str) const
{
	std::string::iterator it = str.begin();
	if (*it == '+' || *it = '-')
		it++;
	while (it != str.end() && std::isdigit(*it))
		++it;
	return !str.empty() && it == str.end();
}

bool	ScalarConverter::isFloat(const std::string &str) const
{
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return (true);
	 if (str.empty() || str == "f" || str == ".f")
		return (false);
	std::string::iterator it = str.begin();
	if (*it == '+' || *it == '-')
		it++;

	int hasDot = 0;
	int hasDigit = 0;
	while (it != str.end())
	{
		if (std::isdigit(*it))
			hasDigit = 1;
		else if (*it == '.')
		{
			if (hasDot)
				return (false);
			hasDot = 1;
		}
		else if (*it == 'f')
			return (hasDigit && hasDot && str.end() == it + 1);
		else
			return (false);
		it++;
	}
	return (false);
}

bool	ScalarConverter::isDouble(const std::string &str) const
{
	if (str == "-inf" || str == "+inf" || str == "nan")
		return (true);
	 if (str.empty() || str == ".")
		return (false);
	std::string::iterator it = str.begin();
	if (*it == '+' || *it == '-')
		it++;

	int hasDot = 0;
	int hasDigit = 0;
	while (it != str.end())
	{
		if (std::isdigit(*it))
			hasDigit = 1;
		else if (*it == '.')
		{
			if (hasDot)
				return (false);
			hasDot = 1;
		}
		else
			return (false);
		it++;
	}
	return (hasDigit && hasDot);
}

// CONVERTERS _________________________
void	ScalarConverter::convertChar(const std::string &str) const
{
	char c = str[0];
	if (std::isprint(c))
	{
		int r = c - 0;
		std::cout << "Char convert : " << c << std::endl;
	}
	else
	{
		std::cout << " non-displayable characters" << std::endl;
		throw ScalarConverter::CharNotDisplayableException();
	}
}

void	convertInt(const std::string &str) const
{

}





// METHODS ________________________
static void	ScalarConverter::convert(std::string &str)
{
	if (str.empty())
	{
		throw EmptyStringException();
		return;
	}
	if (ischar(str))
		convertChar(str);
	else if (isInteger(str))
		convertInt(str);
	else if (isFloat(str))
		convertFloat(str);
	else if (isDouble(str))
		convertDouble(str);
	else
		std::cout << "Err : Unknown type." << std::endl;
	return;
}

const char* ScalarConverter::CharNotDisplayableException::what() const throw() {
	return "Error : not displayable char";
}

const char *ScalarConverter::EmptyStringException::what() const throw() {
	return "Error : String param is empty";
}
