#ifndef ICHARACTER_CLASS_H
# define ICHARACTER_CLASS_H

#include <string>

class ICharacter
{
	public	:

	virtual ~ICharacter(void) {}

	virtual const std::string	&getName() const = 0;
	virtual void				equip(AMateria *m) = 0;
	virtual void				unequip(int idx) = 0;
	virtual void				use(int idx, ICharacter &target) j= 0;

};
#endif
