/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 09:58:57 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/09 12:28:17 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public :
		//Constructor&Destructor
		DiamondTrap();
		explicit DiamondTrap(const std::string& name);
		DiamondTrap(const DiamondTrap& src);
		~DiamondTrap();

		//Overlode Operator
		DiamondTrap&		operator=(const DiamondTrap& src);

		//OverRide Functions
		virtual void	attack(const std::string& target);

		//DiamondTrap Additional Functions
		void			whoAmI();

	protected :
		static const std::string	kDefaultName;

	private :
		std::string		name_;
};
