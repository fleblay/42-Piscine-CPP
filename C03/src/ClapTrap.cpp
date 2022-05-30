#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void) : _Name("DefaultName"), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << "Default Constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(const std::string &name) : _Name(name), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << "Parametric Constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	*this = src;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Default Destructor called" << std::endl;
	return ;
}

std::string		ClapTrap::getName(void) const
{
	return (this->_Name);
}

unsigned int	ClapTrap::getHitPoints(void) const
{
	return (this->_HitPoints);
}

unsigned int	ClapTrap::getEnergyPoints(void) const
{
	return (this->_EnergyPoints);
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	return (this->_AttackDamage);
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	this->_Name = rhs.getName();
	this->_HitPoints = rhs.getHitPoints();
	this->_EnergyPoints = rhs.getEnergyPoints();
	this->_AttackDamage = rhs.getAttackDamage();
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{


}
