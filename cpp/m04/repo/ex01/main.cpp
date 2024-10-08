#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define ANIMAL_NUM 8

int main() {
	const Animal *animals[ANIMAL_NUM];

	std::cout << "----- TESTING ARRAY OF ANIMALS -----" << std::endl;

	for (int i = 0 ; i < ANIMAL_NUM ; i++) {
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for (int i = 0 ; i < ANIMAL_NUM ; i++) {
		animals[i]->makeSound();
		delete animals[i];
	}

	std::cout << "----- TESTING DEEP COPIES -----" << std::endl;

	Cat *cat1 = new Cat(), *cat2 = new Cat(*cat1);

	delete cat2;
	delete cat1;

	return 0;
}

// int main() {
// 	const WrongAnimal *wrongAnimal = new WrongAnimal(), *wrongCat = new WrongCat();

// 	std::cout << "Type of WrongAnimal: " << wrongAnimal->getType() << std::endl;
// 	std::cout << "Type of WrongCat: " << wrongCat->getType() << std::endl;

// 	wrongAnimal->makeSound();
// 	wrongCat->makeSound();

// 	delete wrongCat;
// 	delete wrongAnimal;

// 	return 0;
// }