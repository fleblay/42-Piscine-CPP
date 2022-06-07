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

const char				*ShrubberyCreationForm::OpenFileException::what(void) const throw()
{
	return ("Cannot perform operation : Open file error");
}

const char				*ShrubberyCreationForm::WriteToFileException::what(void) const throw()
{
	return ("Cannot perform operation : Open file error");
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	std::ofstream		ofs;
	std::string			fileName;
	std::stringstream	buf;

	if (executor.getGrade() > this->getGradeToBeExecuted())
		throw GradeTooLowException();
	if (!this->getSignedStatus())
		throw FormNotSignedException();
	fileName = this->_target + "_shrubbery";
	ofs.open(fileName.c_str(), std::ofstream::out);
	if (!ofs.good())
	{
		throw OpenFileException();
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
		ofs.close();
		throw WriteToFileException();
	}
	ofs.close();
	return ;
}
