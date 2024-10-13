#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

# include <iostream>

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	public:
		MateriaSource();
		MateriaSource(MateriaSource const &source);
		MateriaSource &operator=(MateriaSource const &source);
		~MateriaSource();
		void learnMateria(AMateria *materia);
		AMateria *createMateria(std::string const &type);
	private:
		static int const SIZE = 4;
		AMateria *materia[SIZE];
};

#endif