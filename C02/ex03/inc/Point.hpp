#ifndef POINT_CLASS_H
# define POINT_CLASS_H

#include <iostream>
#include "Fixed.hpp"

class Point{

	public	:

	Point(void);
	Point(const Point &src);
	Point(const float x, const float y);
	~Point(void);

	const Fixed	&getX(void) const;
	const Fixed	&getY(void) const;

	Point	&operator=(const Point &rhs);
	bool	operator==(const Point &rhs) const;

	bool			isAligned(const Point &a, const Point &b) const;
	static float	area(const Point &a, const Point &b, const Point &c);
	static bool		bsp(Point const a, Point const b, Point const c, Point const point);

	private	:

	const Fixed	_x;
	const Fixed	_y;
};

std::ostream	&operator<<(std::ostream & ostream, const Point &rhs);

#endif
