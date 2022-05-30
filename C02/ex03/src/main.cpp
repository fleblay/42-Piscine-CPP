#include "Point.hpp"
#include <iostream>


int	main(void)
{
	Point	a(3.3f, 5.6f);
	Point	b(a);
	Point	c;
	Point	d = b;

	std::cout << "a :" << a << std::endl;
	std::cout << "b :" << b << std::endl;
	std::cout << "c :" << c << std::endl;
	std::cout << "d :" << d << std::endl;
	return (0);
}
