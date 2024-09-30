#include <iostream>

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
	//Should be in the triangle:
	// Point a(0.f, 0.f), b(1.f, 0.f), c(0.f, 1.f), p(0.6f, 0.2f);
	//Should NOT be in the triangle:
	// Point a(0.f, 0.f), b(1.f, 0.f), c(0.f, 1.f), p(0.6f, 0.6f);
	//Should NOT be in the triangle (because it's not a triangle):
	// Point a(0.f, 0.f), b(1.f, 0.f), c(2.f, 0.f), p(0.8f, 0.f);
	//Should be in the triangle
	Point a(-1.f, 3.f), b(2.f, 1.f), c(0.f, -3.f), p(0.f, 0.f);

	std::cout << "Point A = " << a << std::endl;
	std::cout << "Point B = " << b << std::endl;
	std::cout << "Point C = " << c << std::endl;
	std::cout << "Point P = " << p << std::endl;

	if (bsp(a, b, c, p))
		std::cout << "Point P is in the ABC triangle" << std::endl;
	else
		std::cout << "Point P is NOT in the ABC triangle" << std::endl;

	return 0;
}