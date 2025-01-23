#ifndef PRESIDENTIAL_PARDON_FORM_H
# define PRESIDENTIAL_PARDON_FORM_H

# include <iostream>
# include <cstdlib>
# include <ctime>

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm(std::string const &target);
		~PresidentialPardonForm();
		std::string const &getTarget() const;
	protected:
		void doThing() const;
	private:
		std::string const target;
		PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const &f);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &f);
};

#endif