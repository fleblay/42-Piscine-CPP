#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap	NoName;
	ScavTrap	Bobby("Bobby");
	ScavTrap	BobbyClone(Bobby);
	ScavTrap	BobbyClone2;
	ScavTrap	Enemy1("Scaring Enemy");

	BobbyClone2 = Bobby;

	Enemy1.attack("Bobby");
	Bobby.guardGate();
	Bobby.takeDamage(50);
	Bobby.beRepaired(20);
	Bobby.beRepaired(80);
	Bobby.attack("Scaring Enemy");
	Bobby.takeDamage(100);
	Bobby.beRepaired(2);
	Bobby.attack("Scaring Enemy");
	Bobby.takeDamage(1);

	return (0);
}
