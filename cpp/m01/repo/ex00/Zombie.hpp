#include <string>

#ifndef ZOMBIE_H
# define ZOMBIE_H

class Zombie {
	public:
		Zombie(std::string name);
		~Zombie();
		void announce();
	private:
		std::string name;
};

#endif