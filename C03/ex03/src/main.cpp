#include "DiamondTrap.hpp"
#include <iostream>

int main(void)
{
	DiamondTrap	NoName;

	NoName.whoAmI();

	std::cout << "Initial HP : " << NoName.getHitPointsInit() << std::endl;
	std::cout << "HP : " << NoName.getHitPoints() << std::endl;
	std::cout << "EP : " << NoName.getEnergyPoints() << std::endl;
	std::cout << "DMG : " << NoName.getAttackDamage() << std::endl;

	DiamondTrap	Named("Bobby-Joe");

	Named.whoAmI();

	std::cout << "Initial HP : " << Named.getHitPointsInit() << std::endl;
	std::cout << "HP : " << Named.getHitPoints() << std::endl;
	std::cout << "EP : " << Named.getEnergyPoints() << std::endl;
	std::cout << "DMG : " << Named.getAttackDamage() << std::endl;

	DiamondTrap	Noname2 = Named;

	Noname2.whoAmI();

	std::cout << "Initial HP : " << Noname2.getHitPointsInit() << std::endl;
	std::cout << "HP : " << Noname2.getHitPoints() << std::endl;
	std::cout << "EP : " << Noname2.getEnergyPoints() << std::endl;
	std::cout << "DMG : " << Noname2.getAttackDamage() << std::endl;

	Noname2.attack("A random ennemy");
	Noname2.guardGate();
	Noname2.highFiveGuys();
	return (0);
}
