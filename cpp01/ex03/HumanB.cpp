/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 00:32:59 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/04/08 00:42:35 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

HumanB::HumanB(std::string name)
{
	myName = name;
}

HumanB::~HumanB()
{
}

void	HumanB::attack()
{
	std::string	msg = " attacks with their ";

	std::cout << myName << msg << myWeapon.getType() << std::endl;
	return ;
}
