#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ClapTrap clapTrap("Alpha");
	ScavTrap scavTrap("Beta");

	clapTrap.attack("Z");
	scavTrap.attack("Z");

	clapTrap.showStatus();
	clapTrap.takeDamage(6);
	clapTrap.showStatus();
	clapTrap.beRepaired(3);
	clapTrap.showStatus();

	scavTrap.showStatus();
	scavTrap.takeDamage(8);
	scavTrap.showStatus();
	scavTrap.beRepaired(5);
	scavTrap.showStatus();

	scavTrap.guardGate();

	return 0;
}