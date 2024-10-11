#include "Point.hpp"

static bool isTriangle(Point const a, Point const b, Point const c) {
	Point const ab(b - a), ac(c - a);

	return !Point::areParallel(ab, ac);
}

static bool pointsSameSide(Point const a, Point const b, Point const c, Point const p) {
	Point const abN((b - a).normal()), ac(c - a), ap(p - a);
	Fixed cSide = abN*ac, pSide = abN*ap;

	return (cSide > 0 && pSide > 0) || (cSide < 0 && pSide < 0);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	return isTriangle(a, b, c) && pointsSameSide(a, b, c, point) && pointsSameSide(b, c, a, point) && pointsSameSide(c, a, b, point);
}