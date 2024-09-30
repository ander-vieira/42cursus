#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap {
	public:
		FragTrap();
		FragTrap(std::string const name);
		FragTrap(FragTrap const &fragTrap);
		~FragTrap();
		void highFivesGuys();
};

#endif