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
	Intern		someRandomIntern;
	Form		*rrf, *scf, *ppf, *error;
	Bureaucrat	Boss("Boss", 1);	

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
	ppf = someRandomIntern.makeForm("presidential pardon", "Joe_Dalton");
	error = someRandomIntern.makeForm("Yolo", "toto");

	Boss.signForm(*rrf);
	Boss.signForm(*scf);
	Boss.signForm(*ppf);

	Boss.executeForm(*rrf);
	Boss.executeForm(*scf);
	Boss.executeForm(*ppf);

	delete rrf;
	delete scf;
	delete ppf;

	return (0);
}
