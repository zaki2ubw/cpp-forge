/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 13:17:44 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/04 18:06:38 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>

class ClapTrap
{
	public :
		//Constructor&Destructor
		ClapTrap();
		explicit ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& src);
		~ClapTrap();

		//Overlode Operator
		ClapTrap&		operator=(const ClapTrap& src);

		//function
		std::string		getName() const;
		unsigned int	getCurrentHp() const;
		unsigned int	getCurrentEp() const;
		unsigned int	getCurrentDmg() const;
		void			attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		void			showStatus() const;
		void			showDeadLog() const;

	private :
		std::string		name_;
		unsigned int	hitPoint_;
		unsigned int	energyPoint_;
		unsigned int	damage_;
};
