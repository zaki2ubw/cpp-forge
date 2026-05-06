/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 22:08:28 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/06 22:39:41 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public :
		//Constructor&Destructor
		FragTrap();
		explicit FragTrap(const std::string& name);
		explicit FragTrap(const std::string& name,
						  unsigned int hp,
						  unsigned int ep,
						  unsigned int dmg);
		FragTrap(const FragTrap& src);
		~FragTrap();

		//Overlode Operator
		FragTrap&		operator=(const FragTrap& src);

		//OverRide Functions
		virtual void	attack(const std::string& target);

		//FragTrap Additional Functions
		void			highFiveGuys();

	private :
};
