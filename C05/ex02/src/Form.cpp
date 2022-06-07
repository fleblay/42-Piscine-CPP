#include "Form.hpp"
#include <iostream>
#include "Bureaucrat.hpp"

Form::Form(void) : _name("DefaultFormName"), _signed(0), _gradeToBeSigned(1) , _gradeToBeExecuted(1)
{
	std::cout << "Form Default Constructor called" << std::endl;
	return ;
}

Form::Form(const std::string &name, const int &gradeToBeSigned, const int &gradeToBeExecuted) : _name(name), _signed(0), _gradeToBeSigned(gradeToBeSigned), _gradeToBeExecuted(gradeToBeExecuted)
{
	std::cout << "Form Parametric Constructor called" << std::endl;
	if (gradeToBeSigned > 150 || gradeToBeExecuted > 150)
		throw GradeTooLowException();
	if (gradeToBeSigned < 1 || gradeToBeExecuted < 1)
		throw GradeTooHighException();
	return ;
}

Form::Form(const Form &src) : _gradeToBeSigned(src.getGradeToBeSigned()), _gradeToBeExecuted(src.getGradeToBeExecuted())
{
	std::cout << "Form Copy Constructor called" << std::endl;
	*this = src;
	return ;
}

Form::~Form(void)
{
	std::cout << "Form Default Destructor called" << std::endl;
	return ;
}

Form	&Form::operator=(const Form &rhs)
{
	std::cout << "Form Assign operator overload called" << std::endl;
	(std::string &)this->_name = rhs._name;
	this->_signed = rhs._signed;

	int	&tbsREF = (int &)this->_gradeToBeSigned;
	int	&tbeREF = (int &)this->_gradeToBeExecuted;
	tbsREF = rhs._gradeToBeSigned;
	tbeREF = rhs._gradeToBeExecuted;

	return (*this);
}

const std::string	&Form::getName(void) const
{
	return (this->_name);
}

const bool			&Form::getSignedStatus(void) const
{
	return (this->_signed);
}

const int			&Form::getGradeToBeSigned(void) const
{
	return (this->_gradeToBeSigned);
}

const int			&Form::getGradeToBeExecuted(void) const
{
	return (this->_gradeToBeExecuted);
}

bool				Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToBeSigned)
		throw GradeTooLowException();
	if (this->_signed)
		return (0);
	this->_signed = 1;
	return (1);
}

const char			*Form::GradeTooHighException::what(void) const throw()
{
	return ("Cannot perform operation : grade too high");
}

const char			*Form::GradeTooLowException::what(void) const throw()
{
	return ("Cannot perform operation : grade too low");
}

std::ostream		&operator<<(std::ostream &ostream, const Form &rhs)
{
	ostream	<< rhs.getName() << ", grade to be signed : " << rhs.getGradeToBeSigned()
			<< ", grade to be executed : " << rhs.getGradeToBeExecuted()
			<< ", signed status : " << rhs.getSignedStatus() << "." << std::endl;
	return ostream;
}
