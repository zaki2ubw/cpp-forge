/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:52:30 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/03/23 10:06:18 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include "index.hpp"

class Contact
{
	public:
		Contact();
		~Contact();
		bool					addColumn(int index, std::string input);
		void					displaySummary(int index);
		void					displayDetail(void);

	private:
		typedef void			(Contact::*SetField)(std::string);
		static SetField			_setFields[SIZE];
		void					setFirstName(std::string input);
		void					setLastName(std::string input);
		void					setNickName(std::string input);
		void					setPhoneNumber(std::string input);
		void					setDarkestSecret(std::string input);
		void					displaySingleField(const std::string& field);
		std::string				_firstName;
		std::string				_lastName;
		std::string				_nickName;
		std::string				_phoneNumber;
		std::string				_darkestSecret;
};

