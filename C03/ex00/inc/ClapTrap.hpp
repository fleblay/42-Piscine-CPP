#ifndef CLAPTRAP_CLASS_H
# define CLAPTRAP_CLASS_H

#include <string>

class ClapTrap
{
	public	:

	ClapTrap(void);
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap &src);
	~ClapTrap(void);

	std::string		getName(void) const;
	unsigned int	getHitPoints(void) const;
	unsigned int	getEnergyPoints(void) const;
	unsigned int	getAttackDamage(void) const;
	unsigned int	getHitPointsInit(void) const;

	ClapTrap &operator=(const ClapTrap &rhs);

	bool	canDoAction(const std::string &action_name) const;
	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	private	:

	std::string			_Name;
	unsigned int		_HitPoints;
	unsigned int		_EnergyPoints;
	unsigned int		_AttackDamage;
	unsigned int		_HitPointsInit;
};

#endif
