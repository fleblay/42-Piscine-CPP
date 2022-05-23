#include "HumanB.hpp"
#include "iostream"

HumanB::HumanB(std::string name) : _name(name), _weapon(0)
{
	std::cout << "HumanB Constructor called" << std::endl;
	return ;
}

HumanB::~HumanB(void)
{
	std::cout << "HumanB Destructor called" << std::endl;
	return ;
}

void	HumanB::attack(void) const
{
	std::cout	<< this->_name
				<< " attacks with their ";
	if (this->_weapon)
		std::cout	<< this->_weapon->getType();
	else
		std::cout	<< "bare hands";
	std::cout << std::endl;
	return ;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
	return ;
}
