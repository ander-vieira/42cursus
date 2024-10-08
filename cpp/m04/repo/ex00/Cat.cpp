#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(Cat const &cat): Animal(cat) {
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat destroyer called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
}