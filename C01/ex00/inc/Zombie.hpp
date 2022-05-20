#ifndef ZOMBIE_CLASS_H
# define ZOMBIE_CLASS_H

#include <string>

class Zombie {

	public :

	Zombie(std::string name);
	~Zombie(void);

	void		announce(void);
	static		Zombie	*newZombie(std::string name);
	static void	randomChump(std::string name);

	private :

	std::string	_name;
};

#endif
