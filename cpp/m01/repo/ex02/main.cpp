#include <iostream>

int main() {
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "The addresses are:" << std::endl;
	std::cout << "Variable:  " << &string << std::endl;
	std::cout << "Pointer:   " << stringPTR << std::endl;
	std::cout << "Reference: " << &stringREF << std::endl;

	std::cout << "The values are:" << std::endl;
	std::cout << "Variable:  " << string << std::endl;
	std::cout << "Pointer:   " << *stringPTR << std::endl;
	std::cout << "Reference: " << stringREF << std::endl;
}