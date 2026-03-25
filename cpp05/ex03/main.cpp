#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <cstdlib>
#include <ctime>

int	main (void)
{
	//for RobotomyRequestForm random robotomy result
	std::srand(std::time(0));

/////
	std::cout << "\n================ CREATING BUREAUCRATS ================\n" << std::endl;
	Bureaucrat	B1("Boss", 1);
	Bureaucrat	B2("Intern", 140);

	std::cout << B1 << std::endl;
	std::cout << B2 << std::endl;

	std::cout << "\n================ CREATING FORMS ================\n" << std::endl;
	ShrubberyCreationForm	s1("Jardin");
	RobotomyRequestForm		r1("Oliv");
	PresidentialPardonForm	p1("Bellamy");

	std::cout << s1 << std::endl;

	std::cout << "\n================ TEST: UNSIGNED FORM ================\n" << std::endl;
	try { B1.executeForm(s1); }
	catch(const std::exception& e) { std::cerr << "Error caught: " << e.what() << '\n'; }

	std::cout << "\n================ TEST: SHRUBBERY ================\n" << std::endl;
	// Intern a le grade 140. Requis pour Shrubbery : Sign 145 / Exec 137
	try { B2.signForm(s1); }
	catch(const std::exception& e) { std::cerr << "Error caught: " << e.what() << '\n'; }

	try { B2.executeForm(s1); } // Doit échouer (140 > 137)
	catch(const std::exception& e) { std::cerr << "Error caught: " << e.what() << '\n'; }

	try { B1.executeForm(s1); } // Boss (grade 1) doit réussir
	catch(const std::exception& e) { std::cerr << "Error caught: " << e.what() << '\n'; }

	std::cout << "\n================ TEST: ROBOTOMY ================\n" << std::endl;
	// Boss a le grade 1. Requis pour Robotomy : Sign 72 / Exec 45
	try { B1.signForm(r1); }
	catch(const std::exception& e) { std::cerr << "Error caught: " << e.what() << '\n'; }

	// On l'exécute plusieurs fois pour tester le hasard 50/50 !
	try { B1.executeForm(r1); } catch(const std::exception& e) { std::cerr << "Error caught: " << e.what() << '\n'; }
	std::cout << "_____\n" << std::endl;
	try { B1.executeForm(r1); } catch(const std::exception& e) { std::cerr << "Error caught: " << e.what() << '\n'; }
	std::cout << "_____\n" << std::endl;
	try { B1.executeForm(r1); } catch(const std::exception& e) { std::cerr << "Error caught: " << e.what() << '\n'; }
	std::cout << "_____\n" << std::endl;
	try { B1.executeForm(r1); } catch(const std::exception& e) { std::cerr << "Error caught: " << e.what() << '\n'; }
	std::cout << "_____\n" << std::endl;
	try { B1.executeForm(r1); } catch(const std::exception& e) { std::cerr << "Error caught: " << e.what() << '\n'; }
	std::cout << "_____\n" << std::endl;
	try { B1.executeForm(r1); } catch(const std::exception& e) { std::cerr << "Error caught: " << e.what() << '\n'; }
	std::cout << "_____\n" << std::endl;
	try { B1.executeForm(r1); } catch(const std::exception& e) { std::cerr << "Error caught: " << e.what() << '\n'; }
	std::cout << "_____\n" << std::endl;
	try { B1.executeForm(r1); } catch(const std::exception& e) { std::cerr << "Error caught: " << e.what() << '\n'; }

	std::cout << "\n================ TEST: PRESIDENTIAL PARDON ================\n" << std::endl;
	// Requis pour Pardon : Sign 25 / Exec 5
	try { B2.signForm(p1); } // Intern (140) essaie de signer : doit échouer
	catch(const std::exception& e) { std::cerr << "Error caught: " << e.what() << '\n'; }

	try { B1.signForm(p1); } // Boss signe : succès
	catch(const std::exception& e) { std::cerr << "Error caught: " << e.what() << '\n'; }

	try { B1.executeForm(p1); } // Boss exécute : succès
	catch(const std::exception& e) { std::cerr << "Error caught: " << e.what() << '\n'; }

	std::cout << std::endl;

	std::cout << "\n\n================ TEST: INTERNS ================\n" << std::endl;

	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << std::endl;
	if (!rrf) {
		std::cout << "rrf is NULL" << std::endl;
	}
	else
	{
		try { B1.signForm(*rrf); } catch(const std::exception& e) { std::cerr << "Error caught: " << e.what() << '\n'; }
		try { B1.executeForm(*rrf); } catch(const std::exception& e) { std::cerr << "Error caught: " << e.what() << '\n'; }
		try { B2.executeForm(*rrf); } catch(const std::exception& e) { std::cerr << "Error caught: " << e.what() << '\n'; }
		delete rrf;
	}
	AForm* failForm;
	failForm = someRandomIntern.makeForm("papiers du vehicule", "Bender");

	if (failForm != NULL) {
		delete failForm;
	}
	else
	{
		std::cout << "pointeur Is NULL, and it's normal" << std::endl;
	}


	return 0;
}
