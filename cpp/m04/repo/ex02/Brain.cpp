#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0 ; i < Brain::SIZE ; i++)
		this->ideas[i] = "";
}

Brain::Brain(Brain const &brain) {
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0 ; i < Brain::SIZE ; i++)
		this->ideas[i] = brain.ideas[i];
}

Brain &Brain::operator=(Brain const &brain) {
	if (this != &brain) {
		for (int i = 0 ; i < Brain::SIZE ; i++)
			this->ideas[i] = brain.ideas[i];
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}
