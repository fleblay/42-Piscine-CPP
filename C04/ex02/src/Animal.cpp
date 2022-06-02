#include "Animal.hpp"
#include <iostream>

Animal::Animal(void) : _type("DefaultAnimalType")
{
	std::cout	<< "Animal Default Constructor Called" << std::endl;
	return ;
}

Animal::Animal(const std::string &type) : _type(type)
{
	std::cout	<< "Animal Parametric Constructor Called" << std::endl;
	return ;
}

Animal::Animal(const Animal &rhs)
{
	std::cout	<< "Animal Copy Constructor Called" << std::endl;
	*this = rhs;
	return ;
}

Animal::~Animal(void)
{
	std::cout	<< "Animal Default Destructor Called" << std::endl;
	return ;
}

const std::string	&Animal::getType(void) const
{
	return (this->_type);
}

Animal &Animal::operator=(const Animal &rhs)
{
	this->_type = rhs._type;
	return (*this);
}

void	Animal::makeSound(void) const
{
	std::cout	<< "* DULL AND BORING ANIMAL SOUND *" << std::endl;
	return ;
}
