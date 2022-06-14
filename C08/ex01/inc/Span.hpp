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

	int						getValue(const unsigned int &index) const;
	unsigned int			getValueSize(void) const;
	void					addNumber(const int &number);
	unsigned int			shortestSpan(void) const;	
	unsigned int			longestSpan(void) const;	
	void					fillSpan(std::vector<int>::iterator begin,
								std::vector<int>::iterator end);

	private	:
	
	std::vector<int>	_value;
	unsigned int		_size;

};

std::ostream	&operator<<(std::ostream &o, const Span &rhs);

#endif
