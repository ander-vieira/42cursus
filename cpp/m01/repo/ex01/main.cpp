#include <iostream>

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main() {
	Zombie *zombies;

	zombies = zombieHorde(5, "Carlos");
	std::cout << "Announcing the horde" << std::endl;
	for(int i = 0 ; i < 5 ; i++)
		zombies[i].announce();
	std::cout << "Destroying the horde" << std::endl;
	delete[] zombies;
}