/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 15:42:46 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/04/05 14:27:32 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie
{
	public:
		Zombie();
		~Zombie();
		void	announce(void) const;
		void	setName(std::string name);

	private:
		std::string	zombieName;
};

Zombie*	zombieHorde(int N, std::string name);
