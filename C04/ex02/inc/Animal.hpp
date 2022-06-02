#ifndef ANIMAL_CLASS_H
# define ANIMAL_CLASS_H

# include <string>

class Animal
{
	public	:	

	Animal(void);
	Animal(const std::string &type);
	Animal(const Animal &src);
	virtual ~Animal(void);

	const std::string	&getType(void)const;
	
	Animal	&operator=(const Animal &rhs);

	virtual void	makeSound(void) const = 0;

	protected	:

	std::string	_type;
};

#endif
