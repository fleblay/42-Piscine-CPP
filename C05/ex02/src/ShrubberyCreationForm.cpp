#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : Form("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : Form(src), _target(src._target)
{
	std::cout << "ShrubberyCreationForm Copy Constructor called" << std::endl;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm Default Destructor called" << std::endl;
	return ;
}

const std::string				&ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);

}
ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	std::cout << "ShrubberyCreationForm Assign operator overload called" << std::endl;
	*((Form *)this) = (const Form &)rhs;
	this->_target = rhs._target;
	return (*this);
}

bool	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	std::ofstream		ofs;
	std::string			fileName;
	std::stringstream	buf;

	if (executor.getGrade() > this->getGradeToBeExecuted())
		throw GradeTooLowException();
	if (!this->getSignedStatus())
		return (0);
	fileName = this->_target + "_shrubbery";
	ofs.open(fileName.c_str(), std::ofstream::out);
	if (!ofs.good())
	{
		std::cout	<< "Error opening output file" << std::endl;
		return (0);
	}
	buf << "       _-_" << std::endl;
	buf << "    /~~   ~~\\" << std::endl;
	buf << " /~~         ~~\\" << std::endl;
	buf << "{               }" << std::endl;
	buf << " \\  _-     -_  /" << std::endl;
	buf << "   ~  \\\\ //  ~" << std::endl;
	buf << "_- -   | | _- _" << std::endl;
	buf << "  _ -  | |   -_" << std::endl;
	buf << "      // \\\\" << std::endl;
	ofs << buf.str();
	if (!ofs.good())
	{
		std::cout	<< "Error writing to output file" << std::endl;
		ofs.close();
		return (0);
	}
	ofs.close();
	std::cout << "OK" << std::endl;
	return (1);
}
