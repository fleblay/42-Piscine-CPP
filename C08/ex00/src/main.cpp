#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

void	print(const int &src)
{
	std::cout << src << std::endl;
}

int main(void)
{
	std::vector<int>	v;

	v.push_back(11);
	v.push_back(22);
	v.push_back(33);

	std::vector<int>::iterator	it;
	it = easyfind(v, 22);
	if (it != v.end())
		*it = 44;
	easyfind(v, 11);
	easyfind(v, 22);

	for_each(v.begin(), v.end(), print);

	std::list<int>		l;	

	l.push_front(42);
	l.push_front(-42);
	l.push_front(101010);
	l.push_front(0);
	l.push_front(21);

	std::list<int>::iterator	it2;
	it2 = easyfind(l, -42);
	if (it2 != l.end())
		*it2 = 44;
	easyfind(l, 11);
	easyfind(l, 22);
	
	for_each(l.begin(), l.end(), print);
	return (0);
}
