#ifndef ROBOTOMYREQUESTFORM_CLASS_H
# define ROBOTOMYREQUESTFORM_CLASS_H

#include <string>
#include <iostream>
#include <stdexcept>

#include "Form.hpp"

class Bureaucrat;

class RobotomyRequestForm : public Form
{
	public	:

	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &src);
	virtual ~RobotomyRequestForm(void);

	const std::string				&getTarget(void) const;

	RobotomyRequestForm	&operator=(const RobotomyRequestForm &rhs);

	virtual void		execute(const Bureaucrat &executor) const;

	private	:

	std::string	_target;
};

#endif
