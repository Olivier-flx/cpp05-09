#include "ScalarConverter.hpp"

//PRIVATE____________________________
ScalarConverter::ScalarConverter( void ) {
	std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &cpy) {
	(void) cpy;
};

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src) {
	(void) src;
	return *this;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "destructor called" << std::endl;
}



// HELPERS

bool	ScalarConverter::isChar(const std::string &str)
{
	if (str.size() == 1)
		return(!std::isdigit(str[0]));
	return (false);
}

bool	ScalarConverter::isInt(const std::string &str)
{
	std::string::const_iterator it = str.begin();
	if (*it == '+' || *it == '-')
		it++;

	int hasDigit = 0;
	while (it != str.end() && std::isdigit(*it))
	{
		hasDigit++;
		++it;
	}
	return (!str.empty() && it == str.end() && hasDigit > 0);
}

bool	ScalarConverter::isFloat(const std::string &str)
{
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return (true);
	 if (str.empty() || str == "f" || str == ".f")
		return (false);
	std::string::const_iterator it = str.begin();
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

bool	ScalarConverter::isDouble(const std::string &str)
{
	if (str == "-inf" || str == "+inf" || str == "nan")
		return (true);
	 if (str.empty() || str == ".")
		return (false);
	std::string::const_iterator it = str.begin();
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
void	ScalarConverter::convertChar(const std::string &str)
{
	double d = static_cast<double>(str[0]);
	displayAll(d);
}

void	ScalarConverter::convertInt(const std::string &str)
{
	long l = std::strtol(str.c_str(), NULL, 10);
	displayAll(static_cast<double>(l));
}

void	ScalarConverter::convertFloat(const std::string &str)
{
	float f = std::strtof(str.c_str(), NULL); // strtof gère nan/inf/-inff/+inff
	displayAll(static_cast<double>(f));
}

void	ScalarConverter::convertDouble(const std::string &str)
{
	double d = std::strtod(str.c_str(), NULL); //strtod gère nan/inf/-inf/+inf
	displayAll(d);
}

//DISPLAY OUTPUT______

void	ScalarConverter::displayAll(double d)
{
	// --- char ---
	if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(d)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;

	// --- int ---
	if (std::isnan(d) || std::isinf(d) || d > INT_MAX || d < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;

	// --- float ---
	float f = static_cast<float>(d);
	std::cout << "float: ";
	if (std::isnan(f))
		std::cout << "nanf" << std::endl;
	else if (std::isinf(f))
		std::cout << (f > 0 ? "+inff" : "-inff") << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;

	// --- double ---
	std::cout << "double: ";
	if (std::isnan(d))
		std::cout << "nan" << std::endl;
	else if (std::isinf(d))
		std::cout << (d > 0 ? "+inf" : "-inf") << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << d << std::endl;

}


//EXCPTIONS________________________
const char* ScalarConverter::CharNotDisplayableException::what() const throw() {
	return "Error : not displayable char";
}

const char *ScalarConverter::EmptyStringException::what() const throw() {
	return "Error : String param is empty";
}


//PUBLIC__________________________________

// METHODS ________________________
void	ScalarConverter::convert(const std::string &str)
{
	if (str.empty())
	{
		throw EmptyStringException();
		return;
	}
	if (isChar(str))
		convertChar(str);
	else if (isInt(str))
		convertInt(str);
	else if (isFloat(str))
		convertFloat(str);
	else if (isDouble(str))
		convertDouble(str);
	else
		std::cout << "Err : Unknown type." << std::endl;
	return;
}

