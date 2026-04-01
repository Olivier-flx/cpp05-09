#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>
#include <iostream>
#include <exception>

class ScalarConverter {
	private :

	public :
	ScalarConverter( void );
	ScalarConverter(const ScalarConverter &cpy);
	ScalarConverter &operator=(const ScalarConverter &src);
	~ScalarConverter();

		//member functions
		static void	convert(std::string &str) const;

	class CharNotDisplayableException : public Exception {
		throw ("Error : not displayable char");

	};
	class EmptyStringException : public Exception {
		throw ("Error : String param is empty");
	};
};

std::ostream& operator<<(std::ostream& stream, const ScalarConverter &src);

#endif
