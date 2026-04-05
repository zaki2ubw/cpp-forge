/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 19:51:17 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/04/05 20:04:43 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanB
{
	public :
		HumanB(std::string name);
		~HumanB();
		void	attack();
		void	setWeapon(std::string weaponName);

	private :
		Weapon::Weapon*	myWeapon;
		std::string		myName;
}
