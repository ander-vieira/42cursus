#include "Zombie.hpp"
#include <iostream>

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int main()
{
	Zombie *zombie;

	zombie = newZombie("Jose");
	std::cout << "Now announcing Jose" << std::endl;
	zombie->announce();

	std::cout << "Now announcing and destroying Carlos" << std::endl;
	randomChump("Carlos");

	std::cout << "Now destroying Jose" << std::endl;
	delete zombie;
}