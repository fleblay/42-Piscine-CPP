#ifndef DIAMONDTRAP_CLASS_H
# define DIAMONDTRAP_CLASS_H

# include "ClapTrap.hpp"
# include <string>

# define RED "\x1b[31m"
# define RESET "\x1b[0m"

class DiamondTrap : public ClapTrap
{
	public	:

	DiamondTrap(void);
	DiamondTrap(const std::string &name);
	DiamondTrap(const DiamondTrap &src);
	~DiamondTrap(void);

	DiamondTrap	&operator=(const DiamondTrap &rhs);

	void	whoAmI(void);

	private	:

	std::string	_Name;

};
#endif
