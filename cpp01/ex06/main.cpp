/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 15:22:14 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/04/11 17:58:23 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <iomanip>

int	main(int argc, char **argv)
{
	Harl		harl;
	std::string	line;

	if (argc != 2)
	{
		std::cerr << std::setw(10) << "[USAGE]:";
		std::cerr << "Please input DEBUG/INFO/WARNING/DEBUG or Message.";
		std::cerr << std::endl;
		return 1;
	}
	line = static_cast<std::string>(argv[1]);
	harl.complain(line);
	return 0;
}
