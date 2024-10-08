#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	const Animal *animal = new Animal(), *dog = new Dog(), *cat = new Cat();

	std::cout << "Type of Animal: " << animal->getType() << std::endl;
	std::cout << "Type of Dog: " << dog->getType() << std::endl;
	std::cout << "Type of Cat: " << cat->getType() << std::endl;

	animal->makeSound();
	dog->makeSound();
	cat->makeSound();

	delete cat;
	delete dog;
	delete animal;

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