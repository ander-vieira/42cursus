#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(std::string const name): ClapTrap(name) {
	std::cout << "ScavTrap named constructor called with name " << name << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const &scavTrap): ClapTrap(scavTrap) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(std::string const &target) {
	if (this->hitPoints == 0 || this->energyPoints == 0)
		return;
	this->energyPoints -= 1;
	std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->name << " is in Gatekeeper Mode!" << std::endl;
}