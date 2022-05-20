#include <iostream>
#include <Contact.hpp>

Contact::Contact(void)
{
	//std::cout << "Contact Constructor called" << std::endl;
	return ;
}

Contact::~Contact(void)
{
	//std::cout << "Contact Destructor called" << std::endl;
	return ;
}

int	Contact::setInfos(void)
{
	int	i = 0;

	while (i < 5)
	{
		std::cout << "Please enter " << this->_Infos_type[i] << " : ";
		std::getline(std::cin, this->_Infos[i]);
		if (!std::cin)
		{
			if (std::cin.eof())
				std::cout << "EOF encountered" << std::endl;
			else
				std::cout << "Failure encountered" << std::endl;
			return (0);
		}
		if (this->_Infos[i].size())
			i++;
		else
			std::cout << "Empty Input. Please Try Again" << std::endl;
	}
	return (1);
}

std::string	Contact::getInfo(int index) const
{
	return (this->_Infos[index]);
}

void	Contact::printInfos(void) const
{
	int	i = 0;
	while (i < 5)
		std::cout << this->_Infos[i++] << std::endl;
	return ;
}

const std::string Contact::_Infos_type[5] = {"First Name", "Last Name", "Nickname", "Phone Number", "Darkest secret"};
