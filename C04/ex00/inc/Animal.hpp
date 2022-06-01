#ifndef ANIMAL_CLASS_H
# define ANIMAL_CLASS_H

# include <string>

class Animal
{
	public	:	

	Animal(void);
	Animal(const std::string &type);
	Animal(const Animal &src);
	~Animal(void);

	const std::string	&getType(void)const;
	
	Animal	&operator=(const Animal &rhs);

	virtual void	makeSound(void) const;

	protected	:

	std::string	_type;
};

#endif
