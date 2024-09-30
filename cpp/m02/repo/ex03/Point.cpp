#include "Point.hpp"

//Public methods

Point::Point(): x(0), y(0) {}

Point::Point(float x, float y): x(Fixed(x)), y(Fixed(y)) {}

Point::Point(Point const &point): x(point.x), y(point.y) {}

Point &Point::operator=(Point const &point) {
	(void)point;
	return (*this);
}

Point::~Point() {}

Fixed Point::getX() const {
	return this->x;
}

Fixed Point::getY() const {
	return this->y;
}

Point Point::operator-(Point const &point) const {
	return Point(this->x - point.x, this->y - point.y);
}

Fixed Point::operator*(Point const &point) const {
	return (this->x*point.x + this->y*point.y);
}

Point Point::normal() {
	return Point(this->y, -this->x);
}

bool Point::areParallel(Point const &p1, Point const &p2) {
	return p1.x*p2.y == p2.x*p1.y;
}

//Private methods

Point::Point(Fixed x, Fixed y): x(x), y(y) {}

//Non-method functions

std::ostream& operator<<(std::ostream& os, Point const &point) {
	os << "(" << point.getX() << "," << point.getY() << ")";
	return os;
}