/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 18:36:02 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/04/09 23:26:19 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Weapon
{
	public :
		Weapon(std::string weaponType);
		~Weapon();
		void				setType(const std::string& param);
		const std::string&	getType(void) const;

	private :
		std::string	type;
};
