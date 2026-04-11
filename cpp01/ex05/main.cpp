/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 15:22:14 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/04/11 17:43:46 by sohyamaz         ###   ########.fr       */
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
	std::cout << "CASE0: input=''" << std::endl;
	harl.complain("");
	std::cout << "CASE1: input=DEBUG" << std::endl;
	harl.complain("DEBUG");
	std::cout << "CASE2: input=INFO" << std::endl;
	harl.complain("INFO");
	std::cout << "CASE3: input=WARNING" << std::endl;
	harl.complain("WARNING");
	std::cout << "CASE4: input=ERROR" << std::endl;
	harl.complain("ERROR");
	std::cout << "CASE5: input=HOGE" << std::endl;
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
		if (line != "yes")
			break ;
	}
	return 0;
}
