#include <iostream>
#include <Contact.hpp>

Contact::Contact(void)
{
	std::cout << "Contact Constructor called" << std::endl;
	return ;
}

Contact::~Contact(void)
{
	std::cout << "Contact Destructor called" << std::endl;
	return ;
}

void	Contact::setInfos(void)
{
	int	i = 0;

	while (i < 5 && !std::cin.eof())
	{
		std::cout << "Please enter " << this->_Infos_type[i] << " :" << std::endl;
		std::getline(std::cin, this->_Infos[i]);
		if (this->_Infos[i].size())
			i++;
		else
			std::cout << "Wrong Input. Please Try Again" << std::endl;
	}
	return ;
}

void	Contact::printInfos(void) const
{
	int	i = 0;
	while (i < 5)
		std::cout << this->_Infos[i++] << std::endl;
	return ;
}

const std::string Contact::_Infos_type[5] = {"First Name", "Last Name", "Nickname", "Phone Number", "Darkest secret"};
