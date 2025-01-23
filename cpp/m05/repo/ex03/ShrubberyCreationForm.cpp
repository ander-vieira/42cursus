#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("SCF", 145, 137), target(target) {
	std::cout << "ShrubberyCreationForm: created with target " << this->target << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm: killed with target " << this->target << std::endl;
}

std::string const &ShrubberyCreationForm::getTarget() const {
	return this->target;
}

void ShrubberyCreationForm::doThing() const {
	std::ofstream file((this->target + "_shrubbery").c_str());

	file << "ASCII trees" << std::endl;
	std::cout << "ShrubberyCreationForm: added shrubbery to target " << this->target << std::endl;
}