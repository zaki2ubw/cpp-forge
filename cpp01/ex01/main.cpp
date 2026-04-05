/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 14:44:08 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/04/05 16:41:21 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>

int	main(void)
{
	const std::string	askSize = "How many zombies in your horde?";
	const std::string	askName = "What is the name of your Zombies?";
	Zombie*				horde;
	std::string			hordeName;
	int					hordeSize;
	std::string			tmpStr;
	char*				endptr;

	std::cout << askSize << std::endl << ">";
	if (!getline(std::cin, tmpStr))
		return 1;
	std::cout << std::endl;
	hordeSize = static_cast<int>(std::strtol(tmpStr.c_str(), &endptr, 10));
	if (*endptr != '\0' || hordeSize < 0)
		return 1;
	if (hordeSize == 0)
	{
		std::cout << "No Zombie sponed" << std::endl;
		return 0;
	}
	std::cout << askName << std::endl << ">";
	if (!getline(std::cin, hordeName))
		return 1;
	std::cout << std::endl;
	horde = zombieHorde(hordeSize, hordeName);
	for (int i = 0; i < hordeSize; i++)
		horde[i].announce();
	delete[] horde;
	return 0;
}
