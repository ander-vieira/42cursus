#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(Cat const &cat) : Animal(cat) {
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
}