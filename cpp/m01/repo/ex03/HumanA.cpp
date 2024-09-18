#include <iostream>

#include "HumanA.hpp"

HumanA::HumanA(std::string name, const Weapon &weapon) : name(name), weapon(weapon) {}

void HumanA::attack() {
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}