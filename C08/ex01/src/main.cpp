#include "Span.hpp"
#include <ctime>
#include <cstdlib>
#include <climits>

int main(void)
{
	Span	mySpan(10);

	mySpan.addNumber(20);
	mySpan.addNumber(50);
	mySpan.addNumber(100);
	mySpan.addNumber(-100);

	std::cout << "longest span : " << mySpan.longestSpan() << std::endl;
	std::cout << "shortest span : " << mySpan.shortestSpan() << std::endl;

	std::cout << mySpan;

	std::cout << "------------------------------------" << std::endl;
	std::vector<int>	v(50, 10);
	mySpan.fillSpan(v.begin(), v.begin() + 5);

	std::cout << mySpan;
	std::cout << "------------------------------------" << std::endl;
	try
	{
		mySpan.fillSpan(v.begin(), v.begin() + 20);
	}
	catch (std::exception &e)
	{
		std::cout << "Failled because : " << e.what() << std::endl;

	}


	srand(time(NULL));

	Span	myRandomSpan(20000);
	int		to_add;
	for (int i = 0; i < 20000; ++i)
	{
		to_add = rand() % INT_MAX;
		i % 2 ? myRandomSpan.addNumber(to_add) : myRandomSpan.addNumber(to_add * (-1));
	}

	std::cout << "longest span : " << myRandomSpan.longestSpan() << std::endl;
	std::cout << "shortest span : " << myRandomSpan.shortestSpan() << std::endl;

	//std::cout << myRandomSpan;

	return (0);
}

/*
int main()
{
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
return 0;
}
*/
