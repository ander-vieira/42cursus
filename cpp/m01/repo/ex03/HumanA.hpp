#ifndef HUMAN_A_H
# define HUMAN_A_H

# include <string>

# include "Weapon.hpp"

class HumanA {
	public:
		HumanA(std::string name, Weapon const &weapon);
		void attack();
	private:
		std::string name;
		Weapon const &weapon;
};

#endif