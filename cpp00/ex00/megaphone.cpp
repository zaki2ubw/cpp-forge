/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 15:53:06 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/03/23 15:31:31 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int argc, char **argv)
{
	std::string noinput = "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";

	if (argc <= 1)
	{
		std::cout << noinput;
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		for (int n = 0; argv[i][n] != '\0'; n++)
			std::cout << static_cast<unsigned char>(toupper(argv[i][n]));
	}
	std::cout << std::endl;
	return (0);
}
