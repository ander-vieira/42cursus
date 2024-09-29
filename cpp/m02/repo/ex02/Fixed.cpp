#include <cmath>

#include "Fixed.hpp"

Fixed::Fixed() {
	this->value = 0;
}

Fixed::Fixed(const Fixed &fixed) {
	*this = fixed;
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

bool Fixed::operator>(const Fixed &fixed) {
	return this->value > fixed.value;
}

bool Fixed::operator<(const Fixed &fixed) {
	return this->value < fixed.value;
}

bool Fixed::operator>=(const Fixed &fixed) {
	return this->value >= fixed.value;
}

bool Fixed::operator<=(const Fixed &fixed) {
	return this->value <= fixed.value;
}

bool Fixed::operator==(const Fixed &fixed) {
	return this->value == fixed.value;
}

bool Fixed::operator!=(const Fixed &fixed) {
	return this->value != fixed.value;
}

Fixed Fixed::operator+(const Fixed &fixed) {
	Fixed f;
	f.setRawBits(this->value+fixed.value);
	return f;
}

Fixed Fixed::operator-(const Fixed &fixed) {
	Fixed f;
	f.setRawBits(this->value-fixed.value);
	return f;
}

Fixed Fixed::operator*(const Fixed &fixed) {
	Fixed f;
	f.setRawBits((this->value*fixed.value)/Fixed::pow10());
	return f;
}

Fixed Fixed::operator/(const Fixed &fixed) {
	Fixed f;
	f.setRawBits((this->value*Fixed::pow10())/fixed.value);
	return f;
}

Fixed &Fixed::operator++() {
	this->setRawBits(this->value + 1);
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed f(*this);
	this->setRawBits(this->value + 1);
	return f;
}

Fixed &Fixed::operator--() {
	this->setRawBits(this->value - 1);
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed f(*this);
	this->setRawBits(this->value - 1);
	return f;
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2) {
	return (f1.value >= f2.value ? f1 : f2);
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2) {
	return (f1.value >= f2.value ? f1 : f2);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2) {
	return (f1.value >= f2.value ? f2 : f1);
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2) {
	return (f1.value >= f2.value ? f2 : f1);
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