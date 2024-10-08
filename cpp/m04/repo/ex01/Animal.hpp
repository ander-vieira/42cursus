#ifndef ANIMAL_H
# define ANIMAL_H

# include <iostream>

class Animal {
	public:
		Animal();
		Animal(Animal const &animal);
		Animal &operator=(Animal const &animal);
		virtual ~Animal();
		virtual void makeSound() const;
		std::string getType() const;
	protected:
		std::string type;
};

#endif
