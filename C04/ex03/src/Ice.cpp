#include "Ice.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Colors.hpp"
#include <iostream>

Ice::Ice(void) : AMateria("ice")
{
	std::cout << RED"Default Ice Constructor called"RESET << std::endl;
	return ;
}

Ice::Ice(const Ice &src) : AMateria("ice")
{
	std::cout << RED"Copy Ice Constructor called"RESET << std::endl;
	*this = src;
	return ;
}

Ice::~Ice(void)
{
	std::cout << RED"Default Ice Destructor called"RESET << std::endl;
	return ;
}

Ice	&Ice::operator=(const Ice &rhs)
{
	std::cout << RED"Overload Ice assign operator called"RESET << std::endl;
	this->_type = rhs._type;
	return (*this);
}

AMateria	*Ice::clone(void) const
{
	return (new Ice());
}

void	Ice::use(ICharacter &target)
{
	std::cout << RED"* shoots an ice bolt at " << target.getName() << " *"RESET << std::endl;
	return ;	
}
