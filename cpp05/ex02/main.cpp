#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main (void)
{
	Bureaucrat	B1("B1", 1);
	std::cerr << B1 << std::endl;
	try {
		B1.incrementGrade();
	}
	catch (std::exception & e) {
		std::cerr << "Error caught: " << e.what() << " for " << B1.getName() << std::endl;
	}

	ShrubberyCreationForm s1("Jardin");

	try { B1.signForm(s1);}
	catch(const std::exception& e) { std::cerr << "Error caught: " << e.what() << '\n'; }



	try { B1.decrementGrade();}
	catch(const std::exception& e) { std::cerr << "Error caught: " << e.what() << '\n'; }

	try { B1.signForm(s1) ;}
	catch(const std::exception& e) {
		std::cerr << "Error caught: " << e.what() << '\n';
	}




	std::cout << B1 << std::endl;
	try {
		Bureaucrat B2("B2", 0);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat B3("B3", 151);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	Bureaucrat B4("B4", 150);
	std::cout << B4 << std::endl;
	try {
		B4.decrementGrade();
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
