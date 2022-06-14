#include "Span.hpp"

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

	std::vector<int>	v(
	mySpan.fillSpan(

	return (0);
}
