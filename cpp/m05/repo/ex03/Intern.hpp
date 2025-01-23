#ifndef INTERN_H
# define INTERN_H

# include <iostream>

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

//This class could have been a simple function :(

class Intern {
	public:
		Intern();
		~Intern();
		AForm *makeForm(std::string const &name, std::string const &target) const;
	private:
		Intern(Intern const &i);
		Intern &operator=(Intern const &i);
};

#endif