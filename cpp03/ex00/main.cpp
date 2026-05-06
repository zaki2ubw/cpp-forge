/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:22:43 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/06 20:08:21 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap a;
	const std::string	name = "CL4P-TP";
	ClapTrap b(name);
	const std::string	org = "originalTrap";
	int hp = 20;
	int ep = 20;
	int dmg = 20;
	ClapTrap c(org, hp, ep, dmg);
	ClapTrap d(c);
	const std::string	target = "SANDBAG";
	for (int i = 0; i < 10; ++i)
	{
		a.attack(target);
		a.takeDamage(1);
		a.beRepaired(1);
	}
	b.takeDamage(42);
	b.takeDamage(42);
	c.attack(target);
	d.attack(target);
	return 0;
}
