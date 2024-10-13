#ifndef CHARACTER_H
# define CHARACTER_H

# include <iostream>

# include "ICharacter.hpp"

class Character : public ICharacter {
	public:
		Character();
		Character(std::string const name);
		Character(Character const &character);
		Character &operator=(Character const &character);
		~Character();
		std::string const &getName() const;
		void equip(AMateria *materia);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
	private:
		static int const SIZE = 4;
		std::string name;
		AMateria *materia[Character::SIZE];
};

#endif