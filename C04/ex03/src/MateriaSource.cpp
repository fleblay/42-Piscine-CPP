#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Colors.hpp"
#include <iostream>

MateriaSource::MateriaSource(void)
{
	std::cout << BLUE"Default MateriaSource Constructor called"RESET << std::endl;
	for (std::size_t i = 0; i < 4 ; i++)
		this->_inventory[i] = NULL;
	return ;
}

MateriaSource::MateriaSource(const MateriaSource &src) 
{
	std::cout << BLUE"Copy MateriaSource Constructor called"RESET << std::endl;
	*this = src;
	return ;
}

MateriaSource::~MateriaSource(void)
{
	std::cout << BLUE"Default MateriaSource Destructor called"RESET << std::endl;
	for (std::size_t i = 0; i < 4 ; i++)
		delete this->_inventory[i];
	return ;
}

MateriaSource		&MateriaSource::operator=(const MateriaSource &rhs)
{
	std::cout << BLUE"Overload MateriaSource assign operator called"RESET << std::endl;
	for (std::size_t i = 0; i < 4 ; i++)
	{
		delete this->_inventory[i];
		this->_inventory[i] = rhs._inventory[i];
	}
	return (*this);
}

void				MateriaSource::learnMateria(AMateria *m)
{
	std::size_t i = 0;

	while (i < 4 && this->_inventory[i])
		i++;
	if (i == 4)
	{
		std::cout	<< "Cannot learn new materia, MateriaSource inventory is full"
					<< std::endl;	
		return ;
	}
	this->_inventory[i] = m->clone();
	return ;
}

AMateria			*MateriaSource::createMateria(const std::string &type)
{
	std::size_t i = 0;

	while (i < 4 && this->_inventory[i])
	{
		if (type == this->_inventory[i]->getType())
			return (this->_inventory[i]->clone());
		i++;
	}
	std::cout	<< "No Materia named " << type << " in this MateriaSource" << std::endl;	
	return (NULL);
}
