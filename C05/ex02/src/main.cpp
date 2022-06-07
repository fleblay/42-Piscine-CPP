#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Form.hpp"
#include <iostream>
#include <time.h>
#include <stdlib.h>

int	main(void)
{
	srand(time(NULL));
	Bureaucrat	newbie("Newbie", 150);
	Bureaucrat	boss("Boss", 1);

	ShrubberyCreationForm	form1("fichier1");

	std::cout << form1;
	std::cout << form1.getTarget() << std::endl;

	newbie.executeForm(form1);
	boss.executeForm(form1);

	newbie.signForm(form1);
	boss.signForm(form1);

	newbie.executeForm(form1);
	boss.executeForm(form1);
}
