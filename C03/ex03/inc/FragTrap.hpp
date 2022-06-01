#ifndef FRAGTRAP_CLASS_H
# define FRAGTRAP_CLASS_H

# include "ClapTrap.hpp"
# include <string>

# define GREEN "\x1b[32m"
# define RESET "\x1b[0m"

class FragTrap : virtual public ClapTrap
{
	public	:

	FragTrap(void);
	FragTrap(const std::string &name);
	FragTrap(const FragTrap &src);
	~FragTrap(void);

	FragTrap	&operator=(const FragTrap &rhs);

	void	highFiveGuys(void);

	protected	:

	static unsigned	int	_FragTrapHitPoints;
	static unsigned	int	_FragTrapEnergyPoints;
	static unsigned	int	_FragTrapAttackDamage;
};
#endif
