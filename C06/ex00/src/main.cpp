#include <iostream>
#include <cstdlib>
#include <string>


//Dectect right type with parsing
//convert using strtod etc...
//Use static cast to create other value
//Display

int	main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cout << "Wrong usage" << std::endl;
		return (1);
	}
	std::string	input = av[1];
	if (input.find_last_of("f") != std::string::npos)
	{
	}

	return (0);
}
