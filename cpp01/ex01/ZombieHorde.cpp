/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 14:28:23 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/04/05 15:38:38 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie*	zombieArray = new Zombie[N];
	if (!zombieArray)
		return NULL;
	for (int i = 0; i < N; i++)
		zombieArray[i].setName(name);
	return zombieArray;
}
