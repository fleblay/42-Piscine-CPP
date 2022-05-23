#ifndef WEAPON_CLASS_H
# define WEAPON_CLASS_H

#include <string>

class Weapon {

	public	:

	Weapon(std::string new_type);
	~Weapon(void);

	const std::string	&getType(void) const;
	void				setType(std::string new_type);

	private	:

	std::string	_type;

};
#endif
