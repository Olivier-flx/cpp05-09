#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>
#include <iostream>
#include <exception>

class ScalarConverter {
	private :
		ScalarConverter( void );
		ScalarConverter(const ScalarConverter &cpy);
		ScalarConverter &operator=(const ScalarConverter &src);
		~ScalarConverter();


		bool	ischar(const std::string &str) const;
		bool	isInteger(const std::string &str) const;
		bool	isFloat(const std::string &str) const;
		bool	isDouble(const std::string &str) const;
		bool	isInfinite(const std::string &str) const;

		void	convertChar(const std::string &str) const;
		void	convertInt(const std::string &str) const;
		void	convertFloat(const std::string &str) const;
		void	convertDouble(const std::string &str) const;

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
		static void	convert(std::string &str) const;


};

std::ostream& operator<<(std::ostream& stream, const ScalarConverter &src);

#endif
