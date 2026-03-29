/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:59:26 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/03/23 15:02:12 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include "index.hpp"
#include "contact.hpp"

Contact::SetField Contact::_setFields[SIZE] = {
	&Contact::setFirstName,
	&Contact::setLastName,
	&Contact::setNickName,
	&Contact::setPhoneNumber,
	&Contact::setDarkestSecret
};

namespace {
	bool	isOnlySpace(const std::string& str)
	{
		for (size_t i = 0; i < str.size(); i++)
		{
			if (!std::isspace(static_cast<unsigned char>(str[i])))
				return (false);
		}
		return (true);
	}
}

Contact::Contact()
{
}

Contact::~Contact()
{
}

bool	Contact::addColumn(int index, std::string input)
{
	if (index < 0 || index >= SIZE)
		return (false);
	if (input.empty() || isOnlySpace(input))
		return (false);
	(this->*(_setFields[index]))(input);
	std::cout << std::endl;
	return (true);
}

void	Contact::setFirstName(std::string input)
{
	_firstName = input;
	std::cout << "[REGISTERED] FirstName is " << _firstName << std::endl;
}

void	Contact::setLastName(std::string input)
{
	_lastName = input;
	std::cout << "[REGISTERED] LastName is " << _lastName << std::endl;
}

void	Contact::setNickName(std::string input)
{
	_nickName = input;
	std::cout << "[REGISTERED] NickName is " << _nickName << std::endl;
}

void	Contact::setPhoneNumber(std::string input)
{
	_phoneNumber = input;
	std::cout << "[REGISTERED] PhoneNumber is " << _phoneNumber << std::endl;
}

void	Contact::setDarkestSecret(std::string input)
{
	_darkestSecret = input;
	std::cout << "[REGISTERED] DarkestSecret is " << _darkestSecret << std::endl;
}

void	Contact::displaySummary(int index)
{
	std::cout << "|";
	std::cout << std::setw(10) << index;
	Contact::displaySingleField(_firstName);
	Contact::displaySingleField(_lastName);
	Contact::displaySingleField(_nickName);
	std::cout << "|" << std::endl;
	return ;
}

void	Contact::displaySingleField(const std::string& field)
{
	size_t	length;
	std::string	adjustedField;
	std::string	separate = "|";

	length = field.size();
	if (length > 10)
		adjustedField = field.substr(0, 9) + ".";
	else
		adjustedField = field;
	std::cout << separate;
	std::cout << std::setw(10) << adjustedField;
	return ;
}

void	Contact::displayDetail(void)
{
	std::cout << "FirstName: " << _firstName << std::endl;
	std::cout << "LastName: " << _lastName << std::endl;
	std::cout << "NickName: " << _nickName << std::endl;
	std::cout << "PhoneNumber: " << _phoneNumber << std::endl;
	std::cout << "DarkestSecret: " << _darkestSecret << std::endl;
	return ;
}
