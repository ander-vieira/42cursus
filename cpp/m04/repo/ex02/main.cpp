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

//This fails because animal is an abstract class now (because makeSound is pure virtual)
// int main() {
// 	Animal animal;

// 	animal.makeSound();

// 	return 0;
// }