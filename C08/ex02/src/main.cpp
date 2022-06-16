#include "MutantStack.hpp"
#include <cstdio>

int main(void)
{
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	DEBUG && std::cout << "\x1b[33mfirst element is : \x1b[0m" << mstack.top() << std::endl;
	mstack.pop();

	std::cout << "the stack size is now : " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	mstack.push(42);
	mstack.push(-42);
	mstack.push(1024);
	mstack.push(256);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "Now displaying full mutant stack" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	MutantStack<int>	copystack(mstack);	
	MutantStack<int>	copystack2;	

	copystack2 = mstack;

	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	std::cout << "Now REVERSE displaying full mutant stack copy" << std::endl;
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}
	return (0);
}
