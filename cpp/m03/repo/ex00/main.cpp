#include "ClapTrap.hpp"

int main() {
	ClapTrap clapTrap1("Alpha"), clapTrap2("Beta");

	clapTrap1.showStatus();
	clapTrap1.attack("1");
	clapTrap1.attack("2");
	clapTrap1.attack("3");
	clapTrap1.attack("4");
	clapTrap1.attack("5");
	clapTrap1.attack("6");
	clapTrap1.attack("7");
	clapTrap1.attack("8");
	clapTrap1.attack("9");
	clapTrap1.attack("10");
	clapTrap1.attack("11");
	clapTrap1.showStatus();

	clapTrap2.attack("Alpha");

	clapTrap2.showStatus();
	clapTrap2.takeDamage(6);
	clapTrap2.showStatus();
	clapTrap2.beRepaired(2);
	clapTrap2.showStatus();

	return 0;
}