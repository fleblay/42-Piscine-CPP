#include "Character.hpp"
#include "ICharacter.hpp"
#include "Colors.hpp"
#include "AMateria.hpp"
#include <iostream>

Character::Character(void) : _name("DefaultCharacterName")
{
	std::cout << ORANGE"Default Character Constructor called"RESET << std::endl;
	for (std::size_t i = 0; i < 4 ; i++)
		this->_inventory[i] = NULL;
	for (std::size_t i = 0; i < 256 ; i++)
		this->_discarded[i] = NULL;
	return ;
}

Character::Character(const std::string &name) : _name(name)
{
	std::cout << ORANGE"Parametric Character Constructor called"RESET << std::endl;
	for (std::size_t i = 0; i < 4 ; i++)
		this->_inventory[i] = NULL;
	for (std::size_t i = 0; i < 256 ; i++)
		this->_discarded[i] = NULL;
	return ;
}

Character::Character(const Character &src) 
{
	std::cout << ORANGE"Copy Character Constructor called"RESET << std::endl;
	*this = src;
	return ;
}

Character::~Character(void)
{
	std::cout << ORANGE"Default Character Destructor called"RESET << std::endl;
	for (std::size_t i = 0; i < 4 ; i++)
		delete this->_inventory[i];
	for (std::size_t i = 0; i < 256 ; i++)
		delete this->_discarded[i];
	return ;
}

Character	&Character::operator=(const Character &rhs)
{
	std::cout << ORANGE"Overload Character assign operator called"RESET << std::endl;
	this->_name = rhs._name;
	for (std::size_t i = 0; i < 4 ; i++)
	{
		delete this->_inventory[i];
		if (rhs._inventory[i])
			this->_inventory[i] = rhs._inventory[i]->clone();
	}
	for (std::size_t i = 0; i < 256 ; i++)
	{
		delete this->_discarded[i];
		if (rhs._inventory[i])
			this->_discarded[i] = rhs._discarded[i]->clone();
	}
	return (*this);
}

const std::string	&Character::getName() const
{
	return (this->_name);
}

void				Character::equip(AMateria *m)
{
	std::size_t i = 0;

	while (i < 4 && this->_inventory[i])
		i++;
	if (i == 4)
	{
		std::cout	<< "Cannot equip new materia, inventory is full for "
					<< this->getName() << "." << std::endl;	
		return ;
	}
	if (!m)
	{
		std::cout	<< "Cannot equip new materia, Materia is NULL" << std::endl;
		return ;
	}
	this->_inventory[i] = m->clone();
	return ;
}

void				Character::unequip(int idx)
{
	std::size_t i = 0;

	if (idx > 3 || idx < 0)
	{
		std::cout	<< "Out of range index for unequip for " << this->getName()
					<< "." << std::endl;
		return ;
	}
	if (!this->_inventory[idx])
	{
		std::cout	<< "No materia to unequip for " << this->getName()
					<< "at slot " << idx << " ."  << std::endl;
		return ;
	}
	while (i < 256 && this->_discarded[i])
		i++;
	if (i == 256)
	{
		std::cout	<< "Cannot properly unequip materia, discarded is full for "
					<< this->getName() << ". You may have leaks now" << std::endl;	
	}
	this->_discarded[i] = this->_inventory[idx];
	this->_inventory[idx] = NULL;
	return ;
}

void				Character::use(int idx, ICharacter &target)
{
	if (idx > 3 || idx < 0)
	{
		std::cout	<< "Out of range index for use for " << this->getName()
					<< "." << std::endl;
		return ;
	}
	if (!this->_inventory[idx])
	{
		std::cout	<< "No materia to use for " << this->getName()
					<< " at slot " << idx << " ."  << std::endl;
		return ;
	}
	this->_inventory[idx]->use(target);
	return ;
}
