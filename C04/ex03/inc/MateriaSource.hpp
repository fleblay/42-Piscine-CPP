#ifndef MATERIASOURCE_CLASS_H
# define MATERIASOURCE_CLASS_H

# include <string>
# include "IMateriaSource.hpp"

class AMateria;

class MateriaSource : public IMateriaSource
{
	public	:

	MateriaSource(void);
	MateriaSource(const MateriaSource &src);
	virtual ~MateriaSource(void);

	MateriaSource	&operator=(const MateriaSource &rhs);

	virtual void		learnMateria(AMateria *m);	
	virtual AMateria	*createMateria(const std::string &type);

	private	:

	AMateria	*_inventory[4];
};

#endif

