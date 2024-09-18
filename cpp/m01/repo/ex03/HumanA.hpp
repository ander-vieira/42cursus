#ifndef HUMAN_A_H
# define HUMAN_A_H

# include <string>

# include "Weapon.hpp"

class HumanA {
	public:
		HumanA(std::string name, const Weapon &weapon);
		void attack();
	private:
		std::string name;
		const Weapon &weapon;
};

#endif