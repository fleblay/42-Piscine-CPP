#include "WrongAnimal.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include <iostream>


int main(void)
{
	std::cout << "------------------NORMAL PART -------------------------" << std::endl;

	Animal	NoName;
	Animal	Named("Random_Animal");
	Animal	Copy(Named);

	NoName.getType();
	NoName.makeSound();
	Named.getType();
	Named.makeSound();
	Copy.getType();
	Copy.makeSound();

	Cat		UnnamedCat;
	Cat		CopyCat(UnnamedCat);

	UnnamedCat.getType();
	UnnamedCat.makeSound();
	CopyCat.getType();
	CopyCat.makeSound();


	Dog		UnnamedDog;
	Dog		CopyDog(UnnamedDog);

	UnnamedDog.getType();
	UnnamedDog.makeSound();
	CopyDog.getType();
	CopyDog.makeSound();

	//Wrong Part
	std::cout << "------------------WRONG PART -------------------------" << std::endl;

	WrongAnimal	WNoName;
	WrongAnimal	WNamed("Wrong_Random_Animal");
	WrongAnimal	WCopy(WNamed);

	WNoName.getType();
	WNoName.makeSound();
	WNamed.getType();
	WNamed.makeSound();
	WCopy.getType();
	WCopy.makeSound();

	WrongCat	WUnnamedCat;
	WrongCat	WCopyCat(WUnnamedCat);

	WUnnamedCat.getType();
	WUnnamedCat.makeSound();
	WCopyCat.getType();
	WCopyCat.makeSound();


	//Pointer Type
	std::cout << "------------------POINTER PART -------------------------" << std::endl;

	Animal	*AnimalPTR = new Dog();
	Animal	*AnimalPTR2 = new Cat();
	WrongAnimal	*WrongAnimalPTR = new WrongCat();

	AnimalPTR->makeSound();
	AnimalPTR2->makeSound();
	WrongAnimalPTR->makeSound();

	delete AnimalPTR;
	delete AnimalPTR2;
	delete WrongAnimalPTR;
}

/*
int	main(void)
{
	const Animal*	meta = new Animal();
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	return (0);
}
*/
