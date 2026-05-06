/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 13:17:44 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/06 18:26:14 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>

class ClapTrap
{
	public :
		//Constructor&Destructor
		ClapTrap();
		explicit ClapTrap(const std::string& name,
						  unsigned int hp,
						  unsigned int ep,
						  unsigned int dmg);
		ClapTrap(const ClapTrap& src);
		~ClapTrap();

		//Overlode Operator
		ClapTrap&		operator=(const ClapTrap& src);

		//Functions
		std::string		getName() const;
		unsigned int	getCurrentHp() const;
		unsigned int	getCurrentEp() const;
		unsigned int	getCurrentDmg() const;
		void			showStatus() const;

		//Virtual Functions
		virtual void	attack(const std::string& target);
		virtual void	takeDamage(unsigned int amount);
		virtual void	beRepaired(unsigned int amount);

	private :
		std::string		name_;
		unsigned int	hitPoint_;
		unsigned int	energyPoint_;
		unsigned int	damage_;
};
