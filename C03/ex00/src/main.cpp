#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	NoName;
	ClapTrap	Bobby("Bobby");
	ClapTrap	BobbyClone(Bobby);
	ClapTrap	BobbyClone2;
	ClapTrap	Enemy1("Scaring Enemy");

	BobbyClone2 = Bobby;

	Enemy1.attack("Bobby");
	Bobby.takeDamage(5);
	Bobby.beRepaired(2);
	Bobby.beRepaired(8);
	Bobby.attack("Scaring Enemy");
	Bobby.takeDamage(11);
	Bobby.beRepaired(2);
	Bobby.attack("Scaring Enemy");
	Bobby.takeDamage(1);
	return (0);
}
