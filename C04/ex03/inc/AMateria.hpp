#ifndef AMATERIA_CLASS_H
# define AMATERIA_CLASS_H

#include <string>

class AMateria
{
	public	:

	AMateria(void);
	AMateria(const std::string &type);
	AMateria(const AMateria &src);
	virtual ~AMateria(void);

	AMateria			&operator=(const AMateria &rhs);

	const std::string	&getType(void) const;

	virtual AMateria	*clone(void) const = 0;
	virtual void		use(ICharacter &target);
	
	protected	:

	std::string	_type;
};

#endif
