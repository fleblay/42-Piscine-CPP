#include "Bureaucrat.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "---------------0----------------" << std::endl;

	Bureaucrat	Bobby;
	Bureaucrat	Joe;
	Bureaucrat	BobbyJoe(Bureaucrat("Bobby-Joe", 100));

	Joe = Bobby;
	std::cout << Bobby;
	std::cout << Joe;
	std::cout << BobbyJoe;

	std::cout << "---------------1----------------" << std::endl;
	try
	{
		Bureaucrat	Oliver1("Oliver1", 140);
		std::cout << Oliver1;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "---------------2----------------" << std::endl;
	try
	{
		Bureaucrat	Oliver2("Oliver2", 0);
		std::cout << Oliver2;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "---------------3----------------" << std::endl;
	try
	{
		Bureaucrat	Oliver3("Oliver3", 160);
		std::cout << Oliver3;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "---------------4----------------" << std::endl;
	try
	{
		Bobby.incrementGrade(10);
		Bobby.decrementGrade(20);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "---------------5----------------" << std::endl;
	try
	{
		Joe.incrementGrade(160);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
