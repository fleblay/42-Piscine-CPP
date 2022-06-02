#ifndef WRONGCAT_CLASS_H
# define  WRONGCAT_CLASS_H

# include "WrongAnimal.hpp"
# include <string>

# define ORANGEBOLD "\x1b[1;33m"
# define RESET "\x1b[0m"

class WrongCat : public WrongAnimal
{
	public	:	

	WrongCat(void);
	WrongCat(const WrongCat &src);
	~WrongCat(void);

	WrongCat	&operator=(const WrongCat &rhs);

	virtual void	makeSound(void) const;
};

#endif


