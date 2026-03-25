#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm (std::string target)
		: AForm("Shrubbery Creation", 145, 137),
		_target(target)
{
	std::cout << "Shrubbery Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy)
		: AForm(cpy.getName(), cpy.getGradeToSign(), cpy.getGradeToExec()),
		_target(cpy._target)
{
	std::cout << "Shrubbery Copy Constructor called" << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator= (const ShrubberyCreationForm &src)
{
	if (this != &src) {
		if (src.getIsSigned())
			setSigned();
		if (src.getIsExecuted())
			setExecuted();
	}
	std::cout << "ShrubberyCreationForm Overload = assignment has been called!" << std::endl;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout << "Shrubbery Destructor called" << std::endl;
}



// METHODS_________________________
void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException();
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (this->getIsExecuted())
		throw AForm::AlreadyExecutedException();

	std::ofstream outFile(_target + "_shrubbery");
	if (!outFile.is_open()) {
		std::cerr << "Error: Could not create the file!" << std::endl;
		return ;
	}

	outFile << "          &&& &&  & &&\n";
	outFile << "      && &\\/&\\|& ()|/ @,&\n";
	outFile << "      &\\/(/&/&||/& /_/)_&/&\n";
	outFile << "   &() &\\/&|()|/&\\/ '%\" & ()\n";
	outFile << "  &_\\_&&_\\ |& |&&/&__%_/_& &&\n";
	outFile << "&&   && & &| &| /& & % ()& /&&\n";
	outFile << " ()&_---()&\\&\\|&&-&&--%---()~\n";
	outFile << "     &&     \\|||\n";
	outFile << "             |||\n";
	outFile << "             |||\n";
	outFile << "             |||\n";
	outFile << "       , -=-~  .-^- _\n";

	outFile.close();
}
