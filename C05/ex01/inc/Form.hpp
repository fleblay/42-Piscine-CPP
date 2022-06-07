#ifndef FORM_CLASS_H
# define FORM_CLASS_H

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class Form
{
	public	:

	Form(void);
	Form(const std::string &name, const int &gradeToBeSigned, const int &gradeToBeExecuted);
	Form(const Form &src);
	virtual ~Form(void);

	Form	&operator=(const Form &rhs);

	const std::string	&getName(void) const;
	const bool			&getSignedStatus(void) const;
	const int			&getGradeToBeSigned(void) const;
	const int			&getGradeToBeExecuted(void) const;

	void				beSigned(const Bureaucrat &bureaucrat);

	class GradeTooHighException : public std::exception
	{
		public	:
		virtual const char	*what(void) const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public	:
		virtual const char	*what(void) const throw();
	};
	
	private	:

	const std::string	_name;
	bool				_signed;
	const int			_gradeToBeSigned;
	const int			_gradeToBeExecuted;

};

std::ostream	&operator<<(std::ostream &ostream, const Form &rhs);

#endif
