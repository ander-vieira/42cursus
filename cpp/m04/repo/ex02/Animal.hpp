#ifndef ANIMAL_H
# define ANIMAL_H

# include <iostream>

class Animal {
	public:
		Animal();
		Animal(std::string const &type);
		Animal(Animal const &animal);
		Animal &operator=(Animal const &animal);
		virtual ~Animal();
		virtual void makeSound() const = 0;
		std::string const &getType() const;
	protected:
		std::string type;
};

#endif
