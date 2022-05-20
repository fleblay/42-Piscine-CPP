/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:47:19 by fle-blay          #+#    #+#             */
/*   Updated: 2022/05/20 10:04:22 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <locale>
#include <string>

int	main(int ac, char *av[])
{
	std::locale	loc;
	std::string	str;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (*++av)
		{
			str = *av;
			for (std::string::size_type i = 0; i < str.length(); i++)
				std::cout << std::toupper(str[i], loc);
		}
		std::cout << std::endl;
	}
	return (0);
}
