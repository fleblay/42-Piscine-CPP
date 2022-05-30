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

	private	:

	const Fixed	_x;
	const Fixed	_y;
};

std::ostream	&operator<<(std::ostream & ostream, const Point &rhs);

#endif
