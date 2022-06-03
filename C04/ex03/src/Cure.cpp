#include "Cure.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Colors.hpp"
#include <iostream>

Cure::Cure(void) : AMateria("cure")
{
	std::cout << MAGENTA"Default Cure Constructor called"RESET << std::endl;
	return ;
}

Cure::Cure(const Cure &src) : AMateria("cure")
{
	std::cout << MAGENTA"Copy Cure Constructor called"RESET << std::endl;
	*this = src;
	return ;
}

Cure::~Cure(void)
{
	std::cout << MAGENTA"Default Cure Destructor called"RESET << std::endl;
	return ;
}

Cure	&Cure::operator=(const Cure &rhs)
{
	std::cout << MAGENTA"Overload Cure assign operator called"RESET << std::endl;
	this->_type = rhs._type;
	return (*this);
}

AMateria	*Cure::clone(void) const
{
	return (new Cure());
}

void	Cure::use(ICharacter &target)
{
	std::cout << MAGENTA"* heals " << target.getName() << "'s wounds *"RESET << std::endl;
	return ;	
}
