/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:22:43 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/09 11:24:55 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap	Ancestor("OldTrap");
	ScavTrap	Father("Deffender");
	FragTrap	Mother("Fragmenter");
	DiamondTrap	baby("LatestTrap");

	std::string	target = "CL4P-TP";
	Ancestor.attack(target);
	Father.attack(target);
	Mother.attack(target);
	baby.attack(target);
	baby.whoAmI();
}
