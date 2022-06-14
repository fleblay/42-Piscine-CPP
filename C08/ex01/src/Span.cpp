#include "Span.hpp"
#include <iostream>
#include <algorithm>
#include <iterator>
#include <cstdlib>

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

int	Span::getValue(const unsigned int &index) const
{
	if (index >= this->_size)
		throw(std::runtime_error("Out of bound index!"));
	return (this->_value[index]);
}

unsigned int	Span::getValueSize(void) const
{
	return (this->_value.size());
}

void	Span::addNumber(const int &number)
{
	if (this->_value.size() == _size)
		throw(std::runtime_error("Maximum Span capacity already reached!"));
	this->_value.push_back(number);
}

unsigned int	Span::shortestSpan(void) const
{
	if (this->_value.size() <= 1)
		throw(std::runtime_error("Not enough members to perform shortest span!"));

	std::vector<int>					valuecopy(this->_value);
	std::vector<int>::const_iterator	it;
	std::vector<int>::const_iterator	end;
	unsigned int						s_span;
	unsigned int						curr_diff;

	std::sort(valuecopy.begin(), valuecopy.end());
	it = valuecopy.begin();
	end = valuecopy.end();
	s_span = valuecopy[1] - valuecopy[0];

	for (++it; it != end; ++it)
	{
		curr_diff = *it - it[-1]; 
		if (curr_diff < s_span)
			s_span = curr_diff;
	}
	return (s_span);
}

unsigned int	Span::longestSpan(void) const
{
	if (this->_value.size() <= 1)
		throw(std::runtime_error("Not enough members to perform longest span!"));

	std::vector<int>	valuecopy(this->_value);

	std::sort(valuecopy.begin(), valuecopy.end());
	return (valuecopy.back() - valuecopy.front());
}

void			Span::fillSpan(std::vector<int>::iterator begin,
					std::vector<int>::iterator end)
{
	if (this->_value.size() == _size)
		throw(std::runtime_error("Maximum Span capacity already reached!"));
	if (std::distance(begin, end) == 0)
		throw(std::runtime_error("Iterator range is 0!"));
	if (static_cast<unsigned long>(std::abs(std::distance(begin, end)))
		> this->_size - this->_value.size())
		throw(std::runtime_error("Iterator range is bigger than available space!"));

	this->_value.insert(this->_value.end(), begin, end);
}

std::ostream	&operator<<(std::ostream &o, const Span &rhs)
{
	for (unsigned int i = 0; i < rhs.getValueSize(); i++)
	{
		o << "Span[" << i << "] = " << rhs.getValue(i) << std::endl;
	}
	return (o);
}
