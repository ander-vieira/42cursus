#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string const &type) : type(type) {
	std::cout << "Animal parameterized constructor called with type " << type << std::endl;
}

Animal::Animal(Animal const &animal) : type(animal.type) {
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(Animal const &animal) {
	if (this != &animal) {
		this->type = animal.type;
	}
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

std::string const &Animal::getType() const {
	return this->type;
}