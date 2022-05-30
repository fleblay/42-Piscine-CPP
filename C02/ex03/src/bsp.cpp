#include "Point.hpp"
#include <iostream>

bool		Point::bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (a == point || b == point || c == point)
	{
		std::cout << "Le point est confondu avec un des sommets du triangle" << std::endl;
		return (false);
	}
	float areaABC = area(a, b, c);
	float areaABM = area(a, b, point);
	std::cout << "Aire 1er triangle : " << areaABM << std::endl;
	float areaBCM = area(b, c, point);
	std::cout << "Aire 2eme triangle : " << areaBCM << std::endl;
	float areaCAM = area(c, a, point);
	std::cout << "Aire 3eme triangle : " << areaCAM << std::endl;
	float sumAreas = areaABM + areaBCM + areaCAM;

	if (areaABC == sumAreas)
	{
		std::cout << "La somme des aires est egale a celle du triangle principal" << std::endl;
		if (point.isAligned(a, b) || point.isAligned(b, c) || point.isAligned(c, a))
		{
			std::cout << "Mais le point fait partie d'un des cote du triangle" << std::endl;
			return (false);
		}
		else
		{
			std::cout << "Le point est a l'interieur du triangle" << std::endl;
			return (true);
		}
	}
	else
	{
		std::cout << "La somme des aires est differente de celle du triangle principal" << std::endl;
		std::cout << "Somme : " << sumAreas << " | " << "Triangle Principal : " << areaABC << std::endl;
		return (false);
	}
}
