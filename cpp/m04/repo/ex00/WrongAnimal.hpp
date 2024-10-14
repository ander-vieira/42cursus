#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

# include <iostream>

class WrongAnimal {
	public:
		WrongAnimal();
		WrongAnimal(std::string const &type);
		WrongAnimal(WrongAnimal const &wrongAnimal);
		WrongAnimal &operator=(WrongAnimal const &wrongAnimal);
		~WrongAnimal();
		void makeSound() const;
		std::string const &getType() const;
	protected:
		std::string type;
};

#endif
