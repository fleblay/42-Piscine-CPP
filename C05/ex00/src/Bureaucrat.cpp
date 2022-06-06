#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(void) : _name("DefaultBureaucratName"), _grade(150)
{
	std::cout << "Bureaucrat Default Constructor called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(const std::string &name, const int &grade) : _name(name)
{
	std::cout << "Bureaucrat Parametric Constructor called" << std::endl;
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	this->setGrade(grade);
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	std::cout << "Bureaucrat Copy Constructor called" << std::endl;
	*this = src;
	return ;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat Default Destructor called" << std::endl;
	return ;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &rhs)
{
	std::cout << "Bureaucrat Assign operator overload called" << std::endl;
	(std::string &)this->_name = rhs._name;
	this->_grade = rhs._grade;
	return (*this);
}

const std::string	&Bureaucrat::getName(void) const
{
	return (this->_name);
}

const int			&Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void				Bureaucrat::setGrade(const int	&NewGrade)
{
	if (NewGrade > 150)
		throw GradeTooLowException();
	else if (NewGrade < 1)
		throw GradeTooHighException();
	this->_grade = NewGrade;
	return ;
}

void				Bureaucrat::incrementGrade(const int &value)
{
	this->setGrade(this->getGrade() - value);
	std::cout << "Successfull Grade increment" << std::endl;
}

void				Bureaucrat::decrementGrade(const int &value)
{
	this->setGrade(this->getGrade() + value);
	std::cout << "Successfull Grade decrement" << std::endl;
}

std::ostream		&operator<<(std::ostream &ostream, const Bureaucrat &rhs)
{
	ostream	<< rhs.getName() << ", bureaucrat grade " << rhs.getGrade()
			<< "." << std::endl;
	return ostream;
}
