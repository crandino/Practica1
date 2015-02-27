#include "Point2d.h"

Point2d Point2d::operator+ (const Point2d &p) const
{
	Point2d tmp;
	tmp.x = x + p.x;
	tmp.y = y + p.y;
	return tmp;
}

Point2d Point2d::operator- (const Point2d &p) const
{
	Point2d tmp;
	tmp.x = x - p.x;
	tmp.y = y - p.y;
	return tmp;
}

const Point2d& Point2d::operator+= (const Point2d &p)
{
	x += p.x;
	y += p.y;
	return (*this);
}

const Point2d& Point2d::operator-= (const Point2d &p)
{
	x -= p.x;
	y -= p.y;
	return (*this);
}