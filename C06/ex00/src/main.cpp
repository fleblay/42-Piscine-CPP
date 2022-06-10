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
	char		Char;
	int			Int;
	long int	LongInt;
	float		Float;
	double		Double;
	int			Int_ov_underflow = 0;
	int			Char_ov_underflow = 0;
	std::string	str_arg(arg);

	if (type == INT)
	{
		LongInt = strtol(str_arg.c_str(), NULL, 10);
		if (errno == ERANGE
			|| LongInt > static_cast<long int>(INT_MAX)
			|| LongInt < static_cast<long int>(INT_MIN))
		{
			std::cout << "Overflow or Underflow detected" << std::endl;
			return ;
		}
		Int = static_cast<int>(LongInt);
		if (Int > static_cast<int>(CHAR_MAX)
			|| Int < static_cast<int>(CHAR_MIN))
			Char_ov_underflow = 1;
		else
			Char = static_cast<char>(Int);
		Float = static_cast<float>(Int);
		Double = static_cast<double>(Int);
	}
	else if (type == DOUBLE)
	{
		Double = strtod(str_arg.c_str(), NULL);
		if (str_arg == "-inf" || str_arg == "+inf" || str_arg == "nan")
		{
			Int_ov_underflow = 2;
			Char_ov_underflow = 2;
		}
		else
		{
			if (errno == ERANGE
				|| Double > static_cast<double>(INT_MAX)
				|| Double < static_cast<double>(INT_MIN))
				Int_ov_underflow = 1;
			if (Double > static_cast<double>(CHAR_MAX)
				|| Double < static_cast<double>(CHAR_MIN))
				Char_ov_underflow = 1;
		}
		Char = static_cast<char>(Double);
		Float = static_cast<float>(Double);
		Int = static_cast<int>(Double);
	}
	else if (type == FLOAT)
	{
		Float = strtof(str_arg.c_str(), NULL);
		if (str_arg == "-inff" || str_arg == "+inff" || str_arg == "nanf")
		{
			Int_ov_underflow = 2;
			Char_ov_underflow = 2;
		}
		else
		{
			if (Float > static_cast<float>(CHAR_MAX)
				|| Float < static_cast<float>(CHAR_MIN))
				Char_ov_underflow = 1;
			if (errno == ERANGE
				|| Float > static_cast<float>(INT_MAX)
				|| Float < static_cast<float>(INT_MIN))
				Int_ov_underflow = 1;
		}
		Char = static_cast<char>(Float);
		Double = static_cast<double>(Float);
		Int = static_cast<int>(Float);
	}
	else
	{
		Char = str_arg.c_str()[0];
		Float = static_cast<float>(Char);
		Double = static_cast<double>(Char);
		Int = static_cast<int>(Char);
	}
	//print char
	if (!Char_ov_underflow && isprint(Char))
		std::cout	<< "char: '" << Char << "'" << std::endl;
	else if (!Char_ov_underflow && !isprint(Char))
		std::cout	<< "char: Non displayable" << std::endl;
	else if (Char_ov_underflow == 1)
		std::cout	<< "char: over/underflow" << std::endl;
	else if (Char_ov_underflow == 2)
		std::cout	<< "char: impossible" << std::endl;

	//print int
	if (!Int_ov_underflow)
		std::cout	<< "int: " << Int << std::endl;
	else if (Int_ov_underflow == 1)
		std::cout	<< "int: over/underflow" << std::endl;
	else if (Int_ov_underflow == 2)
		std::cout	<< "int: impossible" << std::endl;
	//print others
	std::cout	<< "float: " << std::fixed << std::setprecision(1)
				<< Float << "f" << std::endl
				<< "double: " << Double << std::endl;
}

int	main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cout << "Wrong arg count!" << std::endl;
		return (1);
	}
	int	type = get_type(av[1]);
	if (type == ERROR)
		return (1);
	else
		display(type, av[1]);
	return (0);
}
