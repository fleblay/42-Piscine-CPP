#ifndef PRESIDENTIALPARDONFORM_CLASS_H
# define PRESIDENTIALPARDONFORM_CLASS_H

#include <string>
#include <iostream>
#include <stdexcept>

#include "Form.hpp"

class Bureaucrat;

class PresidentialPardonForm : public Form
{
	public	:

	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &src);
	virtual ~PresidentialPardonForm(void);

	const std::string				&getTarget(void) const;

	PresidentialPardonForm	&operator=(const PresidentialPardonForm &rhs);

	virtual void			execute(const Bureaucrat &executor) const;

	private	:

	std::string	_target;
};

#endif
