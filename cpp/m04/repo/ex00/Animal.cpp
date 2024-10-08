#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal default constructor called" << std::endl;
	this->type = "Animal";
}

Animal::Animal(Animal const &animal) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = animal;
}

Animal &Animal::operator=(Animal const &animal) {
	if (this != &animal)
		this->type = animal.type;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destroyer called" << std::endl;
}

void Animal::makeSound() const {
	std::cout << "Generic animal sound" << std::endl;
}

std::string Animal::getType() const {
	return this->type;
}