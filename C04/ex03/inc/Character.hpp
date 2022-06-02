#ifndef CHARACTER_CLASS_H
# define CHARACTER_CLASS_H

# include "ICharacter.hpp"
# include "AMateria.hpp"

#include <string>

class Character : public ICharacter
{
	public	:

	Character(void);
	Character(const std::string &name);
	Character(const Character &src);
	virtual ~Character(void);

	Character			&operator=(const Character &rhs);

	virtual const std::string	&getName() const;
	virtual void				equip(AMateria *m);
	virtual void				unequip(int idx);
	virtual void				use(int idx, ICharacter &target);

	private	:

	AMateria	*_inventory[4];
	AMateria	*_discarded[256];
	std::string	_name;
};

#endif
