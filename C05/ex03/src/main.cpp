#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include <iostream>
#include <time.h>
#include <stdlib.h>

int	main(void)
{
	srand(time(NULL));
	std::cout << "---------------0----------------" << std::endl;
	Intern		someRandomIntern;
	Form		*rrf, *scf, *ppf, *error;
	Bureaucrat	Boss("Boss", 1);	

	std::cout << "---------------1----------------" << std::endl;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << "---------------2----------------" << std::endl;
	scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
	std::cout << "---------------3----------------" << std::endl;
	ppf = someRandomIntern.makeForm("presidential pardon", "Joe_Dalton");
	std::cout << "---------------4----------------" << std::endl;
	error = someRandomIntern.makeForm("Yolo", "toto");
	std::cout << "---------------5----------------" << std::endl;

	Boss.signForm(*rrf);
	Boss.signForm(*scf);
	Boss.signForm(*ppf);
	std::cout << "---------------6----------------" << std::endl;

	Boss.executeForm(*rrf);
	Boss.executeForm(*scf);
	Boss.executeForm(*ppf);

	std::cout << "---------------7----------------" << std::endl;
	delete rrf;
	delete scf;
	delete ppf;
	std::cout << "---------------8----------------" << std::endl;

	return (0);
}
