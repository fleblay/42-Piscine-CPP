#include "Intern.hpp"
#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void)
{
	std::cout << "Intern Default Constructor called" << std::endl;
	return ;
}

Intern::Intern(const Intern &src)
{
	std::cout << "Intern Copy Constructor called" << std::endl;
	*this = src;
	return ;
}

Intern::~Intern(void)
{
	std::cout << "Intern Default Destructor called" << std::endl;
	return ;
}

Intern	&Intern::operator=(const Intern &rhs)
{
	std::cout << "Intern Assign operator overload called" << std::endl;
	(void)rhs;
	return (*this);
}

Form	*Intern::makeForm(const std::string &formRequest, const std::string &formTarget) const
{
	Form		*availableForms[3] = {new ShrubberyCreationForm(formTarget), new RobotomyRequestForm(formTarget), new PresidentialPardonForm(formTarget)};
	std::string	availableFormsName[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};	

	std::size_t i = 0;
	for (; i < 3; i++)
	{
		if (formRequest == availableFormsName[i])
			break ;
	}
	if (i == 3)
	{
		std::cout << "Couldn't find a valid corresponding form name" << std::endl;
		for (std::size_t j = 0; j < 3; j++)
			delete availableForms[j];
		return (NULL);
	}
	Form	*ret = availableForms[i];
	for (std::size_t j = 0; j < 3; j++)
	{
		if (i !=j)
			delete availableForms[j];
	}
	std::cout << "Intern creates " << formRequest << " form." << std::endl;
	return (ret);
}
