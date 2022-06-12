#ifndef ITER_H
# define ITER_H

#include <cstddef>
#include <iostream>

template<typename T>
void	iter(const T array[], const std::size_t size, void (*fx)(const T &))
{
	for (std::size_t i = 0; i < size; i++)
		fx(array[i]);
	return ;
}

template<typename T>
void	printer(const T &item)
{
	std::cout << "Item value : " << item << std::endl;
	return ;
}

#endif
