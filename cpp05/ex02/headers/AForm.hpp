#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm {
	private :
		const std::string	_name;
		bool				_isSigned;
		const unsigned int	_gradeToSign;
		const unsigned int	_gradeToExec;

		AForm( void );
		//Error check___________
			static unsigned int	gradeValidation(unsigned int grade);

	public :
		virtual void execute(Bureaucrat const & executor) const = 0;


		AForm(std::string name, unsigned int gradeToSign, unsigned int _gradeToExec);
		AForm(const AForm &cpy);
		AForm &operator=(const AForm &src);
		~AForm();

		//Getters________
			std::string		getName(void) const;
			bool			getIsSigned() const;
			unsigned int	getGradeToSign(void) const;
			unsigned int	getGradeToExec(void) const;

		//Setters________
			void			beSigned(const Bureaucrat &B);

		// METHODS_________
			void	execute(Bureaucrat const & executor) const;


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

std::ostream& operator<<(std::ostream& stream, const AForm &src);

#endif
