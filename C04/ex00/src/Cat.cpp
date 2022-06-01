#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) : Animal("Cat")
{
	std::cout	<< ORANGE;
	std::cout	<< "Cat Default Constructor Called" << std::endl;
	std::cout	<< RESET;
	return ;
}

Cat::Cat(const Cat &rhs) : Animal()
{
	std::cout	<< ORANGE;
	std::cout	<< "Cat Copy Constructor Called" << std::endl;
	std::cout	<< RESET;
	*this = rhs;
	return ;
}

Cat::~Cat(void)
{
	std::cout	<< ORANGE;
	std::cout	<< "Cat Default Destructor Called" << std::endl;
	std::cout	<< RESET;
	return ;
}

Cat &Cat::operator=(const Cat &rhs)
{
	this->_type = rhs._type;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout	<< ORANGE;
	std::cout	<< "* Miaouwwwwwwwwwwwwww *" << std::endl;
	std::cout	<< RESET;
	return ;
}

