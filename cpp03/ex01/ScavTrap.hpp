/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 19:24:18 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/05 20:25:41 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>

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

		//function
		std::string		getName() const;
		unsigned int	getCurrentHp() const;
		unsigned int	getCurrentEp() const;
		unsigned int	getCurrentDmg() const;
		void			attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		void			showStatus() const;

		//ScavTrap
		void			guardGate();

	private :
		std::string		name_;
		unsigned int	hitPoint_;
		unsigned int	energyPoint_;
		unsigned int	damage_;
};
