#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal default constructor called" << std::endl;
	this->type = "WrongAnimal";
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
	std::cout << "WrongAnimal destroyer called" << std::endl;
}

void WrongAnimal::makeSound() const {
	std::cout << "Distorted animal sound" << std::endl;
}

std::string WrongAnimal::getType() const {
	return this->type;
}