#include "Bureaucrat.hpp"

int	main (void)
{
	Bureaucrat	B1("B1", 1);
	std::cout << B1 << std::endl;
	try {
		B1.decrementGrade();
	}
	catch (std::exception & e) {
		std::cout << "error catched while incrementing grade of" << B1.getName() << std::endl;
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
