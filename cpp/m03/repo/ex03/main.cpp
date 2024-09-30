#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
	DiamondTrap diamondTrap("Delta");
	
	diamondTrap.showStatus();

	diamondTrap.attack("Z");
	diamondTrap.takeDamage(3);
	diamondTrap.beRepaired(2);
	diamondTrap.guardGate();
	diamondTrap.highFivesGuys();
	diamondTrap.whoAmI();

	return 0;
}