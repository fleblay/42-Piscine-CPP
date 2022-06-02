#ifndef WRONGANIMAL_CLASS_H
# define WRONGANIMAL_CLASS_H

# include <string>

class WrongAnimal
{
	public	:	

	WrongAnimal(void);
	WrongAnimal(const std::string &type);
	WrongAnimal(const WrongAnimal &src);
	virtual ~WrongAnimal(void);

	const std::string	&getType(void)const;
	
	WrongAnimal	&operator=(const WrongAnimal &rhs);

	void	makeSound(void) const;

	protected	:

	std::string	_type;
};

#endif

