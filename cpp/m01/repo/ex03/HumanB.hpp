#ifndef HUMAN_B_H
# define HUMAN_B_H

# include <string>

# include "Weapon.hpp"

class HumanB {
	public:
		HumanB(std::string name);
		void setWeapon(Weapon *weapon);
		void attack();
	private:
		std::string name;
		Weapon *weapon;
};

#endif