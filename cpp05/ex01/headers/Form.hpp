#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class Form {
	private :
		const std::string	_name;
		bool				_isSigned;
		const unsigned int	_gradeToSign;
		const unsigned int	_gradeToExec;

		Form( void );
		//Error check___________
			static unsigned int	gradeValidation(unsigned int grade);

	public :
		Form(std::string name, unsigned int gradeToSign, unsigned int _gradeToExec);
		Form(const Form &cpy);
		Form &operator=(const Form &src);
		~Form();

		//Getters________
			std::string		getName(void) const;
			bool			getIsSigned() const;
			unsigned int	getGradeToSign(void) const;
			unsigned int	getGradeToExec(void) const;

		//Setters________
			void			beSigned(const Bureaucrat &B);

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
