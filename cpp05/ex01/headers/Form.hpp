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
		const int	_gradeToSign;
		const int	_gradeToExec;

		Form( void );
		//Error check___________
			static int	gradeValidation(int grade);

	public :
		Form(std::string name, int gradeToSign, int _gradeToExec);
		Form(const Form &cpy);
		Form &operator=(const Form &src);
		~Form();

		//Getters________
			std::string		getName(void) const;
			bool			getIsSigned() const;
			int	getGradeToSign(void) const;
			int	getGradeToExec(void) const;

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
