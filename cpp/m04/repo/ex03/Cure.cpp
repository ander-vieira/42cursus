#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(Cure const &cure) : AMateria("cure") {
	(void)cure;
}

Cure &Cure::operator=(Cure const &cure) {
	(void)cure;
	return *this;
}

Cure::~Cure() {}

AMateria *Cure::clone() const {
	return new Cure();
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
