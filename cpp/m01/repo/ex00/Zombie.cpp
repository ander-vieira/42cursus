#include <iostream>

#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
	this->name = name;
	std::cout << "DEBUG: constructing zombie " << this->name << std::endl;
}

Zombie::~Zombie() {
	std::cout << "DEBUG: destructing zombie " << this->name << std::endl;
}

void Zombie::announce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}