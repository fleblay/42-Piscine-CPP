#ifndef ZOMBIE_CLASS_H
# define ZOMBIE_CLASS_H

#include <string>

class Zombie {

	public :

	Zombie(std::string name);
	Zombie(void);
	~Zombie(void);

	void			announce(void);
	void			setName(std::string name);

	static			Zombie	*newZombie(std::string name);
	static void		randomChump(std::string name);
	static Zombie	*zombieHorde(int N, std::string name);

	private :

	std::string	_name;
};

#endif
