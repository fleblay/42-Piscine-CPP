#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(void) : _name("DefaultBureaucratName"), _grade(150)
{
	std::cout << "Bureaucrat Default Constructor called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src.getName())
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
	this->_grade = NewGrade;
	return ;
}

std::ostream		&operator<<(std::ostream &ostream, const Bureaucrat &rhs)
{
	ostream	<< rhs.getName() << ", bureaucrat grade " << rhs.getGrade()
			<< "." << std::endl;
	return ostream;
}
