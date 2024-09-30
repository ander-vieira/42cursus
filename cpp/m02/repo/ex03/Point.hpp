#ifndef POINT_H
# define POINT_H

# include "Fixed.hpp"

class Point {
	public:
		Point();
		Point(float x, float y);
		Point(Point const &point);
		Point &operator=(Point const &point);
		~Point();
		Fixed getX() const;
		Fixed getY() const;
		Point operator-(Point const &point) const;
		Fixed operator*(Point const &point) const;
		Point normal();
		static bool areParallel(Point const &p1, Point const &p2);
	private:
		Fixed const x;
		Fixed const y;
		Point(Fixed x, Fixed y);
};

std::ostream& operator<<(std::ostream& os, Point const &point);

#endif