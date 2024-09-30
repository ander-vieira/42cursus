#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>

class ClapTrap {
	public:
		ClapTrap();
		ClapTrap(std::string const name);
		ClapTrap(ClapTrap const &clapTrap);
		ClapTrap &operator=(ClapTrap const &clapTrap);
		~ClapTrap();
		void showStatus() const;
		void attack(std::string const &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
	protected:
		std::string name;
		int hitPoints;
		int energyPoints;
		int attackDamage;
};

#endif