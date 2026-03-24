#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150



class Form {
	private :
		const std::string	_name;
		bool				_isSigned;
		unsigned int		_gradeToSign;
		unsigned int		_gradeToExec;

		Form( void );
		//Error check___________
			static unsigned int	gradeValidation(unsigned int grade);

	public :
		Form(std::string name, unsigned int grade);
		Form(const Form &cpy);
		Form &operator=(const Form &src);
		~Form();

		//member functions
			std::string		getName(void) const;
			unsigned int	getGrade(void) const;
			void			incrementGrade(void);
			void			decrementGrade(void);

		//Error / Exeptions
			class GradeTooHighException : public std::exception {
				public:
					virtual const char* what() const throw();
			};
			// throw() = garantie que what() ne lance pas elle-même d'exception

			class GradeTooLowException : public std::exception {
				public:
					virtual const char* what() const throw();
			};
};

std::ostream& operator<<(std::ostream& stream, const Form &src);

#endif
