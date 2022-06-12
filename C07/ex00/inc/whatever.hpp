#ifndef WHATEVER_H
# define WHATEVER_H

template<typename T>
void	swap(T &lhs, T &rhs)
{
	T	tmp;

	tmp = lhs;
	lhs = rhs;
	rhs = tmp;
}

template<typename T>
const T 	&min(const T &lhs, const T &rhs)
{
	return (lhs < rhs ? lhs : rhs);
}

template<typename T>
const T 	&max(const T &lhs, const T &rhs)
{
	return (lhs > rhs ? lhs : rhs);
}
#endif
