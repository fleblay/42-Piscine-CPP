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


	a = Point(0, 0);
	b = Point(0, 3);
	c = Point(3, 0);

	std::cout << "a :" << a << std::endl;
	std::cout << "b :" << b << std::endl;
	std::cout << "c :" << c << std::endl;

	std::cout << Point::bsp(a, b, c, Point(1, 1)) << std::endl;
	std::cout << Point::bsp(a, b, c, Point(0, 0)) << std::endl;
	std::cout << Point::bsp(a, b, c, Point(2, 0)) << std::endl;
	std::cout << Point::bsp(a, b, c, Point(4, 4)) << std::endl;
	return (0);
}
