#ifndef __Point2d_H__
#define __Point2d_H__

class Point2d {

public:
	float x, y;

	// Point2d() {};
	// virtual ~Point2d() {};

	Point2d operator+ (const Point2d &p) const;
	Point2d operator- (const Point2d &p) const;
	const Point2d& operator+= (const Point2d &p);
	const Point2d& operator-= (const Point2d &p);
	
};








#endif // !__Point2d_H__
