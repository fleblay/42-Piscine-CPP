#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon(std::string new_type) : _type(new_type)
{
	std::cout << "Weapon Constructor Called" << std::endl;
	return ;
}

Weapon::~Weapon(void)
{
	std::cout << "Weapon Destructor Called" << std::endl;
	return ;
}

const std::string	&Weapon::getType(void) const
{
	const std::string	&typeREF = this->_type;
	return (typeREF);
}

void	Weapon::setType(std::string new_type)
{
	this->_type = new_type;
	return ;
}
