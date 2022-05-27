#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::Fixed(const int value) : _value(value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value <<= this->_decimals;
	return ;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (1 << this->_decimals));
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
	return ;
}

float	Fixed::toFloat(void) const
{
	float	to_return = 0;

	to_return = (float)this->_value / (1 << this->_decimals);
	return (to_return);
}

int		Fixed::toInt(void) const
{
	return (this->_value >> this->_decimals);
}

Fixed &	Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignement operator called" << std::endl;
	this->_value = rhs.getRawBits();
	return (*this);
}

const int	Fixed::_decimals = 8;

std::ostream & operator<<(std::ostream &stream, const Fixed &rhs)
{
	stream << rhs.toFloat();
	return stream;
}
