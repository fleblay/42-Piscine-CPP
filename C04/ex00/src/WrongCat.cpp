#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout	<< ORANGEBOLD;
	std::cout	<< "WrongCat Default Constructor Called" << std::endl;
	std::cout	<< RESET;
	return ;
}

WrongCat::WrongCat(const WrongCat &rhs) : WrongAnimal()
{
	std::cout	<< ORANGEBOLD;
	std::cout	<< "WrongCat Copy Constructor Called" << std::endl;
	std::cout	<< RESET;
	*this = rhs;
	return ;
}

WrongCat::~WrongCat(void)
{
	std::cout	<< ORANGEBOLD;
	std::cout	<< "WrongCat Default Destructor Called" << std::endl;
	std::cout	<< RESET;
	return ;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
	this->_type = rhs._type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout	<< ORANGEBOLD;
	std::cout	<< "* Wrong Miaouwwwwwwwwwwwwww *" << std::endl;
	std::cout	<< RESET;
	return ;
}


