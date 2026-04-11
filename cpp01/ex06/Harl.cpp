/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 14:03:30 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/04/11 17:52:09 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <iomanip>

# define	OUTOFRANGE -1
# define	LEVELRANGE 4
# define	PREFIX_WIDTH 10

namespace {
	int		levelHandler(const std::string levels[], const std::string& state);
	void	printInvalidInput(void);

	int		levelHandler(const std::string levels[], const std::string& state)
	{
		int	i = 0;

		while (i < LEVELRANGE && levels[i] != state)
			i++;
		if (i == LEVELRANGE)
			return OUTOFRANGE;
		return i;
	}

	void	printInvalidInput(void)
	{
		std::cerr << std::setw(PREFIX_WIDTH) << "[IGNORE]:";
		std::cerr << "He's saying something insignificant.";
		std::cerr << std::endl;
		return ;
	}
}

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::complain(const std::string& state)
{
	std::string	levels[LEVELRANGE];

	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";
	int level = levelHandler(levels, state);
	switch (level)
	{
		case 0:
			Harl::debug();
			//fallthrough
		case 1:
			Harl::info();
			//fallthrough
		case 2:
			Harl::warning();
			//fallthrough
		case 3:
			Harl::error();
			//fallthrough
		default :
			printInvalidInput();
	}
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
