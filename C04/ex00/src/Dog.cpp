#include "Dog.hpp"
#include <iostream>

Dog::Dog(void) : Animal("Dog")
{
	std::cout	<< GREEN;
	std::cout	<< "Dog Default Constructor Called" << std::endl;
	std::cout	<< RESET;
	return ;
}

Dog::Dog(const Dog &rhs) : Animal()
{
	std::cout	<< GREEN;
	std::cout	<< "Dog Copy Constructor Called" << std::endl;
	std::cout	<< RESET;
	*this = rhs;
	return ;
}

Dog::~Dog(void)
{
	std::cout	<< GREEN;
	std::cout	<< "Dog Default Destructor Called" << std::endl;
	std::cout	<< RESET;
	return ;
}

Dog &Dog::operator=(const Dog &rhs)
{
	this->_type = rhs._type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout	<< GREEN;
	std::cout	<< "* Wooooaaaaaaaaaafffff *" << std::endl;
	std::cout	<< RESET;
	return ;
}
