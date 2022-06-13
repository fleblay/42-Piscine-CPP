#ifndef ARRAY_CLASS_H
# define ARRAY_CLASS_H

#include <stdexcept>
#include <iostream>

template<typename T>
class Array
{
	public	:

	Array<T>(void);
	Array<T>(const unsigned int n);
	Array<T>(const Array<T>	&src);
	~Array<T>(void);

	Array<T>	&operator=(const Array<T> &rhs);
	T			&operator[](const unsigned int index) const;

	const unsigned int	&size(void) const;

	class OutOfRangeIndex : public std::exception
	{
		virtual const char *what(void) const throw();

	};

	private	:

	T				*_start;
	unsigned int	_size;
};

template<typename T>
std::ostream	&operator<<(std::ostream &o, const Array<T> &tab);

#include "Array.tpp"
#endif
