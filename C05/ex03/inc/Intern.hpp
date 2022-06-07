#ifndef INTERN_CLASS_H
# define INTERN_CLASS_H

#include <string>
#include <iostream>

class Form;

class Intern
{
	public	:

	Intern(void);
	Intern(const Intern &src);
	virtual ~Intern(void);

	Intern	&operator=(const Intern &rhs);

	Form	*makeForm(const std::string &formRequest, const std::string &formTarget) const;
};

#endif
