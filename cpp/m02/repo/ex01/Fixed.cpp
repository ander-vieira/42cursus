#include <cmath>

#include "Fixed.hpp"

Fixed::Fixed() {
	this->value = 0;
}

Fixed::Fixed(const Fixed &fixed) {
	this->value = fixed.value;
}

Fixed::Fixed(const int i)
{
	this->value = i * Fixed::pow10();
}

Fixed::Fixed(const float f)
{
	this->value = (long)roundf(f * Fixed::pow10());
}

Fixed &Fixed::operator=(const Fixed &fixed) {
	this->value = fixed.value;
	return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits() const {
	return this->value;
}

void Fixed::setRawBits(int const raw) {
	this->value = raw;
}

float Fixed::toFloat() const {
	return ((double)this->value / Fixed::pow10());
}

int Fixed::toInt() const {
	return roundf(this->toFloat());
}

int Fixed::pow10() {
	static bool init;
	static int value;

	if (!init)
	{
		value = 1;
		for (int i = 0 ; i < Fixed::point ; i++)
			value *= 10;
		init = true;
	}
	return value;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}