#ifndef CURE_H
# define CURE_H

# include <string>
# include "AMateria.hpp"

class ICharacter;

class Cure : public AMateria
{
	public	:

	Cure(void);
	Cure(const Cure &src);
	~Cure(void);

	Cure			&operator=(const Cure &rhs);

	virtual AMateria	*clone(void) const;
	virtual void		use(ICharacter &target);
	
};

#endif
