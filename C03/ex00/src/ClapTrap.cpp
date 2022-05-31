#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void) : _Name("DefaultName"), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0), _HitPointsInit(10)
{
	std::cout << "Default Constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(const std::string &name) : _Name(name), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0), _HitPointsInit(10)
{
	std::cout << "Parametric Constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "Copy Constructor called" << std::endl;
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

unsigned int	ClapTrap::getHitPointsInit(void) const
{
	return (this->_HitPointsInit);
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	std::cout << "Assignation overload operator called" << std::endl;
	this->_Name = rhs.getName();
	this->_HitPoints = rhs.getHitPoints();
	this->_EnergyPoints = rhs.getEnergyPoints();
	this->_AttackDamage = rhs.getAttackDamage();
	this->_HitPointsInit = rhs.getHitPointsInit();
	return (*this);
}


bool	ClapTrap::canDoAction(const std::string &action_name) const
{
	if (this->_HitPoints == 0)
	{
		std::cout	<< "ClapTrap " << this->_Name
					<< " cannot " << action_name << " because it is dead."
					<< std::endl;
		return (0);
	}
	if (this->_EnergyPoints == 0)
	{
		std::cout	<< "ClapTrap " << this->_Name
					<< " cannot " << action_name << " because it has no energy."
					<< std::endl;
		return (0);
	}
	return (1);
}


void	ClapTrap::attack(const std::string &target)
{
	if (!this->canDoAction("attack"))
		return ;
	this->_EnergyPoints--;
	std::cout	<< "ClapTrap " << this->_Name
				<< " attacks " << target
				<< ", causing " << this->_AttackDamage
				<< " points of damage!" << std::endl;
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->canDoAction("take damage"))
		return ;
	amount < this->_HitPoints ? this->_HitPoints -= amount : this->_HitPoints = 0;

	std::cout	<< "ClapTrap " << this->_Name
				<< " takes " << amount << " points of damage!"
				<< " It now has " << this->_HitPoints << "HP." << std::endl;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->canDoAction("repair itself"))
		return ;
	this->_EnergyPoints--;
	amount + this->_HitPoints < this->_HitPointsInit ? this->_HitPoints += amount : this->_HitPoints = this->_HitPointsInit;

	std::cout	<< "ClapTrap " << this->_Name
				<< " heals " << amount << " HitPoints!"
				<< " It now has " << this->_HitPoints << "HP." << std::endl;
	return ;
}
