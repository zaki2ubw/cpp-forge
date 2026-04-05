/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 18:09:23 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/04/05 18:19:52 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string		stringORG = "HI THIS IS BRAIN";
	std::string*	stringPTR = &stringORG;
	std::string&	stringREF = stringORG;

	std::cout << "stringORG:"<< std::endl;
	std::cout << "  Address=" << &stringORG << std::endl;
	std::cout << "  Value=" << stringORG << std::endl;
	std::cout << "stringPTR:" << std::endl;
	std::cout << "  Address=" << stringPTR << std::endl;
	std::cout << "  Value=" << *stringPTR << std::endl;
	std::cout << "stringREF:" << std::endl;
	std::cout << "  Address=" << &stringREF << std::endl;
	std::cout << "  Value=" << stringREF << std::endl;
	return 0;
}
