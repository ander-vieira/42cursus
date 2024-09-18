#include <iostream>

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name) {
	this->weapon = NULL;
}

void HumanB::setWeapon(Weapon *weapon) {
	this->weapon = weapon;
}

void HumanB::attack() {
	if (this->weapon == NULL)
		std::cout << this->name << " attacks without a weapon" << std::endl;
	else
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}