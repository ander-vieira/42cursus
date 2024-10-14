#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat default constructor called" << std::endl;
	this->brain = new Brain();
}

Cat::Cat(Cat const &cat): Animal(cat) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->brain = new Brain(*(cat.brain));
}

Cat &Cat::operator=(Cat const &cat) {
	if (this != &cat) {
		this->type = cat.type;
		delete this->brain;
		this->brain = new Brain(*(cat.brain));
	}
	return (*this);
}

Cat::~Cat() {
	delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
}