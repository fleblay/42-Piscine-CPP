#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	PhoneBook	pb;
	std::string	query ("");

	while (query.compare("EXIT"))
	{
		std::cout << "Enter you command : ";
		std::getline(std::cin, query);
		if (!std::cin)
		{
			if (std::cin.eof())
				std::cout << "EOF encountered" << std::endl;
			else
				std::cout << "Failure encountered" << std::endl;
			return (1);
		}
		if (!query.compare("ADD") && !pb.addContact())
			break ;
		else if (!query.compare("SEARCH") && !pb.searchContact())
			break ;
		else if (query.compare("EXIT") && query.compare("ADD") && query.compare("SEARCH"))
			std::cout << "Available commands are : ADD, SEARCH, EXIT" << std::endl;
	}
	return (0);
}
