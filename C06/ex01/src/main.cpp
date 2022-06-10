#include "Data.hpp"
#include <iostream>
#include <stdint.h>

uintptr_t	serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data		*deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int	main(void)
{
	struct Data	my_data = {42, -42};

	std::cout	<< "Value of &my_data : " << &my_data	<< std::endl;
	std::cout	<< "Value of serialize(&my_data) : " << serialize(&my_data)	<< std::endl;
	std::cout	<< "Value of deserialize(serialize(&my_data)) : "
				<< deserialize(serialize(&my_data))	<< std::endl;
	std::cout	<< deserialize(serialize(&my_data))->value1 << std::endl;
	std::cout	<< deserialize(serialize(&my_data))->value2 << std::endl;

	return (0);
}
