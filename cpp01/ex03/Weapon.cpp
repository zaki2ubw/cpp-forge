/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 18:43:04 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/04/09 23:26:43 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weaponType)
	: type(weaponType)
{
}

Weapon::~Weapon()
{
}

void	Weapon::setType(const std::string& param)
{
	type = param;
	return ;
}

const std::string&	Weapon::getType(void) const
{
	return (type);
}
