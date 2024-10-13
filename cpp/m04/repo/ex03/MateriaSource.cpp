#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0 ; i < MateriaSource::SIZE ; i++)
		this->materia[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &source) {
	for (int i = 0 ; i < MateriaSource::SIZE ; i++) {
		if (source.materia[i] != NULL)
			this->materia[i] = source.materia[i]->clone();
		else
			this->materia[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator=(MateriaSource const &source) {
	if (this != &source) {
		for (int i = 0 ; i < MateriaSource::SIZE ; i++) {
			delete this->materia[i];
			if (source.materia[i] != NULL)
				this->materia[i] = source.materia[i]->clone();
			else
				this->materia[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0 ; i < MateriaSource::SIZE ; i++)
		delete this->materia[i];
}

void MateriaSource::learnMateria(AMateria *materia) {
	if (materia == NULL) {
#ifdef DEBUG
		std::cout << "DEBUG: MateriaSource has nothing to learn" << std::endl;
#endif
		return ;
	}
	for (int i = 0 ; i < MateriaSource::SIZE ; i++)
		if (this->materia[i] == NULL) {
			this->materia[i] = materia;
#ifdef DEBUG
			std::cout << "DEBUG: MateriaSource learned " << materia->getType() << " in slot " << i << std::endl;
#endif
			return;
		}
#ifdef DEBUG
	std::cout << "DEBUG: MateriaSource cannot learn " << materia->getType() << "; its memory is full" << std::endl;
#endif
	delete materia;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
	for (int i = 0 ; i < MateriaSource::SIZE ; i++)
		if (this->materia[i] != NULL && this->materia[i]->getType() == type)
			return (this->materia[i]->clone());
#ifdef DEBUG
	std::cout << "DEBUG: MateriaSource does not know " << type << std::endl;
#endif
	return NULL;
}
