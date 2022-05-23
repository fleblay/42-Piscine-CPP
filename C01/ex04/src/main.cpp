#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int	main(int ac, char *av[])
{
	std::string			arg[3];
	std::ifstream		ifs;
	std::stringstream	buf;
	std::string			outfile;
	std::string			input;
	std::size_t			pos_next_to_replace;
	std::size_t			offset = 0;
	std::size_t			count = 0;

	if (ac != 4)
	{
		std::cout	<< "Wrong arg count" << std::endl;
		return (1);
	}
	for (std::size_t i = 0; i < 3; i++)
	{
		arg[i] = av[i + 1];
		if (!arg[i].size())
		{
			std::cout	<< "Arg[" << i + 1 << "] is empty" << std::endl;
			return (1);
		}
	}
	outfile = arg[0] + ".replace";
	ifs.open(arg[0].c_str(), std::ifstream::in);
	if (!ifs.good())
	{
		std::cout	<< "Error opening file" << std::endl;
		return (1);
	}
	//Retrieve as many char as possible from the stream buffer
	buf << ifs.rdbuf();
	ifs.close();
	if (!buf.good())
	{
		std::cout	<< "Error loading file into temporary string" << std::endl;
		return (1);
	}
	//to access data
	std::cout << arg[1] << std::endl;
	while ((pos_next_to_replace = buf.str().find(arg[1], offset)) != std::string::npos)
	{
		count++;
		std::cout << "next post : " << pos_next_to_replace << std::endl;
		/*
		buf.str().erase(pos_next_to_replace, arg[1].size());
		buf.str().insert(pos_next_to_replace, arg[2]);
		offset = pos_next_to_replace + arg[2].size();
		*/
		offset = pos_next_to_replace + arg[1].size();
		std::cout << "offset :" << offset << std::endl;
	}
	std::cout << count << std::endl;
	std::cout << buf.str();
	return (0);
}
