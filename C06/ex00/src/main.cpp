#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>

# define ERROR 0
# define CHAR 1
# define FLOAT 2
# define DOUBLE 3
# define INT 4

int	get_type(char *arg)
{
	std::string	input = arg;
	std::size_t	f_position = input.find_last_of("f");
	std::size_t	dot_position = input.find_last_of(".");
	std::size_t	minus_position = input.find_last_of("-");
	std::size_t	arg_len = input.length();
	std::size_t	f_position_error = (input.find_first_of("f") != input.find_last_of("f"));
	std::size_t	dot_position_error = input.find_first_of(".") != input.find_last_of(".");
	std::size_t	minus_position_error = input.find_first_of("-") != input.find_last_of("-");
	std::size_t min_correct_len = 1
								+ (minus_position != std::string::npos)
								+ (dot_position != std::string::npos)
								+ (f_position != std::string::npos);
	if (arg_len == 0)
		return (std::cout << "Input is empty!" << std::endl, ERROR);
	for (std::size_t i = 0; i < arg_len; i++)
	{
		if (!isprint(input[i]))
			return (std::cout << "There is a non-printable char!" << std::endl, ERROR);
	}
	//char road
	if (!isdigit(input[0]) && arg_len == 1)
	{
		std::cout << "\x1b[31marg is char\x1b[0m" << std::endl;
		return (CHAR);
	}
	//number road
	if (input[0] == '-' && arg_len > 1 && !isdigit(input[1]) && input[1] != '.')
			return (std::cout << "Wrong negative number format!" << std::endl, ERROR);
	if (input.find_first_not_of("0123456789-f.") != std::string::npos)
		return (std::cout << "Wrong char among number format!" << std::endl, ERROR);
	if (f_position != std::string::npos && f_position != arg_len - 1)
		return (std::cout << "Wrong float sign position!" << std::endl, ERROR);
	if (f_position_error)
		return (std::cout << "Too many float signs!" << std::endl, ERROR);
	if (dot_position_error)
		return (std::cout << "Too many dot signs!" << std::endl, ERROR);
	if (minus_position_error)
		return (std::cout << "Too many minus signs!" << std::endl, ERROR);
	if (minus_position != std::string::npos && minus_position != 0)
		return (std::cout << "Wrong minus sign position!" << std::endl, ERROR);
	if (f_position != std::string::npos && f_position != arg_len - 1)
		return (std::cout << "Wrong float sign position!" << std::endl, ERROR);
	if (arg_len < min_correct_len)
		return (std::cout << "Missing value!" << std::endl, ERROR);

	//return number type
	if (f_position != std::string::npos || input == "-inff" || input == "+inff" || input == "nanf")
	{
		std::cout << "\x1b[32marg is a float\x1b[0m" << std::endl;
		return (FLOAT);
	}
	else if (dot_position != std::string::npos || input == "-inf" || input == "+inf" || input == "nan")
	{
		std::cout << "\x1b[33marg is a double\x1b[0m" << std::endl;
		return (DOUBLE);
	}
	else
	{
		std::cout << "\x1b[34marg is a int\x1b[0m" << std::endl;
		return (INT);
	}
}

int	main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cout << "Wrong arg count!" << std::endl;
		return (1);
	}

	int	type = get_type(av[1]);
	if (type == 0)
		return (1);
	else
		std::cout << "make conversion" << std::endl;
	return (0);
}
