/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 14:02:00 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/09 19:26:24 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"
#include "Animal.hpp"

Animal::Animal()
	: type("Animal")
{
	Logger::construct("Animal is sponed.");
}

Animal::Animal(const Animal& src)
	:type(src.type)
{
	Logger::construct("Animal is sponed.");
}

Animal::~Animal()
{
	Logger::destruct("Animal is desponed.");
}

Animal&		Animal::operator=(const Animal& src)
{
	if (this != &src)
		this->type = src.getType();
	return (*this);
}

std::string	Animal::getType() const
{
	return (this->type);
}

void		Animal::makeSound() const
{
	std::cout << "Something Sound by real Animal." << std::endl;
	return ;
}
