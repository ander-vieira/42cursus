#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(Brain const &brain) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = brain;
}

Brain &Brain::operator=(Brain const &brain) {
	if (this != &brain)
		for (int i = 0 ; i < BRAIN_IDEAS ; i++)
			this->ideas[i] = brain.ideas[i];
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}
