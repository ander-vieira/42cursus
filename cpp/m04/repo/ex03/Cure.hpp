#ifndef CURE_H
# define CURE_H

#include <iostream>

#include "AMateria.hpp"

class Cure : public AMateria {
	public:
		Cure();
		Cure(Cure const &cure);
		Cure &operator=(Cure const &cure);
		~Cure();
		AMateria *clone() const;
		void use(ICharacter &target);
};

#endif