#include "Point.hpp"
#include <iostream>

Point::Point(void) : _x(0), _y(0)
{
	//std::cout << "Default Constructor Called" << std::endl;
	return ;
}

Point::Point(const Point &src)
{
	//std::cout << "Copy Constructor Called" << std::endl;
	*this = src;
	return ;
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
	//std::cout << "Parameter Constructor Called" << std::endl;
	return ;
}

Point::~Point(void)
{
	//std::cout << "Default Destructor Called" << std::endl;
	return ;
}

const Fixed	&Point::getX(void) const
{
	return (this->_x);
}

const Fixed	&Point::getY(void) const
{
	return (this->_y);
}

Point	&Point::operator=(const Point &rhs)
{
	//std::cout << "Assignation operator overload called" << std::endl;
	Fixed	&x = (Fixed &)this->_x;
	Fixed	&y = (Fixed &)this->_y;

	x = rhs.getX();
	y = rhs.getY();
	return (*this);
}

bool	Point::operator==(const Point &rhs) const
{
	if (this->_x == rhs.getX() && this->_y == rhs.getY())
		return (true);
	return (false);
}

bool	Point::isAligned(const Point &a, const Point &b) const
{
	float	det;

	det = (b.getX().toFloat() - a.getX().toFloat()) * (this->_y.toFloat() - a.getY().toFloat())
		- (b.getY().toFloat() - a.getY().toFloat()) * (this->_x.toFloat() - a.getX().toFloat());

	return (det == 0);
}

float	Point::area(const Point &a, const Point &b, const Point &c)
{
	float	area;

	area = ((b.getX().toFloat() - a.getX().toFloat()) * (c.getY().toFloat() - a.getY().toFloat())
		- (c.getX().toFloat() - a.getX().toFloat()) * (b.getY().toFloat() - a.getY().toFloat())) / 2;

	return (area < 0 ? -area : area);
}

std::ostream	&operator<<(std::ostream & ostream, const Point &rhs)
{
	ostream << "(" << rhs.getX() << ":" << rhs.getY() << ")";
	return (ostream);
}
