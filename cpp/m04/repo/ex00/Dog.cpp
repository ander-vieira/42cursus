#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(Dog const &dog) : Animal(dog) {
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Woof" << std::endl;
}