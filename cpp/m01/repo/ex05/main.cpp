#include <iostream>

#include "Harl.hpp"

int main() {
	Harl harl;

	std::cout << "DEBUG COMPLAINT:" << std::endl;
	harl.complain("DEBUG");
	std::cout << "INFO COMPLAINT:" << std::endl;
	harl.complain("INFO");
	std::cout << "WARNING COMPLAINT:" << std::endl;
	harl.complain("WARNING");
	std::cout << "ERROR COMPLAINT:" << std::endl;
	harl.complain("ERROR");
	std::cout << "NO COMPLAINT:" << std::endl;
	harl.complain("NOTHING");
}