/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:22:43 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/06 20:07:31 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	a;
	const std::string	onlyName = "Scavanger";
	ScavTrap	b(onlyName);
	const std::string	setAllStatus = "Defender";
	unsigned int		hp = 1000;
	unsigned int		ep = 500;
	unsigned int		dmg = 10000;
	ScavTrap	c(setAllStatus, hp, ep, dmg);
	ScavTrap	d(c);
	const std::string	target = "IronDoor";
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
	d.beRepaired(10);
	for (int i = 0; i < 10; ++i)
		a.attack(target);
	a.takeDamage(420);
	b.takeDamage(420);
	c.takeDamage(420);
	d.takeDamage(420);
	a.guardGate();
	b.guardGate();
	c.guardGate();
	d.guardGate();
	return 0;
}
