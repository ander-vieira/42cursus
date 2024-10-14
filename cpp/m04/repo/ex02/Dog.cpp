#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog default constructor called" << std::endl;
	this->brain = new Brain();
}

Dog::Dog(Dog const &dog): Animal(dog) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->brain = new Brain(*(dog.brain));
}

Dog &Dog::operator=(Dog const &dog) {
	if (this != &dog) {
		this->type = dog.type;
		delete this->brain;
		this->brain = new Brain(*(dog.brain));
	}
	return (*this);
}

Dog::~Dog() {
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Woof" << std::endl;
}