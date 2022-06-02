#ifndef CAT_CLASS_H
# define  CAT_CLASS_H

# include "Animal.hpp"
# include "Brain.hpp"
# include <string>

# define ORANGE "\x1b[33m"
# define RESET "\x1b[0m"

class Cat : public Animal
{
	public	:	

	Cat(void);
	Cat(const Cat &src);
	~Cat(void);

	Cat	&operator=(const Cat &rhs);

	const std::string	&getIdea(int thoughtNumber) const;

	virtual void	makeSound(void) const;

	private	:

	Brain	*_Brain;
};

#endif

