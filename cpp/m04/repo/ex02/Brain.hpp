#ifndef BRAIN_H
# define BRAIN_H

# include <iostream>

# define BRAIN_IDEAS 100

class Brain {
	public:
		Brain();
		Brain(Brain const &brain);
		Brain &operator=(Brain const &brain);
		~Brain();
	private:
		std::string ideas[BRAIN_IDEAS];
};

#endif