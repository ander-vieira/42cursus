#include <iostream>

#include "Fixed.hpp"

int main()
{
	Fixed fixed1, fixed2;

	std::cout << "A: " << fixed1.getRawBits() << ", B: " << fixed2.getRawBits() << std::endl;
	fixed1.setRawBits(5);
	std::cout << "A: " << fixed1.getRawBits() << ", B: " << fixed2.getRawBits() << std::endl;
	fixed2 = fixed1;
	std::cout << "A: " << fixed1.getRawBits() << ", B: " << fixed2.getRawBits() << std::endl;

	Fixed fixed3(fixed1);
	std::cout << "A: " << fixed1.getRawBits() << ", B: " << fixed2.getRawBits() << ", C: " << fixed3.getRawBits() << std::endl;
	fixed1.setRawBits(6);
	std::cout << "A: " << fixed1.getRawBits() << ", B: " << fixed2.getRawBits() << ", C: " << fixed3.getRawBits() << std::endl;
}