#include <iostream>

#include "Harl.hpp"

int main(int argc, char **argv) {
	Harl				harl;
	std::string 		level;
	static std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	size_t				levelNum;

	if (argc != 2)
	{
		std::cout << "WRONG SYNTAX" << std::endl;
		return 1;
	}

	level = (std::string)argv[1];
	for (levelNum = 0 ; levelNum < levels->length() ; levelNum++)
		if (levels[levelNum] == level)
			break;
	switch (levelNum) {
		case 0:
			harl.complain("DEBUG");
			__attribute__((fallthrough));
		case 1:
			harl.complain("INFO");
			__attribute__((fallthrough));
		case 2:
			harl.complain("WARNING");
			__attribute__((fallthrough));
		case 3:
			harl.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}