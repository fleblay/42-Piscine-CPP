#include "iter.hpp"
#include <iostream>

int	main(void)
{
	int			tab1[] = {0, 42, -42, 21, -21, 29, 32, 64};
	const char	*tab2[] = {"salut", "hello", "bonsoir", "c'est la fin"};

	//instanciation explicite
	iter<int>(tab1, sizeof(tab1)/sizeof(tab1[0]), printer<int>);
	iter<const char *>(tab2, sizeof(tab2)/sizeof(tab2[0]), printer<const char *>);

	//instanciation implicite
	iter(tab1, sizeof(tab1)/sizeof(tab1[0]), printer);
	iter(tab2, sizeof(tab2)/sizeof(tab2[0]), printer);
	return (0);
}
