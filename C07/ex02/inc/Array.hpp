#ifndef ARRAY_CLASS_H
# define ARRAY_CLASS_H

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

	private	:

	T	*_start;
};

#include "Array.tpp"
#endif
