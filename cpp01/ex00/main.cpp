/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 10:40:10 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/04/05 11:34:41 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	const std::string	stack = "Enter the zombie name to spawn in the stack.";
	const std::string	heap = "Enter the zombie name to spawn in the heap.";
	std::string			stackName;
	std::string			heapName;
	Zombie*				z;

	std::cout << stack << std::endl;
	std::cout << ">";
	if (!getline(std::cin, stackName))
		return 1;
	std::cout << std::endl;
	randomChump(stackName);
	std::cout << heap << std::endl;
	std::cout << ">";
	if (!getline(std::cin, heapName))
		return 1;
	std::cout << std::endl;
	z = newZombie(heapName);
	if (!z)
		return 1;
	z->announce();
	delete z;
	return 0;
}
