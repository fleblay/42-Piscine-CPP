#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

void	print(const int &src)
{
	std::cout << src << std::endl;
}

int main(void)
{
	std::vector<int> v;

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

	return (0);
}
