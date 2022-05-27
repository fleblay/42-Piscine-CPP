#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void) : _value(0)
{
	//std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed &src)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::Fixed(const int value) : _value(value)
{
	//std::cout << "Int constructor called" << std::endl;
	this->_value <<= this->_decimals;
	return ;
}

Fixed::Fixed(const float value)
{
	//std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (1 << this->_decimals));
	return ;
}

Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
	return ;
}

int	Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
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
	//std::cout << "Copy assignement operator called" << std::endl;
	this->_value = rhs.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(const Fixed &rhs) const
{
	//std::cout << "Plus operator called" << std::endl;
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &rhs) const
{
	//std::cout << "Minus operator called" << std::endl;
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &rhs) const
{
	//std::cout << "Multiply operator called" << std::endl;
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
	//std::cout << "Divide operator called" << std::endl;
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

bool	Fixed::operator>(const Fixed &rhs) const
{
	//std::cout << "gt operator called" << std::endl;
	return (this->_value > rhs.getRawBits());
}

bool	Fixed::operator<(const Fixed &rhs) const
{
	//std::cout << "lt operator called" << std::endl;
	return (this->_value < rhs.getRawBits());
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
	//std::cout << "ge operator called" << std::endl;
	return (this->_value >= rhs.getRawBits());
}

bool	Fixed::operator<=(const Fixed &rhs) const
{
	//std::cout << "le operator called" << std::endl;
	return (this->_value <= rhs.getRawBits());
}

bool	Fixed::operator==(const Fixed &rhs) const
{
	//std::cout << "eq operator called" << std::endl;
	return (this->_value == rhs.getRawBits());
}

bool	Fixed::operator!=(const Fixed &rhs) const
{
	//std::cout << "ne operator called" << std::endl;
	return (this->_value != rhs.getRawBits());
}

Fixed &	Fixed::operator++(void)
{
	//std::cout << "pre-increment operator called" << std::endl;
	this->_value += 1;
	return (*this);
}

Fixed &	Fixed::operator--(void)
{
	//std::cout << "pre-decrement operator called" << std::endl;
	this->_value -= 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	//std::cout << "post-increment operator called" << std::endl;
	Fixed	tmp(*this);
	this->operator++();
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	//std::cout << "post-decrement operator called" << std::endl;
	Fixed	tmp(*this);
	this->operator--();
	return (tmp);
}

Fixed &	Fixed::min(Fixed &lhs, Fixed &rhs)
{
	//std::cout << "min class fx called" << std::endl;
	return (lhs < rhs ? lhs : rhs);
}

const Fixed	&	Fixed::min(const Fixed &lhs, const Fixed &rhs)
{
	//std::cout << "const min class fx called" << std::endl;
	return (lhs < rhs ? lhs : rhs);
}

Fixed &	Fixed::max(Fixed &lhs, Fixed &rhs)
{
	//std::cout << "max class fx called" << std::endl;
	return (lhs > rhs ? lhs : rhs);
}

const Fixed	&	Fixed::max(const Fixed &lhs, const Fixed &rhs)
{
	//std::cout << "const max class fx called" << std::endl;
	return (lhs > rhs ? lhs : rhs);
}

const int	Fixed::_decimals = 8;

std::ostream & operator<<(std::ostream &stream, const Fixed &rhs)
{
	//std::cout << "ostream overload for Fixed called" << std::endl;
	stream << rhs.toFloat();
	return stream;
}
