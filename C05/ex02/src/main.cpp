#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Form.hpp"
#include <iostream>
#include <time.h>
#include <stdlib.h>

int	main(void)
{
	std::cout << "---------------0----------------" << std::endl;
	srand(time(NULL));
	Bureaucrat	newbie("Newbie", 150);
	Bureaucrat	boss("Boss", 1);

	std::cout << "---------------1----------------" << std::endl;

	ShrubberyCreationForm	form1("fichier1");

	std::cout << form1;
	std::cout << form1.getTarget() << std::endl;

	newbie.executeForm(form1);
	boss.executeForm(form1);

	newbie.signForm(form1);
	boss.signForm(form1);

	newbie.executeForm(form1);
	boss.executeForm(form1);

	std::cout << "---------------2----------------" << std::endl;

	RobotomyRequestForm	form2("Bender");

	std::cout << form2;
	std::cout << form2.getTarget() << std::endl;

	newbie.executeForm(form2);
	boss.executeForm(form2);

	newbie.signForm(form2);
	boss.signForm(form2);

	newbie.executeForm(form2);
	boss.executeForm(form2);
	boss.executeForm(form2);
	boss.executeForm(form2);
	boss.executeForm(form2);
	boss.executeForm(form2);
	boss.executeForm(form2);
	boss.executeForm(form2);
	boss.executeForm(form2);

	std::cout << "---------------4----------------" << std::endl;

	PresidentialPardonForm	form3("Julian_Assange");

	std::cout << form3;
	std::cout << form3.getTarget() << std::endl;

	newbie.executeForm(form3);
	boss.executeForm(form3);

	newbie.signForm(form3);
	boss.signForm(form3);

	newbie.executeForm(form3);
	boss.executeForm(form3);
}
