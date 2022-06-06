#ifndef BUREAUCRAT_CLASS_H
# define BUREAUCRAT_CLASS_H

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat
{
	public	:

	Bureaucrat(void);
	Bureaucrat(const Bureaucrat &src);
	virtual ~Bureaucrat(void);

	Bureaucrat	&operator=(const Bureaucrat &rhs);

	const std::string	&getName(void) const;
	const int			&getGrade(void) const;
	void				setGrade(const int &NewGrade);

	class GradetooHighException : public std::exception
	{
		public	:
		virtual const std::

	};
	
	private	:

	const std::string	_name;
	int					_grade;

};

std::ostream	&operator<<(std::ostream &ostream, const Bureaucrat &rhs);

#endif
