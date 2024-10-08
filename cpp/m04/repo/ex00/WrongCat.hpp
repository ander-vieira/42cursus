#ifndef WRONGCAT_H
# define WRONGCAT_H

# include <iostream>

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat();
		WrongCat(WrongCat const &wrongCat);
		~WrongCat();
		void makeSound() const;
};

#endif
