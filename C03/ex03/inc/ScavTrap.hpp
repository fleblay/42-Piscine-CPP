#ifndef SCAVTRAP_CLASS_H
# define SCAVTRAP_CLASS_H

# include "ClapTrap.hpp"
# include <string>

# define ORANGE "\x1b[33m"
# define RESET "\x1b[0m"

class ScavTrap : public ClapTrap
{
	public	:

	ScavTrap(void);
	ScavTrap(const std::string &name);
	ScavTrap(const ScavTrap &src);
	~ScavTrap(void);

	ScavTrap	&operator=(const ScavTrap &rhs);

	void	attack(const std::string &target);
	void	guardGate(void);
};
#endif
