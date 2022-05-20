#include "Zombie.hpp"
#include <string>
#include <iostream>

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << "Zombie Constructor called" << std::endl;
	return ;
}

Zombie::Zombie(void) : _name("DefaultZombieName")
{
	std::cout << "Zombie Constructor (NONAME) called" << std::endl;
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie Destructor called" << std::endl;
	std::cout << this->_name << " is being destroyed" << std::endl;
	return ;
}

void	Zombie::announce(void)
{
	std::cout	<< this->_name
				<< ": BraiiiiiiinnnzzzZ..."
				<< std::endl;
	return ;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
	return ;
}
