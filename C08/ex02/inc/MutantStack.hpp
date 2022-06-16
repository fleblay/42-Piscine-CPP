#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

# ifndef DEBUG
#  define DEBUG 0
# endif


# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public	:

	typedef typename std::stack<T>::container_type::iterator				iterator;
	typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;


	//Constructor & Destructor
	MutantStack<T>(void);
	MutantStack<T>(const MutantStack<T> &src);
	~MutantStack<T>(void);

	//Operator Overload
	MutantStack<T>	&operator=(const MutantStack<T> &rhs);


	//Member functions
	iterator				begin(void);
	const_iterator			begin(void) const ;
	reverse_iterator		rbegin(void);
	const_reverse_iterator	rbegin(void) const ;
	iterator				end(void);
	const_iterator			end(void) const ;
	reverse_iterator		rend(void);
	const_reverse_iterator	rend(void) const ;

};

#include "MutantStack.tpp"

# endif
