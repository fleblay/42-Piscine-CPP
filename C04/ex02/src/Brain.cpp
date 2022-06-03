#include "Brain.hpp"
#include <iostream>

Brain::Brain(void)
{
	std::cout	<< BLUE;
	std::cout	<< "Brain Default Constructor Called" << std::endl;
	std::cout	<< RESET;
	this->setIdeas("DefaultIdea");
	return ;
}

Brain::Brain(const Brain &rhs)
{
	std::cout	<< BLUE;
	std::cout	<< "Brain Copy Constructor Called" << std::endl;
	std::cout	<< RESET;
	*this = rhs;
	return ;
}

Brain::Brain(const std::string &thought)
{
	std::cout	<< BLUE;
	std::cout	<< "Brain Parametric Constructor Called" << std::endl;
	std::cout	<< RESET;
	this->setIdeas(thought);
	return ;
}

Brain::~Brain(void)
{
	std::cout	<< BLUE;
	std::cout	<< "Brain Default Destructor Called" << std::endl;
	std::cout	<< RESET;
	return ;
}

const std::string	*Brain::getIdeas(void) const
{
	return (this->_ideas);
}

void	Brain::setIdeas(const std::string &thought)
{
	for (std::size_t i = 0; i < 100; i++)
	{
		this->_ideas[i] = thought;
	}
	return ;
}

Brain &Brain::operator=(const Brain &rhs)
{
	for (std::size_t i = 0; i < 100; i++)
		this->_ideas[i] = rhs._ideas[i].substr(0);
	return (*this);
}
