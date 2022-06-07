#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main(void)
{
	Bureaucrat	newbie("Newbie", 150);
	Bureaucrat	boss("boss", 1);

	try
	{
		Form	FormCrash("Wrong Form", 0, 100);
	}
	catch (std::exception &e)
	{
		std::cout << "error trying to create form" << std::endl;
	}

	try
	{
		Form	FormCrash2("Wrong Form", 110, 0);
	}
	catch (std::exception &e)
	{
		std::cout << "error trying to create form" << std::endl;
	}
	try
	{
		Form	FormCrash3("Wrong Form", 1, 160);
	}
	catch (std::exception &e)
	{
		std::cout << "error trying to create form" << std::endl;
	}

	try
	{
		Form	FormCrash4("Wrong Form", 160, 1);
	}
	catch (std::exception &e)
	{
		std::cout << "error trying to create form" << std::endl;
	}

	Form		Form1;
	Form		FormNamed("Formulaire", 50, 100);
	Form		FormNamedCopy(FormNamed);

	std::cout	<< Form1;
	std::cout	<< FormNamed;
	std::cout	<< FormNamedCopy;

	newbie.signForm(FormNamed);
	boss.signForm(FormNamed);
	boss.signForm(FormNamed);

	try
	{
		FormNamedCopy.beSigned(newbie);
		std::cout << "Signature went well" << std::endl;

	}
	catch (std::exception &e)
	{
		std::cout << "error trying to sign form" << std::endl;
		std::cout << e.what() << std::endl;
	}

	try
	{
		FormNamedCopy.beSigned(boss);
		std::cout << "Signature went well" << std::endl;

	}
	catch (std::exception &e)
	{
		std::cout << "error trying to sign form" << std::endl;
		std::cout << e.what() << std::endl;
	}
	return (0);
}
