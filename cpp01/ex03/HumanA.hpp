/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 19:01:42 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/04/05 19:19:42 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanA
{
	public :
		HumanA(std::string name, std::string weaponName);
		~HumanA();
		void	attack(void);

	private :
		Weapon::Weapon	myWeapon;
		std::string		myName;
}
