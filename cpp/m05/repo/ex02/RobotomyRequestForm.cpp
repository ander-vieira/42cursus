#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RRF", 72, 45), target(target) {
	std::cout << "RobotomyRequestForm: created with target " << this->target << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm: killed with target " << this->target << std::endl;
}

std::string const &RobotomyRequestForm::getTarget() const {
	return this->target;
}

void RobotomyRequestForm::doThing() const {
	std::cout << "RobotomyRequestForm: *drilling noises*" << std::endl;

	srand(time(NULL));
	if (rand() % 2 == 0)
		std::cout << "RobotomyRequestForm: successfully robotomized target " << this->target << std::endl;
	else
		std::cout << "RobotomyRequestForm: could not robotomize target " << this->target << std::endl;
}