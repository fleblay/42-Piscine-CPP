#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void) : ClapTrap()
{
	std::cout << RED;
	std::cout << "Default DiamondTrap Constructor called" << std::endl;
	std::cout << RESET;
	this->setHitPointsInit(100);
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	return ;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << RED;
	std::cout << "Parametric DiamondTrap Constructor called" << std::endl;
	std::cout << RESET;
	this->setHitPointsInit(100);
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	return ;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src)
{
	std::cout << RED;
	std::cout << "Copy DiamondTrap Constructor called" << std::endl;
	std::cout << RESET;
	*this = src;
	return ;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << RED;
	std::cout << "Default DiamondTrap Destructor called" << std::endl;
	std::cout << RESET;
	return ;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &rhs)
{
	std::cout << RED;
	std::cout << "DiamondTrap Assignation overload operator called" << std::endl;
	std::cout << RESET;
	this->_Name = rhs.getName();
	this->_HitPoints = rhs.getHitPoints();
	this->_EnergyPoints = rhs.getEnergyPoints();
	this->_AttackDamage = rhs.getAttackDamage();
	this->_HitPointsInit = rhs.getHitPointsInit();
	return (*this);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << this->_Name << std::endl;
	return ;
}
