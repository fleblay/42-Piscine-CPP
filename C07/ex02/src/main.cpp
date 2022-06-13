#include <Array.hpp>
#include <iostream>

int	main(void)
{
	int	*a = new int();

	std::cout << *a << std::endl;
	delete a;

	Array<int>	tab(8);
	tab[6] = 42;
	std::cout << tab;

	Array<int>	tab2(4);
	std::cout << tab2;

	tab2 = tab;
	tab2[3] = 21;

	std::cout << "tab" << std::endl;
	std::cout << tab;
	std::cout << "tab2" << std::endl;
	std::cout << tab2;

	Array<int>	tab_copy(tab2);
	Array<int>	tab_copy2;

	std::cout << tab_copy2;

	tab_copy2 = tab2;

	std::cout << "tab_copy" << std::endl;
	std::cout << tab_copy;

	std::cout << "tab_copy2" << std::endl;
	std::cout << tab_copy;

	try
	{
		tab[20] = 28;
		std::cout << "this should not print" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "an error occured : " << e.what() << std::endl;
	}
	return (0);
}
/*
#include <iostream>
#include <Array.hpp>
#include <time.h>
#include <cstdlib>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}
*/
