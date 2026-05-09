/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 19:24:18 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/09 10:07:34 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public :
		//Constructor&Destructor
		ScavTrap();
		explicit ScavTrap(const std::string& name);
		explicit ScavTrap(const std::string& name,
						  unsigned int hp,
						  unsigned int ep,
						  unsigned int dmg);
		ScavTrap(const ScavTrap& src);
		~ScavTrap();

		//Overlode Operator
		ScavTrap&		operator=(const ScavTrap& src);

		//OverRide Functions
		virtual void	attack(const std::string& target);

		//ScavTrap Additional Functions
		void			guardGate();

	private :
};
