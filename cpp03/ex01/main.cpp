/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:22:43 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/04 18:16:46 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap a;
	ClapTrap b("CL4P-TP");
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
