#ifndef ICE_H
# define ICE_H

# include "AMateria.hpp"

#include <string>

class Ice : public AMateria
{
	public	:

	Ice(void);
	Ice(const Ice &src);
	~Ice(void);

	Ice			&operator=(const Ice &rhs);

	virtual AMateria	*clone(void) const;
	virtual void		use(ICharacter &target);
	
};

#endif

