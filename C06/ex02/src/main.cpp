#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdexcept>

Base	*generate(void)
{
	int	random_number = rand();

	if (random_number % 3 == 0)
		return (new A());
	if (random_number % 3 == 1)
		return (new B());
	else
		return (new C());
}

void	identify(Base *p)
{
	A	*Aptr = dynamic_cast<A *>(p);
	B	*Bptr = dynamic_cast<B *>(p);
	C	*Cptr = dynamic_cast<C *>(p);

	if (Aptr)
		std::cout << "is a A" << std::endl;
	else if (Bptr)
		std::cout << "is a B" << std::endl;
	else if (Cptr)
		std::cout << "is a C" << std::endl;
	else
		std::cout << "is of unknown type" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		A	&Aref = dynamic_cast<A &>(p);
		std::cout << "is a A and address is " << &Aref << std::endl;
	}
	catch (std::exception &bc)
	{
		try
		{
			B	&Bref = dynamic_cast<B &>(p);
			std::cout << "is a B and address is " << &Bref << std::endl;
		}
		catch (std::exception &bc)
		{
			try
			{
				C	&Cref = dynamic_cast<C &>(p);
				std::cout << "is a C and address is " << &Cref << std::endl;
			}
			catch (std::exception &bc)
			{
				std::cout << "is of unknown type" << std::endl;
			}
		}
	}
}

int	main(void)
{
	srand(time(NULL));
	Base	*first, *second, *third;

	first = generate();
	second = generate();
	third = generate();

	identify(first);
	identify(second);
	identify(third);

	identify(*first);
	identify(*second);
	identify(*third);

	return (0);
}
