#include "FragTrap.hpp"

int main(void)
{
	FragTrap	NoName;
	FragTrap	Bobby("Bobby");
	FragTrap	BobbyClone(Bobby);
	FragTrap	BobbyClone2;
	FragTrap	Enemy1("Scaring Enemy");

	BobbyClone2 = Bobby;

	Enemy1.attack("Bobby");
	Bobby.highFiveGuys();
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
