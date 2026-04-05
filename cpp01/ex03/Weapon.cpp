/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 18:43:04 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/04/05 19:08:37 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weaponType)
{
	type = weaponType;
}

Weapon::~Weapon
{
}

void	Weapon::setType(std::string param)
{
	type = param;
	return ;
}

const std::string&	Weapon::getType(void) const
{
	return (type);
}
