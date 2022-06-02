#ifndef DOG_CLASS_H
# define  DOG_CLASS_H

# include "Animal.hpp"
# include "Brain.hpp"
# include <string>

# define GREEN "\x1b[32m"
# define RESET "\x1b[0m"

class Dog : public Animal
{
	public	:	

	Dog(void);
	Dog(const Dog &src);
	~Dog(void);

	Dog	&operator=(const Dog &rhs);

	const std::string	&getIdea(int thoughtNumber) const;

	virtual void	makeSound(void) const;

	private	:

	Brain	*_Brain;
};

#endif
