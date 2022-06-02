#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void) : _type("DefaultWrongAnimalType")
{
	std::cout	<< "WrongAnimal Default Constructor Called" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(const std::string &type) : _type(type)
{
	std::cout	<< "WrongAnimal Parametric Constructor Called" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal &rhs)
{
	std::cout	<< "WrongAnimal Copy Constructor Called" << std::endl;
	*this = rhs;
	return ;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout	<< "WrongAnimal Default Destructor Called" << std::endl;
	return ;
}

const std::string	&WrongAnimal::getType(void) const
{
	return (this->_type);
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs)
{
	this->_type = rhs._type;
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout	<< "* DULL AND BORING WRONG ANIMAL SOUND *" << std::endl;
	return ;
}

