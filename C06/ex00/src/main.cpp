#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cerrno>
#include <limits.h>

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
	std::size_t	plus_position = input.find_last_of("+");
	std::size_t	arg_len = input.length();
	std::size_t	f_position_error = (input.find_first_of("f") != input.find_last_of("f"));
	std::size_t	dot_position_error = input.find_first_of(".") != input.find_last_of(".");
	std::size_t	minus_position_error = input.find_first_of("-") != input.find_last_of("-");
	std::size_t	plus_position_error = input.find_first_of("+") != input.find_last_of("+");
	std::size_t min_correct_len = 1
								+ ((minus_position != std::string::npos) || plus_position != std::string::npos)
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

	//exception road
	if (input == "-inff" || input == "+inff" || input == "nanf")
	{
		std::cout << "\x1b[32marg is a float\x1b[0m" << std::endl;
		return (FLOAT);
	}
	if (input == "-inf" || input == "+inf" || input == "nan")
	{
		std::cout << "\x1b[33marg is a double\x1b[0m" << std::endl;
		return (DOUBLE);
	}

	//number road
	if (input[0] == '-' && arg_len > 1 && !isdigit(input[1]) && input[1] != '.')
			return (std::cout << "Wrong negative number format!" << std::endl, ERROR);
	if (input.find_first_not_of("0123456789-+f.") != std::string::npos)
		return (std::cout << "Wrong char among number format!" << std::endl, ERROR);
	if (f_position != std::string::npos && f_position != arg_len - 1)
		return (std::cout << "Wrong float sign position!" << std::endl, ERROR);
	if (minus_position != std::string::npos && plus_position != std::string::npos)
		return (std::cout << "Too many signs : plus and minus signs!" << std::endl, ERROR);
	if (f_position_error)
		return (std::cout << "Too many float signs!" << std::endl, ERROR);
	if (dot_position_error)
		return (std::cout << "Too many dot signs!" << std::endl, ERROR);
	if (minus_position_error)
		return (std::cout << "Too many minus signs!" << std::endl, ERROR);
	if (plus_position_error)
		return (std::cout << "Too many plus signs!" << std::endl, ERROR);
	if (minus_position != std::string::npos && minus_position != 0)
		return (std::cout << "Wrong minus sign position!" << std::endl, ERROR);
	if (plus_position != std::string::npos && plus_position != 0)
		return (std::cout << "Wrong plus sign position!" << std::endl, ERROR);
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

void	display(int type, char *arg)
{
	char		Char = 0;
	int			Int = 0;
	long int	LongInt = 0;
	float		Float = 0;
	double		Double = 0;

	if (type == INT)
	{
		LongInt = strtol(arg, NULL, 10);
		if (errno == ERANGE || LongInt > INT_MAX || LongInt < INT_MIN)
		{
			std::cout << "Overflow or Underflow detected" << std::endl;
			return ;
		}
		Int = static_cast<int>(LongInt);
		Char = (isprint(Int)) ? static_cast<char>(Int) : 0;
		Float = static_cast<float>(Int);
		Double = static_cast<double>(Int);
	}
	else if (type == DOUBLE)
	{
		//check overflow
		Double = strtod(arg, NULL);
		Char = static_cast<char>(Double);
		Float = static_cast<float>(Double);
		Int = static_cast<int>(Double);
	}
	else if (type == FLOAT)
	{
		//check overflow
		Float = strtof(arg, NULL);
		Char = static_cast<char>(Float);
		Double = static_cast<double>(Float);
		Int = static_cast<int>(Float);
	}
	else if (type == CHAR)
	{
		Char = arg[0];
		Float = static_cast<float>(Char);
		Double = static_cast<double>(Char);
		Int = static_cast<int>(Char);
	}
	if (Char != 0)
		std::cout	<< "char: '" << Char << "'" << std::endl;
	else
		std::cout	<< "Non displayable" << std::endl;
	std::cout	<< "int: " << Int << std::endl
				<< "float: " << std::fixed << std::setprecision(1) << Float << "f" << std::endl
				<< "double: " << Double << std::endl;
}

int	main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cout << "Wrong arg count!" << std::endl;
		return (1);
	}
	std::cout << "size of long int : " << sizeof(long int) << std::endl;
	std::cout << "size of int : " << sizeof(int) << std::endl;
	int	type = get_type(av[1]);
	if (type == ERROR)
		return (1);
	else
		display(type, av[1]);
	return (0);
}
