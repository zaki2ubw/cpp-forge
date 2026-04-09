/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 19:01:42 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/04/09 23:19:12 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"
#include <iostream>

class HumanA
{
	public :
		HumanA(std::string name, Weapon& weaponREF);
		~HumanA();
		void	attack(void);

	private :
		Weapon&			myWeapon;
		std::string		myName;
} ;
