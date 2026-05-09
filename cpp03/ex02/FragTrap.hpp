/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 22:08:28 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/09 12:28:50 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
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

	protected :
		//Default status
		static const std::string	kDefaultName;
		static const unsigned int	kDefaultHp = 100;
		static const unsigned int	kDefaultEp = 100;
		static const unsigned int	kDefaultDmg = 30;

	private :
};
