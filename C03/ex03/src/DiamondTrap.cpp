#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << RED;
	std::cout << "Default DiamondTrap Constructor called" << std::endl;
	std::cout << RESET;
	this->setEnergyPoints(ScavTrap::_ScavTrapEnergyPoints);
	this->_Name = ClapTrap::getName() + "_clap_name";
	return ;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name), ScavTrap(), FragTrap()
{
	std::cout << RED;
	std::cout << "Parametric DiamondTrap Constructor called" << std::endl;
	std::cout << RESET;
	this->setEnergyPoints(ScavTrap::_ScavTrapEnergyPoints);
	this->_Name = ClapTrap::getName() + "_clap_name";
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
	this->setName(rhs.getName());
	this->_Name = rhs._Name;
	this->_HitPoints = rhs.getHitPoints();
	this->_EnergyPoints = rhs.getEnergyPoints();
	this->_AttackDamage = rhs.getAttackDamage();
	this->_HitPointsInit = rhs.getHitPointsInit();
	return (*this);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout	<< "My DiamondTrap name : " << this->_Name << std::endl
				<< "My ClapTrap name : " << this->ClapTrap::getName() << std::endl;
	return ;
}
