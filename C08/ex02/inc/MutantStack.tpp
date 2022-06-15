#ifndef MUTANTSTACK_T
# define MUTANTSTACK_T

# ifndef MUTANTSTACK_H
# error __FILE__ should only be included via MutanStack.hpp
#  endif

#include <iostream>

//Constructor & Destructor
template <typename T>
MutantStack<T>::MutantStack(void)
{
	std::cout << "MutantStack Default Constructor called" << std::endl;
	return ;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &rhs)
{
	std::cout << "MutantStack Copy Constructor called" << std::endl;
	*this = rhs;
}

template <typename T>
MutantStack<T>::~MutantStack(void)
{
	std::cout << "MutantStack Default Destructor called" << std::endl;
	return ;
}

//Operator Overload
template <typename T>
MutantStack<T>	&MutantStack<T>::operator=(const MutantStack<T> &rhs)
{
	std::cout << "MutantStack assign operator overloard called" << std::endl;
	if (this == &rhs)
		return (*this);
	this->std::stack<T>::operator=(rhs);
	return (*this);
}

//Member functions
template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void)
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::begin(void) const
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rbegin(void)
{
	return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::rbegin(void) const
{
	return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end(void)
{
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::end(void) const
{
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rend(void)
{
	return (this->c.rend());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::rend(void) const
{
	return (this->c.rend());
}
#endif
