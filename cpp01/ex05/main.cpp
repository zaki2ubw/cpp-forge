/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 15:22:14 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/04/11 15:44:30 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <iomanip>

int	main(void)
{
	Harl		harl;
	std::string	line;

	std::cout << std::setw(10) << "[START]:";
	std::cout << "Show sample cases" << std::endl;
	harl.complain("");
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("HOGE");
	std::cout << std::setw(10) << "[END]:";
	std::cout << "Show sample cases" << std::endl;
	while (1)
	{
		std::cout << "Please input state for test" << std::endl;
		std::cout << ">";
		if (!getline(std::cin, line))
			return 1;
		std::cout << std::endl;
		harl.complain(line);
		std::cout << "Continue? (yes/no)" << std::endl;
		std::cout << ">";
		if (!getline(std::cin, line))
			return 1;
		if (line == "no")
			break ;
	}
	return 0;
}
