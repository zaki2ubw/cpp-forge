/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:22:43 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/06 22:42:06 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	a;
	const std::string	onlyName = "FragMan";
	FragTrap	b(onlyName);
	const std::string	setAllStatus = "FriendlyMonster";
	unsigned int		hp = 1000;
	unsigned int		ep = 500;
	unsigned int		dmg = 10000;
	FragTrap	c(setAllStatus, hp, ep, dmg);
	FragTrap	d(c);
	hp = 20;
	ep = 10;
	dmg = 0;
	ClapTrap	e("CL4P-TP", hp, ep, dmg);
	hp = 200;
	ep = 100;
	dmg = 50;
	ScavTrap	f("Deffender", hp, ep, dmg);
	const std::string	target = "HighFiveDoll";
	a.attack(target);
	a.takeDamage(10);
	a.beRepaired(10);
	b.attack(target);
	b.takeDamage(10);
	b.beRepaired(10);
	c.attack(target);
	c.takeDamage(10);
	c.beRepaired(10);
	d.attack(target);
	d.takeDamage(10);
	d.attack(target);
	e.takeDamage(10);
	e.beRepaired(10);
	e.beRepaired(10);
	f.attack(target);
	f.takeDamage(10);
	f.beRepaired(10);
	for (int i = 0; i < 10; ++i)
		a.attack(target);
	a.takeDamage(420);
	b.takeDamage(420);
	c.takeDamage(420);
	d.takeDamage(420);
	e.takeDamage(420);
	f.takeDamage(420);
	a.highFiveGuys();
	b.highFiveGuys();
	c.highFiveGuys();
	d.highFiveGuys();
	f.guardGate();
	return 0;
}
