#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : Form("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm Default Constructor called" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : Form(src), _target(src._target)
{
	std::cout << "PresidentialPardonForm Copy Constructor called" << std::endl;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm Default Destructor called" << std::endl;
	return ;
}

const std::string				&PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);

}
PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	std::cout << "PresidentialPardonForm Assign operator overload called" << std::endl;
	*((Form *)this) = (const Form &)rhs;
	this->_target = rhs._target;
	return (*this);
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getGradeToBeExecuted())
		throw GradeTooLowException();
	if (!this->getSignedStatus())
		throw FormNotSignedException();
	std::cout	<< this->_target
				<< " has been pardonned by Zaphod Beeblebrox" << std::endl;
	return ;
}
