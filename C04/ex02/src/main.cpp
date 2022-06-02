#include "WrongAnimal.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include <iostream>

int main(void)
{
	Cat	Garfield;
	Dog	Odie;

	std::cout << Garfield.getIdea(10) << std::endl;
	std::cout << Odie.getIdea(10) << std::endl;

	const Animal	*j = new Dog();
	const Animal	*i = new Cat();

	std::cout << "-----------------START OF DELETION-------------------" << std::endl;

	delete j;
	delete i;

	std::cout << "-----------------END OF DELETION-------------------" << std::endl;

	Animal	*tab[4];

	for (std::size_t i = 0; i < 4 ; i++)
		i % 2 ? tab[i] = new Dog() : tab[i] = new Cat();

	std::cout << "-----------------END OF TAB CREATION-------------------" << std::endl;

	for (std::size_t i = 0; i < 4 ; i++)
		delete tab[i];
	
	std::cout << "-----------------END OF TAB DELETION-------------------" << std::endl;


	/*
	Animal	animal;
	*/

	return (0);
}
