/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 14:03:30 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/04/11 16:26:24 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <iomanip>

# define	LEVELRANGE 4
# define	PREFIX_WIDTH 10

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::complain(std::string state)
{
	void		(Harl::*funcp[LEVELRANGE])(void);
	std::string	levels[LEVELRANGE];
	size_t	i = 0;

	funcp[0] = &Harl::debug;
	funcp[1] = &Harl::info;
	funcp[2] = &Harl::warning;
	funcp[3] = &Harl::error;
	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";
	while (i < LEVELRANGE && levels[i] != state)
		i++;
	if (i == LEVELRANGE)
	{
		std::cerr << std::setw(PREFIX_WIDTH) << "[INVALID]:";
		std::cerr << "please input error state. ";
		std::cerr << "You can use only DEBUG/INFO/WARNING/ERROR";
		std::cerr << std::endl;
		return ;
	}
	(this->*funcp[i])();
	return ;
}

void	Harl::debug(void)
{
	std::cout << std::setw(PREFIX_WIDTH) << "[DEBUG]:";
	std::cout << "I love having extra bacon ";
	std::cout << "for my 7XL-double-cheese-triple-pickle-specialketchup burger. ";
	std::cout << "I really do!" << std::endl;
	return ;
}

void	Harl::info(void)
{
	std::cout << std::setw(PREFIX_WIDTH) << "[INFO]:";
	std::cout << "I cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn’t put enough bacon in my burger! ";
	std::cout << "If you did, I wouldn’t be asking for more!" << std::endl;
	return ;
}

void	Harl::warning(void)
{
	std::cout << std::setw(PREFIX_WIDTH) << "[WARNING]:";
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I’ve been coming for years, ";
	std::cout << "whereas you started working here just last month." << std::endl;
	return ;
}

void	Harl::error(void)
{
	std::cout << std::setw(PREFIX_WIDTH) << "[ERROR]:";
	std::cout << "This is unacceptable! ";
	std::cout << "I want to speak to the manager now." << std::endl;
	return ;
}
