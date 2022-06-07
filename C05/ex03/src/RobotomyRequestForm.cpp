#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : Form("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : Form(src), _target(src._target)
{
	std::cout << "RobotomyRequestForm Copy Constructor called" << std::endl;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm Default Destructor called" << std::endl;
	return ;
}

const std::string				&RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);

}
RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	std::cout << "RobotomyRequestForm Assign operator overload called" << std::endl;
	*((Form *)this) = (const Form &)rhs;
	this->_target = rhs._target;
	return (*this);
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getGradeToBeExecuted())
		throw GradeTooLowException();
	if (!this->getSignedStatus())
		throw FormNotSignedException();
	if (rand() % 2)
	{
		std::cout	<< "Bzzzzzzzzzzzzzzzzzzzzzzz. " << this->_target
					<< " has been successfully robotomized." << std::endl;
	}
	else
		std::cout	<< "Bzzzzzzzzzzzzzzzzzzzzzzz. Operation failed" << std::endl;
	return ;
}
