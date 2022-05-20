#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombieHorde;

	zombieHorde = Zombie::zombieHorde(4, "Bobby");
	for (int i = 0; i < 4; i++)
		zombieHorde[i].announce();
	delete [] zombieHorde;
	return (0);
}
