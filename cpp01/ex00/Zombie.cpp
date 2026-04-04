/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 17:20:20 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/04/04 17:44:02 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::void	announce(void) const
{
	const std::string	greeting = ": BraiiiiiiinnnzzzZ...";
	std::cout << zombieName << greeting << std::endl;
	return ;
}

Zombie::void	setName(std::string name)
{
	zombieName = name;
	return ;
}
