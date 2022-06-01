#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << ORANGE;
	std::cout << "Default ScavTrap Constructor called" << std::endl;
	std::cout << RESET;
	this->setHitPointsInit(100);
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	return ;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << ORANGE;
	std::cout << "Parametric ScavTrap Constructor called" << std::endl;
	std::cout << RESET;
	this->setHitPointsInit(100);
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	return ;
}

ScavTrap::ScavTrap(const ScavTrap &src)
{
	std::cout << ORANGE;
	std::cout << "Copy ScavTrap Constructor called" << std::endl;
	std::cout << RESET;
	*this = src;
	return ;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << ORANGE;
	std::cout << "Default ScavTrap Destructor called" << std::endl;
	std::cout << RESET;
	return ;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &rhs)
{
	std::cout << ORANGE;
	std::cout << "ScavTrap Assignation overload operator called" << std::endl;
	std::cout << RESET;
	this->_Name = rhs.getName();
	this->_HitPoints = rhs.getHitPoints();
	this->_EnergyPoints = rhs.getEnergyPoints();
	this->_AttackDamage = rhs.getAttackDamage();
	this->_HitPointsInit = rhs.getHitPointsInit();
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	if (!this->canDoAction("attack"))
		return ;
	this->_EnergyPoints--;
	std::cout << ORANGE;
	std::cout	<< "ScavTrap " << this->_Name
				<< " attacks " << target
				<< ", causing " << this->_AttackDamage
				<< " points of damage!" << std::endl;
	std::cout << RESET;
	return ;
}

void	ScavTrap::guardGate(void)
{
	std::cout	<< ORANGE;
	std::cout	<< "ScavTrap " << this->_Name
				<< " has entered Gate Keeper mode."
				<< std::endl;
	std::cout << RESET;
	return ;
}
