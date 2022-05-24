#include "Harl.hpp"
#include <iostream>
#include <string>

void	print_header(std::string header)
{
	std::cout	<< "[ "
				<< header
				<< " ]"
				<< std::endl;
	return ;
}

int	main(int ac, char *av[])
{
	Harl		Harlito;
	std::string	choice;
	int			choice_number;

	if (ac != 2)
	{
		std::cout << "Wrong arg count" << std::endl;
		return (1);
	}
	choice = av[1];
	choice_number = !choice.compare("DEBUG") * DEBUG +
					!choice.compare("INFO") * INFO +
					!choice.compare("WARNING") * WARNING +
					!choice.compare("ERROR") * ERROR;

	switch (choice_number)
	{
		case DEBUG :	{
							print_header("DEBUG");
							Harlito.complain("DEBUG");
							std::cout << std::endl;
						}	
						
		case INFO :		{
							print_header("INFO");
							Harlito.complain("INFO");
							std::cout << std::endl;
						}

		case WARNING :	{
							print_header("WARNING");
							Harlito.complain("WARNING");
							std::cout << std::endl;
						}

		case ERROR :	{
							print_header("ERROR");
							Harlito.complain("ERROR");
							std::cout << std::endl;
							break ;
						}

		default :		{
							print_header("Probably complaining about insignificant problems");
						}
	}
	return (0);
}
