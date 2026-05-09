/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 18:54:18 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/09 19:23:01 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
	: type("WrongAnimal")
{
	Logger::construct("WrongAnimal is sponed.");
}

WrongAnimal::WrongAnimal(const WrongAnimal& src)
	:type(src.type)
{
	Logger::construct("WrongAnimal is sponed.");
}

WrongAnimal::~WrongAnimal()
{
	Logger::destruct("WrongAnimal is desponed.");
}

WrongAnimal&		WrongAnimal::operator=(const WrongAnimal& src)
{
	if (this != &src)
		this->type = src.getType();
	return (*this);
}

std::string	WrongAnimal::getType() const
{
	return (this->type);
}

void		WrongAnimal::makeSound() const
{
	std::cout << "I am WrongAnimal." << std::endl;
	return ;
}
