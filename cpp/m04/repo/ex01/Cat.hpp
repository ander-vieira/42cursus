#ifndef CAT_H
# define CAT_H

# include <iostream>

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
	public:
		Cat();
		Cat(Cat const &cat);
		Cat &operator=(Cat const &cat);
		~Cat();
		void makeSound() const;
	private:
		Brain *brain;
};

#endif
