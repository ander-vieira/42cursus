#include "Zombie.hpp"
#include <iostream>

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int main() {
	Zombie *zombie;

	std::cout << "main: calling newZombie(\"Jose\")" << std::endl;
	zombie = newZombie("Jose");
	std::cout << "main: returned from newZombie(\"Jose\")" << std::endl;

	std::cout << "main: announcing Jose" << std::endl;
	zombie->announce();
	std::cout << "main: finished announcing Jose" << std::endl;

	std::cout << "main: calling randomChump(\"Carlos\")" << std::endl;
	randomChump("Carlos");
	std::cout << "main: returned from randomChump(\"Carlos\")" << std::endl;

	delete zombie;
}