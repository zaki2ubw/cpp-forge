/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:33:40 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/03/23 14:46:17 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "contact.hpp"

int	main(void)
{
	static const std::string	prompt = "Enter 'ADD', 'SEARCH' or EXIT";
	std::string	command;

	PhoneBook pb;
	std::cout << "Hello, this is your Awesome PhoneBook" << std::endl;
	while (true)
	{
		std::cout << prompt << std::endl;
		if(!getline(std::cin, command))
			break ;
		if (command.empty())
			continue ;
		if (command == "ADD")
			pb.addContact();
		else if (command == "SEARCH")
			pb.searchContact();
		else if (command == "EXIT")
			break ;
	}
	std::cout << "Bye :)" << std::endl;
	return (0);
}
