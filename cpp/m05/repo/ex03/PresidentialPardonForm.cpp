#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PPF", 25, 5), target(target) {
	std::cout << "PresidentialPardonForm: created with target " << this->target << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm: killed with target " << this->target << std::endl;
}

std::string const &PresidentialPardonForm::getTarget() const {
	return this->target;
}

void PresidentialPardonForm::doThing() const {
	std::cout << "PresidentialPardonForm: " << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}