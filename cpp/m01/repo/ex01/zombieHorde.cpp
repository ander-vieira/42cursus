#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *zombies;

	zombies = new Zombie[N]();
	for (int i = 0 ; i < N ; i++)
		zombies[i].setName(name);
	return zombies;
}