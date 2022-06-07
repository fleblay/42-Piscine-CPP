#ifndef SHRUBBERYCREATIONFORM_CLASS_H
# define SHRUBBERYCREATIONFORM_CLASS_H

#include <string>
#include <iostream>
#include <stdexcept>

#include "Form.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public Form
{
	public	:

	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &src);
	virtual ~ShrubberyCreationForm(void);

	const std::string				&getTarget(void) const;

	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &rhs);

	virtual bool		execute(const Bureaucrat &executor) const;

	private	:

	std::string	_target;
};

#endif

