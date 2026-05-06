/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:22:43 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/06 18:28:14 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap a;
	int hp = 10;
	int ep = 10;
	int dmg = 0;
	const std::string	name = "CL4P-TP";
	ClapTrap b(name, hp, ep, dmg);
	ClapTrap c(b);
	const std::string	target = "SANDBAG";
	for (int i = 0; i < 10; ++i)
	{
		a.attack(target);
		a.takeDamage(1);
		a.beRepaired(1);
	}
	b.takeDamage(42);
	b.takeDamage(42);
	return 0;
}
