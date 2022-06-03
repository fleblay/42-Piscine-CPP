#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

#include "ICharacter.hpp"
#include "Character.hpp"

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

#include <iostream>

int	main(void)
{
	IMateriaSource* src = new MateriaSource();
	AMateria *ice1 = new Ice();
	AMateria *cure1 = new Cure();
	src->learnMateria(ice1);
	src->learnMateria(cure1);
	src->learnMateria(NULL);
	src->learnMateria(cure1);
	src->learnMateria(cure1);
	src->learnMateria(cure1);
	src->learnMateria(cure1);

	ICharacter* me = new Character("me");

	AMateria *tmp1, *tmp2, *tmp3;
	tmp1 = src->createMateria("ice");
	me->equip(tmp1);
	tmp2 = src->createMateria("cure");
	me->equip(tmp2);
	tmp3 = src->createMateria("Toto");
	me->equip(tmp2);
	me->equip(tmp1);
	me->equip(tmp1);
	me->equip(tmp1);
	me->equip(tmp1);
	me->unequip(9);
	me->unequip(2);
	me->equip(tmp2);
	me->equip(tmp2);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);

	delete src;

	delete bob;
	delete me;

	delete ice1;
	delete cure1;
	delete tmp1;
	delete tmp2;

	return (0);
}
