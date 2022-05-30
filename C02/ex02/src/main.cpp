#include "Fixed.hpp"
#include <iostream>


int	main(void)
{
	Fixed	a;
	Fixed	b(a);
	Fixed	c(5);
	Fixed	d(2.40f);
	Fixed	e = c * d;
	Fixed	f = c / Fixed(5);
	Fixed	g = c - d;
	Fixed	h = c + d;

	std::cout << "e" << std::endl << e << std::endl;
	std::cout << "e pre inc" << std::endl << ++e << std::endl;
	std::cout << "e" << std::endl << e << std::endl;
	std::cout << "e post inc" << std::endl << e++ << std::endl;
	std::cout << "e" << std::endl << e << std::endl;
	std::cout << "e pre dec" << std::endl << --e << std::endl;
	std::cout << "e" << std::endl << e << std::endl;
	std::cout << "e post dec" << std::endl << e-- << std::endl;
	std::cout << "e" << std::endl << e << std::endl;

	std::cout << "Fixed f = c / Fixed(5)" << std::endl;
	std::cout << f << std::endl;

	std::cout << "Min c et Fixed(6)" << std::endl;
	std::cout << Fixed::min(c, Fixed(6)) << std::endl;

	std::cout << "Max Fixed(10) et Fixed(6)" << std::endl;
	std::cout << Fixed::max(Fixed(10), Fixed(6)) << std::endl;

	std::cout << "g = c - d" << std::endl << g << std::endl;
	std::cout << "h = c + d" << std::endl << h << std::endl;

	std::cout << "a == b" << std::endl << (a == b) << std::endl;
	std::cout << "a != b" << std::endl << (a != b) << std::endl;

	std::cout << "c == Fixed(5)" << std::endl << (c == Fixed(5)) << std::endl;
	std::cout << "c != Fixed(5)" << std::endl << (c != Fixed(5)) << std::endl;

	std::cout << "c == d" << std::endl << (c == d) << std::endl;
	std::cout << "c != d" << std::endl << (c != d) << std::endl;
	std::cout << "c >= d" << std::endl << (c >= d) << std::endl;
	std::cout << "c <= d" << std::endl << (c <= d) << std::endl;
	std::cout << "c > d" << std::endl << (c > d) << std::endl;
	std::cout << "c < d" << std::endl << (c < d) << std::endl;

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
