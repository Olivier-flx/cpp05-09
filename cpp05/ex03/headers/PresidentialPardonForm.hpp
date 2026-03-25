#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include <string>
#include "AForm.hpp"

class Bureaucrat;

//Required grades: sign 25, exec 5
// output : "<target> has been pardoned by Zaphod Beeblebrox"
class PresidentialPardonForm : public AForm
{
	private :
		std::string	_target;

	public :
		PresidentialPardonForm (std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &cpy);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
		~PresidentialPardonForm();

		void execute(Bureaucrat const & executor) const;

};

#endif

