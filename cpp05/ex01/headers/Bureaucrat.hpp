#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150


class Form;

class Bureaucrat {
	private :
		const std::string	_name;
		int		_grade;

		Bureaucrat( void );
		//Error check___________
			static int	gradeValidation(int grade);

	public :
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &cpy);
		Bureaucrat &operator=(const Bureaucrat &src);
		~Bureaucrat();

		//member functions
			std::string		getName( void ) const;
			int	getGrade( void ) const;
			void			incrementGrade( void );
			void			decrementGrade( void );

			void			signForm( Form &form );

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

std::ostream& operator<<(std::ostream& stream, const Bureaucrat &src);

#endif
