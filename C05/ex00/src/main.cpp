#include "Bureaucrat.hpp"
#include <iostream>

int	main(void)
{
	Bureaucrat	Bobby;
	Bureaucrat	Joe;

	Joe = Bobby;
	std::cout << Bobby;
	std::cout << Joe;

	return (0);
}
