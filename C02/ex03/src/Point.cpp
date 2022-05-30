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

std::ostream	&operator<<(std::ostream & ostream, const Point &rhs)
{
	ostream << "(" << rhs.getX() << ":" << rhs.getY() << ")";
	return (ostream);
}
