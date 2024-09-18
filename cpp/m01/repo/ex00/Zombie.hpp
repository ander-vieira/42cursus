#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>

class Zombie {
	public:
		Zombie(std::string name);
		~Zombie();
		void announce();
	private:
		std::string name;
};

#endif