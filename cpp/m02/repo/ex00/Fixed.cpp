#include "Fixed.hpp"

Fixed::Fixed() {
	this->value = 0;
}

Fixed::Fixed(const Fixed &fixed) {
	this->value = fixed.value;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
	this->value = fixed.value;
	return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits() {
	return this->value;
}

void Fixed::setRawBits(int const raw) {
	this->value = raw;
}
