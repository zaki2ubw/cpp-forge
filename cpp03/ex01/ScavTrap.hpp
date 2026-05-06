/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 19:24:18 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/06 18:16:22 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "ClapTrap.hpp"

class ScavTrap : Public ClapTrap
{
	public :
		//Constructor&Destructor
		ScavTrap();
		explicit ScavTrap(const std::string& name);
		ScavTrap(const ClapTrap& src);
		~ScavTrap();

		//Overlode Operator
		ScavTrap&		operator=(const ClapTrap& src);

		//OverRide Functions
		virtual void	attack(const std::string& target);
		virtual void	takeDamage(unsigned int amount);
		virtual void	beRepaired(unsigned int amount);

		//ScavTrap Additional Functions
		void			guardGate();

	private :
};
