#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _ContactCount(0)
{
	//std::cout << "PhoneBook Constructor Called" << std::endl;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	//std::cout << "PhoneBook Destructor Called" << std::endl;
	return ;
}

int	PhoneBook::addContact(void)
{
	int	ret ;

	if (this->_ContactCount > 7)
		std::cout << "Warning. You are replacing contact [" << this->_ContactCount % 8 << "]" << std::endl;
	ret = this->_ContactArray[this->_ContactCount % 8].setInfos();
	if (ret)
		this->_ContactCount++;
	return (ret);
}

void	PhoneBook::printContactList(void)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < 8 && i < this->_ContactCount)
	{
		std::cout.setf(std::ios::right, std::ios::adjustfield);
		std::cout.width(10);
		std::cout << i;
		j = 0;
		while (j < 3)
		{
			std::cout.width(0);
			std::cout << "|";
			if (this->_ContactArray[i]._Infos[j].size() > 10)
			{
				k = 0;
				while (k < 9)
					std::cout << this->_ContactArray[i]._Infos[j].at(k++);
				std::cout << ".";
			}
			else
			{
				std::cout.width(10);
				std::cout << this->_ContactArray[i]._Infos[j];
			}
			j++;
		}
		std::cout << std::endl;
		i++;
	}
}

int	PhoneBook::searchContact(void)
{
	std::string	query ("");
	PhoneBook::printContactList();

	if (this->_ContactCount == 0)
	{
		std::cout << "The PhoneBook is empty !" << std::endl;
		return (1);
	}
	while (query.size() != 1 || !isdigit(query.at(0)) || query.at(0) - 48 >= this->_ContactCount)
	{
		std::cout << "Please enter contact index of contact you wish to display : ";
		std::getline(std::cin, query);
		if (!std::cin)
		{
			if (std::cin.eof())
				std::cout << "EOF encountered" << std::endl;
			else
				std::cout << "Failure encountered" << std::endl;
			return (0);
		}
		if (query.at(0) - 48 >= 8)
			continue ;
	}
	this->_ContactArray[query.at(0) - 48].printInfos();
	return (1);
}
