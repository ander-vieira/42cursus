#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string const &type) : type(type) {
	std::cout << "WrongAnimal parameterized constructor called with type " << type << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &wrongAnimal) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = wrongAnimal;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &wrongAnimal) {
	if (this != &wrongAnimal)
		this->type = wrongAnimal.type;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const {
	std::cout << "Distorted animal sound" << std::endl;
}

std::string const &WrongAnimal::getType() const {
	return this->type;
}