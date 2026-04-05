/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 14:44:08 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/04/05 15:27:30 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>

int	main(void)
{
	const std::string	askSize = "How many zombies in your horde?";
	const std::string	askName = "What is the name of your Zombies?";
	Zombie*				horde;
	std::string			tmpStr;
	const char*			tmpChar;
	std::string			hordeName;
	int					hordeSize;

	std::cout << askSize << std::endl;
	std::cout << ">";
	if (!getline(std::cin, tmpStr))
		return 1;
	std::cout << std::endl;
	tmpChar = tmpStr.c_str();
	hordeSize = std::atoi(tmpChar);
	std::cout << askName << std::endl;
	std::cout << ">";
	if (!getline(std::cin, hordeName))
		return 1;
	std::cout << std::endl;
	horde = zombieHorde(hordeSize, hordeName);
	if (!horde)
		return 1;
	delete[] horde;
	return 0;
}
