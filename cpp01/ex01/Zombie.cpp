/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 17:20:20 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/04/05 11:35:58 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	const std::string	msg = "[CONSTRUCT]: Zombie sponed.";

	std::cout << msg << std::endl;
}

Zombie::~Zombie()
{
	const std::string	prefix = "[DESTRUCT]: ";
	const std::string	msg = " returned to his grave.";

	std::cout << prefix << zombieName << msg << std::endl;
}

void	Zombie::announce(void) const
{
	const std::string	greeting = ": BraiiiiiiinnnzzzZ...";

	std::cout << zombieName << greeting << std::endl;
	return ;
}

void	Zombie::setName(std::string name)
{
	zombieName = name;
	return ;
}
