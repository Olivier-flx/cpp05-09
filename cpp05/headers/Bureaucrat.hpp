#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150



class Bureaucrat {
	private :
		std::string		_name;
		unsigned int	_grade;

		Bureaucrat( void );
		// errors
			static void		GradeTooHighException();
			static void 	GradeTooLowException() ;
			static unsigned int	gradeValidation(unsigned int grade);

	public :
		Bureaucrat(std::string name, unsigned int grade);
		Bureaucrat(const Bureaucrat &cpy);
		Bureaucrat &operator=(const Bureaucrat &src);
		~Bureaucrat();

		//member functions
			std::string		getName(void) const;
			unsigned int	getGrade(void) const;
			void			incrementGrade(void);
			void			decrementGrade(void);
};

std::ostream& operator<<(std::ostream& stream, const Bureaucrat &src);


#endif
