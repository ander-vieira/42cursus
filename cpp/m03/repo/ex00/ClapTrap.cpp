#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name(""), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string const name): name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap named constructor called with name " << name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &clapTrap): name(clapTrap.name), hitPoints(clapTrap.hitPoints), energyPoints(clapTrap.energyPoints), attackDamage(clapTrap.attackDamage) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &clapTrap) {
	this->name = clapTrap.name;
	this->hitPoints = clapTrap.hitPoints;
	this->energyPoints = clapTrap.energyPoints;
	this->attackDamage = clapTrap.attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::showStatus() const {
	std::cout << "Status of ClapTrap " << this->name << ": " << this->hitPoints << " HP, " << this->energyPoints << " EP, " << this->attackDamage << " AD" << std::endl;
}

void ClapTrap::attack(std::string const &target) {
	if (this->energyPoints == 0)
		return;
	this->energyPoints -= 1;
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	this->hitPoints -= amount;
	std::cout << "ClapTrap " << this->name << " has taken " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->energyPoints == 0)
		return;
	this->energyPoints -= 1;
	this->hitPoints += amount;
	std::cout << "ClapTrap " << this->name << " has repaired itself for " << amount << " hitpoints!" << std::endl;
}
