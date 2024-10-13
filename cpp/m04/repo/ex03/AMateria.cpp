#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : type(type) {}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const {
	return this->type;
}

AMateria::AMateria() : type("") {}

AMateria::AMateria(AMateria const &materia) : type(materia.type) {}

AMateria &AMateria::operator=(AMateria const &materia) {
	(void)materia;
	return *this;
}
