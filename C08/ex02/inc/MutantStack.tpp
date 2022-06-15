#ifndef MUTANTSTACK_T
# define MUTANTSTACK_T

# ifndef MUTANTSTACK_H
# error __FILE__ should only be included via MutanStack.hpp
#  endif

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void)
{
	return (this->c.begin());

}


















#endif
