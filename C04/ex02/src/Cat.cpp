#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) : Animal("Cat")
{
	std::cout	<< ORANGE;
	std::cout	<< "Cat Default Constructor Called" << std::endl;
	std::cout	<< RESET;
	this->_Brain = new Brain();
	this->_Brain->setIdeas("Human is stupid, but as long as he feeds me, He will be tolerated...");
	return ;
}

Cat::Cat(const Cat &rhs) : Animal()
{
	std::cout	<< ORANGE;
	std::cout	<< "Cat Copy Constructor Called" << std::endl;
	std::cout	<< RESET;
	this->_Brain = new Brain();
	*this = rhs;
	return ;
}

Cat::~Cat(void)
{
	std::cout	<< ORANGE;
	std::cout	<< "Cat Default Destructor Called" << std::endl;
	std::cout	<< RESET;
	delete this->_Brain;
	return ;
}

Cat &Cat::operator=(const Cat &rhs)
{
	this->_type = rhs._type;
	this->_Brain = rhs._Brain;
	return (*this);
}

const std::string	&Cat::getIdea(int thoughtNumber) const
{
	return (this->_Brain->getIdeas()[thoughtNumber % 100]);
}

void	Cat::makeSound(void) const
{
	std::cout	<< ORANGE;
	std::cout	<< "* Miaouwwwwwwwwwwwwww *" << std::endl;
	std::cout	<< RESET;
	return ;
}

