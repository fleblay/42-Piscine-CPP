#include "Fixed.hpp"
#include <iostream>


int	main(void)
{
	Fixed	a;
	Fixed	b(a);
	Fixed	c(12);
	Fixed	d(2.08f);


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
