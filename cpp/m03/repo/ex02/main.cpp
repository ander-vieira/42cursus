#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	ClapTrap clapTrap("Alpha");
	ScavTrap scavTrap("Beta");
	FragTrap fragTrap("Gamma");

	clapTrap.attack("Z");
	scavTrap.attack("Z");
	fragTrap.attack("Z");

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

	fragTrap.showStatus();
	fragTrap.takeDamage(8);
	fragTrap.showStatus();
	fragTrap.beRepaired(5);
	fragTrap.showStatus();

	fragTrap.highFivesGuys();

	return 0;
}