/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 18:36:02 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/04/08 01:02:42 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Weapon
{
	public :
		Weapon(std::string weaponType);
		~Weapon();
		void				Weapon::setType(std::string param);
		const std::string&	getType(void) const;

	private :
		std::string	type;
};
