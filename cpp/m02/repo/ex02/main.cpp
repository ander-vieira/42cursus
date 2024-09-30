#include <iostream>

#include "Fixed.hpp"

// int main()
// {
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;

// 	std::cout << b << std::endl;

// 	std::cout << Fixed::max( a, b ) << std::endl;

// 	return 0;
// }

int main()
{
	Fixed a(3.5f);
	Fixed b(42.1f);
	Fixed c(71);

	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "b - a = " << b - a << std::endl;
	std::cout << "b * c / a = " << b * c / a << std::endl;

	if (a < b)
		std::cout << "a is greater than b" << std::endl;
	else
		std::cout << "a is not greater than b" << std::endl;

	if (b != c)
		std::cout << "b is not equal to c" << std::endl;
	else
		std::cout << "b is equal to c" << std::endl;
	
	std::cout << "The maximum of b and c is " << Fixed::max(b, c) << std::endl;
	std::cout << "The minimum of b and c is " << Fixed::min(b, c) << std::endl;

	std::cout << "a as integer is " << a.toInt() << std::endl;
	std::cout << "c as integer is " << c.toInt() << std::endl;
}