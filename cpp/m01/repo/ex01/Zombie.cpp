#include <iostream>

#include "Zombie.hpp"

Zombie::~Zombie()
{
	std::cout << this->name << " has returned to its grave..." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}

void Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}