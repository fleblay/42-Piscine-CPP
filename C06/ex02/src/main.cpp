#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

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
}

int	main(void)
{
	srand(time(NULL));

	identify(generate());
	identify(generate());
	identify(generate());
	identify(generate());
	identify(generate());
	identify(generate());
	identify(generate());

	return (0);
}
