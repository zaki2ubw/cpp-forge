/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 19:23:29 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/04/05 19:37:15 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, std::string weaponName)
{
	myName = name;
	myWeapon = Weapon::Weapon(weaponName);
}

HumanA::~HumanA()
{
}

void	HumanA::attack()
{
	std::string	msg = " attacks with their ";

	std::cout << myName << msg << myWeapon.getType() << std::endl;
	return ;
}
