#include <iostream>
#include <cstdlib>
#include <string>


//Dectect right type with parsing
//convert using strtod etc...
//Use static cast to create other value
//Display

int	main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cout << "Wrong arg count!" << std::endl;
		return (1);
	}

	std::string	input = av[1];

	std::size_t	f_position = input.find_last_of("f");
	std::size_t	dot_position = input.find_last_of(".");
	std::size_t	minus_position = input.find_last_of("-");

	std::size_t	arg_len = input.length();

	std::size_t	f_position_error = input.find_first_of("f") != input.find_last_of("f");
	std::size_t	dot_position_error = input.find_first_of(".") != input.find_last_of(".");
	std::size_t	minus_position_error = input.find_first_of("-") != input.find_last_of("-");

	std::size_t min_correct_len = 1
								+ (minus_position != std::string::npos)
								+ (dot_position != std::string::npos)
								+ (f_position != std::string::npos);
	//fx to check que des chars ou que des digits	
	if (arg_len == 0)
	{
		std::cout << "Input is empty!" << std::endl;
		return (1);
	}
	if (f_position_error)
	{
		std::cout << "Too many float signs!" << std::endl;
		return (1);
	}
	if (dot_position_error)
	{
		std::cout << "Too many dot signs!" << std::endl;
		return (1);
	}
	if (minus_position_error)
	{
		std::cout << "Too many minus signs!" << std::endl;
		return (1);
	}
	if (minus_position != std::string::npos && minus_position != 0)
	{
		std::cout << "Wrong minus sign position!" << std::endl;
		return (1);
	}
	if (f_position != std::string::npos && f_position != arg_len - 1)
	{
		std::cout << "Wrong float sign position!" << std::endl;
		return (1);
	}
	if (arg_len < min_correct_len)
	{
		std::cout << "Missing value!" << std::endl;
		return (1);
	}
	std::cout	<< "f_position : " << f_position << std::endl
				<< "dot_position : " << dot_position << std::endl
				<< "arg_len : " << arg_len << std::endl
				<< "min_correct_len : " << min_correct_len << std::endl;

	if (f_position == arg_len - 1
		&& ((dot_position < f_position && arg_len > 2)
		|| (dot_position == std::string::npos && arg_len > 1)))
	{
		std::cout << "arg is a float" << std::endl;
	}

	std::cout << -4.f << std::endl;
	return (0);
}
