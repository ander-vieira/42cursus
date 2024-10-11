#ifndef DOG_H
# define DOG_H

# include <iostream>

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
	public:
		Dog();
		Dog(Dog const &dog);
		Dog &operator=(Dog const &dog);
		~Dog();
		void makeSound()const ;
	private:
		Brain *brain;
};

#endif
