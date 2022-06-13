#ifndef ARRAY_CLASS_T
# define ARRAY_CLASS_T

# ifndef ARRAY_CLASS_H
#  error __FILE__ should be included from the .hpp file only !
# endif

#include <cstddef>
#include <iostream>

template<typename T>
Array<T>::Array(void) : _start(NULL), _size(0)
{
	std::cout << "Default Array constructor called" << std::endl;
	return ;
}

template<typename T>
Array<T>::Array(const unsigned int n)
{
	std::cout << "Parametric Array constructor called" << std::endl;
	if (n == 0)
	{
		this->_start = NULL;
		this->_size = 0;
		return ;
	}
	this->_start = new T[n];
	this->_size = n;
	for (unsigned int i = 0; i < n; i++)
		this->_start[i] = 0;
}

template<typename T>
Array<T>::Array(const Array<T> &src) : _start(NULL), _size(0)
{
	std::cout << "Copy Array constructor called" << std::endl;
	*this = src;
}

template<typename T>
Array<T>::~Array(void)
{
	std::cout << "Default Array destructor called" << std::endl;
	delete [] this->_start;
	return ;
}

template<typename T>
Array<T>	&Array<T>::operator=(const Array<T> &rhs)
{
	std::cout << "Array assign operator overloard called" << std::endl;
	if (this == &rhs)
		return (*this);
	delete [] this->_start;
	if (rhs._size == 0)
	{
		this->_start = NULL;
		return (*this);
	}
	this->_size = rhs._size;
	this->_start = new T[rhs._size];
	for (unsigned int i = 0; i < rhs._size; i++)
		this->_start[i] = rhs._start[i];
	return (*this);
}

template<typename T>
T			&Array<T>::operator[](const unsigned int index) const
{
	//std::cout << "Array subscript operator overloard called" << std::endl;
	if (index > this->_size - 1)
		throw OutOfRangeIndex();
	return (this->_start[index]);
}

template<typename T>
const unsigned int	&Array<T>::size(void) const
{
	return (this->_size);
}

template<typename T>
const char	*Array<T>::OutOfRangeIndex::what(void) const throw()
{
	return ("Index is out of range");

}

template<typename T>
std::ostream	&operator<<(std::ostream &o, const Array<T> &tab)
{
	if (tab.size() == 0)
	{
		std::cout << "Array is empty!" << std::endl;
		return (o);
	}
	for (unsigned int i = 0; i < tab.size(); i++)
	{
		std::cout << "Array [" << i << "] : " << tab[i] << std::endl;
	}
	return (o);
}

#endif
