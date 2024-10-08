#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

# include <iostream>

class WrongAnimal {
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const &wrongAnimal);
		WrongAnimal &operator=(WrongAnimal const &wrongAnimal);
		~WrongAnimal();
		void makeSound() const;
		std::string getType() const;
	protected:
		std::string type;
};

#endif
