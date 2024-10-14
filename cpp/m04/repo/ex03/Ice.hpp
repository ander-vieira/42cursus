#ifndef ICE_H
# define ICE_H

#include <iostream>

#include "AMateria.hpp"

class Ice : public AMateria {
	public:
		Ice();
		Ice(Ice const &ice);
		Ice &operator=(Ice const &ice);
		~Ice();
		AMateria *clone() const;
		void use(ICharacter &target);
};

#endif