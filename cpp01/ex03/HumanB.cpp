/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 00:32:59 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/04/09 23:22:12 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
	: myWeapon(NULL), myName(name)
{
}

HumanB::~HumanB()
{
}

void	HumanB::attack()
{
	std::string	msg = " attacks with their ";

	if (myWeapon == NULL)
	{
		std::cout << myName << " has No Weapon, can't attack." << std::endl;
		return ;
	}
	std::cout << myName << msg << myWeapon->getType() << std::endl;
	return ;
}

void	HumanB::setWeapon(Weapon& weaponREF)
{
	myWeapon = &weaponREF;
	return ;
}
