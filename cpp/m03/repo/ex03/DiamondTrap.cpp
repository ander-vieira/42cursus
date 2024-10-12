#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {
	std::cout << "DiamondTrap default constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 30;
}

DiamondTrap::DiamondTrap(std::string const name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
	std::cout << "DiamondTrap named constructor called with name " << name << std::endl;
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 30;
}

DiamondTrap::DiamondTrap(DiamondTrap const &diamondTrap): ClapTrap(diamondTrap), ScavTrap(diamondTrap), FragTrap(diamondTrap) {
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap " << this->name << " is " << this->ClapTrap::name << "!" << std::endl;
}