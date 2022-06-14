#include "Span.hpp"
#include <iostream>

Span::Span(void) : _size(0)
{
	std::cout << "Default span constructor called" << std::endl;
	return ;
}

Span::Span(const unsigned int &n) : _size(n)
{
	std::cout << "Parametric span constructor called with :" << _size << std::endl;
	return ;
}

Span::Span(const Span &src)
{
	if (this == &src)
		return ;
	*this = src;
}

Span::~Span(void)
{
	std::cout << "Default span destructor called" << std::endl;
	return ;
}

Span	&Span::operator=(const Span &rhs)
{
	std::cout << "Span assign operator overload called" << std::endl;
	this->_size = rhs._size;
	this->_value.assign(rhs._value.begin(), rhs._value.end());
	return (*this);
}

void	Span::addNumber(const int &number)
{
	if (this->_value.size() == _size)
		throw(std::runtime_error("Maximum Span capacity reached!"));
	this->_value.push_back(number);
	this->_size++;
}

unsigned int	Span::shortestSpan(void) const
{
	if (this->_value.size() <= 1)
		throw(std::runtime_error("Not enough members to perform shortest span!"));
	
}
