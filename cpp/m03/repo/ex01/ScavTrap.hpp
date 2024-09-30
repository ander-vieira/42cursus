#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(std::string const name);
		ScavTrap(ScavTrap const &scavTrap);
		~ScavTrap();
		void attack(std::string const &target);
		void guardGate();
};

#endif