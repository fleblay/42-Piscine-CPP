#include "Zombie.hpp"

int	main(void)
{
	Zombie	zombie("Bob");
	Zombie	*zombieptr;

	zombieptr = Zombie::newZombie("John");

	zombie.announce();
	zombieptr->announce();
	delete zombieptr;

	return (0);
}
