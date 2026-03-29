/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:09:49 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/03/29 16:18:57 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <cstdlib>
#include "phonebook.hpp"


namespace {
	std::string getPrompt(int index);
	void		displayHeader(void);
	void		displaySeparate(void);

	static const std::string	prompt[SIZE] = {
		"Please Input First Name",
		"Please Input Last Name",
		"Please Input NickName",
		"Please Input Phone Number",
		"Please Input Darkest Secret"
	};

	std::string getPrompt(int index)
	{
		if (index < 0 || index >= SIZE)
			return ("\n");
		return (prompt[index]);
	}

	void	displayHeader(void)
	{
		displaySeparate();
		std::cout << "|";
		std::cout << std::left << std::setw(43) << "***PHONEBOOK***";
		std::cout << "|" << std::endl;
		displaySeparate();
		std::cout << "|";
		std::cout << std::right << std::setw(10) << "Index";
		std::cout << "|";
		std::cout << std::setw(10) << "FirstName";
		std::cout << "|";
		std::cout << std::setw(10) << "LastName";
		std::cout << "|";
		std::cout << std::setw(10) << "NickName";
		std::cout << "|" << std::endl;
		displaySeparate();
		return ;
	}

	bool	isNumber(const std::string& input)
	{
		if (input.empty())
			return (false);
		for (size_t i = 0; i < input.size(); i++)
		{
			if (!std::isdigit(static_cast<unsigned char>(input[i])))
			   return (false);
		}
		return (true);
	}


	void	displaySeparate(void)
	{
		std::cout << "|";
		std::cout << std::setw(10) << "==========";
		std::cout << "|";
		std::cout << std::setw(10) << "==========";
		std::cout << "|";
		std::cout << std::setw(10) << "==========";
		std::cout << "|";
		std::cout << std::setw(10) << "==========";
		std::cout << "|" << std::endl;
		return ;
	}

	int		getIndex(const std::string& input)
	{
		int	index;

		if (input.empty())
			return (-1);
		else if (!isNumber(input))
			return (-1);
		index = std::atoi(input.c_str());
		return (index);
	}
}

PhoneBook::PhoneBook()
{
	_registered = 0;
	_nextRow = 0;
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::setNextRow(void)
{
	_nextRow = (_nextRow + 1) % 8;
}

void	PhoneBook::addContact(void)
{
	std::string	empty = "Input was Empty, please try again\n";
	std::string input;

	for (int index = 0; index < SIZE;)
	{
		std::cout << getPrompt(index) << std::endl;
		if (!getline(std::cin, input))
			break ;
		if (contacts[_nextRow].addColumn(index, input) == true)
			index++;
		else
			std::cout << empty;
	}
	if (_registered < 8)
		_registered++;
	PhoneBook::setNextRow();
	std::cout << _registered << " contacts."<< std::endl;
}

void	PhoneBook::searchContact(void)
{
	int			index;
	std::string	input;

	if (_registered == 0)
	{
		std::cout << "PhoneBook is empty" << std::endl;
		return ;
	}
	displayHeader();
	for (int i = 0; i < _registered; i++)
	{
		contacts[i].displaySummary(i);
		displaySeparate();
	}
	std::cout << "Please select Index" << std::endl;
	if (!getline(std::cin, input))
		return ;
	index = getIndex(input);
	if (index < 0 || index >= _registered)
	{
		std::cout << "[ERROR]Minimum index is '0', and Maximum index is '";
		std::cout << _registered - 1 << "'." << std::endl;
	}
	else
		contacts[index].displayDetail();
	return ;
}
