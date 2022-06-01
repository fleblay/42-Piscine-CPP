#ifndef CAT_CLASS_H
# define  CAT_CLASS_H

# include "Animal.hpp"
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

	virtual void	makeSound(void) const;
};

#endif

