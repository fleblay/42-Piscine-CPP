#include "AMateria.hpp"

AMateria::AMateria(void) : _type("DefaultType")
{
	std::cout << "Default AMateria Constructor called" << std::endl;
	return ;
}

AMateria::AMateria(const std::string &type) _type(type)
{
	std::cout << "Parametric AMateria Constructor called" << std::endl;
	return ;
}

AMateria::AMateria(AMateria &src) _type(type)
{
	std::cout << "Copy AMateria Constructor called" << std::endl;
	*this = src;
	return ;
}

AMateria	&AMateria::operator=(const AMateria &rhs)
{
	std::cout << "Overload AMateria assign operator called" << std::endl;
	this->_type = rhs.type;
	return ;
}

const std::string	&AMateria::getType(void) const
{
	return (this->_type);
}

void	AMateria::use(ICharacter &target)
{
	std::cout << "* No effect *" << std::endl;
	/*
	else if (this->_type == "cure")
		std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	*/
	return ;	
}
