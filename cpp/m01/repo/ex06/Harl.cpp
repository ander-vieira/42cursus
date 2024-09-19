#include <iostream>

#include "Harl.hpp"

void Harl::complain(std::string level) {
	static std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	static void (Harl::*funs[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for(size_t i = 0 ; i < levels->length() ; i++)
		if(levels[i] == level)
			(this->*(funs[i]))();
}

void Harl::debug() {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info() {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning() {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error() {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}