#ifndef EASYFIND_H
# define EASYFIND_H

#include <algorithm> 
#include <iostream>

template<typename T>
typename T::const_iterator easyfind_const(const T &src, const int &toFind)
{
	typename T::const_iterator	found;

	found = find(src.begin(), src.end(), toFind);
	if (found != src.end())
	{
		std::cout << "Element is found!" << std::endl;
		return (found);
	}
	else
	{
		std::cout << "No such member!" << std::endl;
		return (src.end());
	}
}

template<typename T>
typename T::iterator easyfind(T &src, const int &toFind)
{
	typename T::iterator	found;

	found = find(src.begin(), src.end(), toFind);
	if (found != src.end())
	{
		std::cout << "Element is found!" << std::endl;
		return (found);
	}
	else
	{
		std::cout << "No such member!" << std::endl;
		return (src.end());
	}
}
#endif
