#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

//VIRTUAL
class AForm {
	private :
		const std::string	_name;
		bool				_isSigned;
		bool				_isExecuted;
		const unsigned int	_gradeToSign;
		const unsigned int	_gradeToExec;

		AForm( void );
		//Error check___________
			static unsigned int	gradeValidation(unsigned int grade);

	public :
		AForm(std::string name, unsigned int gradeToSign, unsigned int _gradeToExec);
		AForm(const AForm &cpy);
		AForm &operator=(const AForm &src);
		~AForm();

		//Getters________
			std::string		getName(void) const;
			bool			getIsSigned() const;
			bool			getIsExecuted() const;
			unsigned int	getGradeToSign(void) const;
			unsigned int	getGradeToExec(void) const;

		//Setters________
			void			beSigned(const Bureaucrat &B);
			void			setExecuted();
			void			setSigned();

		// METHODS_________
			virtual void execute(Bureaucrat const & executor) const = 0;


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

			class FormNotSignedException : public std::exception {
				public:
					virtual const char* what() const throw();
			};

			class AlreadyExecutedException : public std::exception {
				public:
					virtual const char* what() const throw();
			};
};

std::ostream& operator<<(std::ostream& stream, const AForm &src);

#endif
