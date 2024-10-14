# include "Character.hpp"
# include "Cure.hpp"
# include "Ice.hpp"
# include "ICharacter.hpp"
# include "IMateriaSource.hpp"
# include "MateriaSource.hpp"

int main(void) {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	return 0;
}

// int main(void) {
// 	IMateriaSource *source = new MateriaSource();
// 	ICharacter *alpha = new Character("Alpha");

// 	source->learnMateria(new Ice());
// 	source->learnMateria(new Cure());
// 	source->learnMateria(NULL);
// 	source->learnMateria(new Ice());
// 	source->learnMateria(new Ice());
// 	source->learnMateria(new Ice());

// 	alpha->equip(source->createMateria("ice"));
// 	alpha->equip(source->createMateria("cure"));
// 	alpha->equip(source->createMateria("fire"));

// 	alpha->use(0, *alpha);
// 	alpha->use(1, *alpha);
// 	alpha->use(2, *alpha);

// 	alpha->equip(source->createMateria("ice"));
// 	alpha->equip(source->createMateria("ice"));

// 	alpha->use(2, *alpha);
// 	alpha->use(3, *alpha);
// 	alpha->use(4, *alpha);

// 	alpha->equip(source->createMateria("ice"));
// 	alpha->unequip(1);
// 	alpha->equip(source->createMateria("ice"));
// 	alpha->use(1, *alpha);

// 	delete alpha;
// 	delete source;
// }