#ifndef BUREAUCRAT_CLASS_H
# define BUREAUCRAT_CLASS_H

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat
{
	public	:

	Bureaucrat(void);
	Bureaucrat(const std::string &name, const int &grade);
	Bureaucrat(const Bureaucrat &src);
	virtual ~Bureaucrat(void);

	Bureaucrat	&operator=(const Bureaucrat &rhs);

	const std::string	&getName(void) const;
	const int			&getGrade(void) const;
	void				setGrade(const int &NewGrade);
	void				incrementGrade(const int &value);
	void				decrementGrade(const int &value);

	class GradeTooHighException : public std::exception
	{
		public	:
		virtual const char	*what(void) const throw()
		{
			return ("Cannot perform operation : Bureaucrat grade will be to high");
		}
	};

	class GradeTooLowException : public std::exception
	{
		public	:
		virtual const char	*what(void) const throw()
		{
			return ("Cannot perform operation : Bureaucrat grade will be to low");
		}
	};
	
	
	private	:

	const std::string	_name;
	int					_grade;

};

std::ostream	&operator<<(std::ostream &ostream, const Bureaucrat &rhs);

#endif
