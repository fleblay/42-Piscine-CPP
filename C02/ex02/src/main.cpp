#include "Fixed.hpp"
#include <iostream>


int	main(void)
{
	Fixed	a;
	Fixed	b(a);
	Fixed	c(5);
	Fixed	d(2.40f);
	Fixed	e;

	e = c * d;
	std::cout << "test 1" << std::endl << e << std::endl;
	std::cout << "test 2" << std::endl << e++ << std::endl;
	std::cout << "test 3" << std::endl << e << std::endl;
	std::cout << "test 4" << std::endl << --e << std::endl;
	std::cout << "test 5" << std::endl << e << std::endl;
	std::cout << "test 6" << std::endl << e-- << std::endl;
	std::cout << "test 7" << std::endl << e << std::endl;

	Fixed f = c / Fixed(5);
	std::cout << f << std::endl;

	std::cout << Fixed::min(c, Fixed(6)) << std::endl;

	return (0);
}

/*
int	main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;

	return (0);
}
*/
