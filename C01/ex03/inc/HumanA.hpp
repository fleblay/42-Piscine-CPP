#ifndef HUMANA_CLASS_H
# define HUMANA_CLASS_H

#include "Weapon.hpp"
#include <string>

class HumanA{

	public	:

	HumanA(std::string name, Weapon &weapon);
	~HumanA(void);
	void	attack(void) const;

	private	:

	std::string		_name;
	Weapon			&_weapon;
};

#endif
