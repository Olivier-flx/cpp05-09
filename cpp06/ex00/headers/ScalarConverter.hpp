#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <cstdlib>
#include <string>
#include <iostream>
#include <exception>
#include <climits>
#include <cmath>
#include <iomanip>

class ScalarConverter {
	private :
		ScalarConverter( void );
		ScalarConverter(const ScalarConverter &cpy);
		ScalarConverter &operator=(const ScalarConverter &src);
		~ScalarConverter();


		static bool	isChar(const std::string &str);
		static bool	isInt(const std::string &str);
		static bool	isFloat(const std::string &str);
		static bool	isDouble(const std::string &str);

		static void	convertChar(const std::string &str);
		static void	convertInt(const std::string &str);
		static void	convertFloat(const std::string &str);
		static void	convertDouble(const std::string &str);

		static void	displayAll(double d);

		// EXCEPTIONS
			class CharNotDisplayableException : public std::exception {
				public:
					virtual const char* what() const throw();
			};
			class EmptyStringException : public std::exception {
				public:
					virtual const char * what() const throw();
			};

	public :
		//member functions
		static void	convert(const std::string &str);


};

#endif
