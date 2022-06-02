#include "Dog.hpp"
#include <iostream>

Dog::Dog(void) : Animal("Dog")
{
	std::cout	<< GREEN;
	std::cout	<< "Dog Default Constructor Called" << std::endl;
	std::cout	<< RESET;
	this->_Brain = new Brain();
	this->_Brain->setIdeas("I am a good boy?. Does my master love me ?");
	return ;
}

Dog::Dog(const Dog &rhs) : Animal()
{
	std::cout	<< GREEN;
	std::cout	<< "Dog Copy Constructor Called" << std::endl;
	std::cout	<< RESET;
	this->_Brain = new Brain();
	*this = rhs;
	return ;
}

Dog::~Dog(void)
{
	std::cout	<< GREEN;
	std::cout	<< "Dog Default Destructor Called" << std::endl;
	std::cout	<< RESET;
	delete this->_Brain;
	return ;
}

Dog &Dog::operator=(const Dog &rhs)
{
	this->_type = rhs._type;
	this->_Brain = rhs._Brain;
	return (*this);
}

const std::string	&Dog::getIdea(int thoughtNumber) const
{
	return (this->_Brain->getIdeas()[thoughtNumber % 100]);
}

void	Dog::makeSound(void) const
{
	std::cout	<< GREEN;
	std::cout	<< "* Wooooaaaaaaaaaafffff *" << std::endl;
	std::cout	<< RESET;
	return ;
}
