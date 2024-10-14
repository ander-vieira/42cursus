#ifndef BRAIN_H
# define BRAIN_H

# include <iostream>

class Brain {
	public:
		Brain();
		Brain(Brain const &brain);
		Brain &operator=(Brain const &brain);
		~Brain();
	private:
		static int const SIZE = 100;
		std::string ideas[Brain::SIZE];
};

#endif