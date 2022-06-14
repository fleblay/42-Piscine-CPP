#ifndef SPAN_CLASS_H
# define SPAN_CLASS_H

#include <iostream>
#include <vector>
#include <stdexcept>

class Span
{
	public	:

	Span(void);
	Span(const unsigned int &n);
	Span(const Span &src);
	~Span(void);

	Span	&operator=(const Span &rhs);

	void			addNumber(const int &number);
	unsigned int	shortestSpan(void) const;	
	unsigned int	longestSpan(void) const;	

	private	:
	
	std::vector<int>	_value;
	unsigned int		_size;

};

std::ostream	&operator<<(std::ostream &o, const Span &rhs);

#endif
