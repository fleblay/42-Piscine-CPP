#include "Harl.hpp"
#include <iostream>

Harl::Harl(void) 
{
	//std::cout << "Harl 2.0 Constructor Called" << std::endl;
	this->_comment[0] = &Harl::_debug;
	this->_comment[1] = &Harl::_info;
	this->_comment[2] = &Harl::_warning;
	this->_comment[3] = &Harl::_error;
	return ;
}

Harl::~Harl(void)
{
	//std::cout << "Harl 2.0 Destructor Called" << std::endl;
	return ;
}

void	Harl::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if (Harl::_LevelName[i].compare(level) == 0)
			return((this->*_comment[i])());
	}
	std::cout	<< "Not a valid Harl level" << std::endl;
	return ;
}

void	Harl::_debug(void)
{
	std::cout	<< "I love having extra bacon for my 7XL-double-cheese-triple"
				<< "-pickle-special-ketchup burger. I really do!"
				<< std::endl;
	return ;
}

void	Harl::_info(void)
{
	std::cout	<< "I cannot believe adding extra bacon costs more money. You "
				<<	"didn’t put enough bacon in my burger! If you did, I wouldn’t "
				<<	"be asking for more!"
				<< std::endl;
	return ;
}

void	Harl::_warning(void)
{
	std::cout	<< "I think I deserve to have some extra bacon for free. I’ve "
				<<	"been coming for years whereas you started working here since"
				<<	" last month."
				<< std::endl;
	return ;
}

void	Harl::_error(void)
{
	std::cout	<< "This is unacceptable! I want to speak to the manager now."
				<< std::endl;
	return ;
}

const std::string	Harl::_LevelName[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
