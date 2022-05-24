#include "Harl.hpp"
#include <iostream>

Harl::Harl(void) 
{
	std::cout << "Harl 2.0 Constructor Called" << std::endl;
	this->_comment = {this->_debug , this->_info, this->_warning, this->_error};
	return ;
}

Harl::~Harl(void)
{
	std::cout << "Harl 2.0 Destructor Called" << std::endl;
	return ;
}

void	Harl::complain(std::string level)
{
	std::cout << level << std::endl;

}

void	Harl::_debug(void)
{

}

void	Harl::_info(void)
{

}

void	Harl::_warning(void)
{

}

void	Harl::_error(void)
{

}
