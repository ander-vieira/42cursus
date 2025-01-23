#include "Intern.hpp"

static const std::string formNames[] = {"PPF", "RRF", "SCF"};

Intern::Intern() {
		std::cout << "Intern: created" << std::endl;
}
Intern::~Intern() {
		std::cout << "Intern: killed" << std::endl;
}

//This did not need to be a method of a class
AForm *Intern::makeForm(std::string const &name, std::string const &target) const {
	size_t formIndex;

	//This is infinitely more readable than an if-else block
	for(formIndex = 0 ; formIndex < formNames->length() ; formIndex++)
		if (name == formNames[formIndex])
			break;
	if (formIndex < formNames->length())
		std::cout << "Intern: creates form " << name << std::endl;
	switch(formIndex) {
		case 0:
			return new PresidentialPardonForm(target);
		case 1:
			return new RobotomyRequestForm(target);
		case 2:
			return new ShrubberyCreationForm(target);
		default:
			std::cout << "Intern: could not create form " << name << std::endl;
			return NULL;
	}
}