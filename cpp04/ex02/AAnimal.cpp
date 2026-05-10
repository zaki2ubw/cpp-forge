/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 14:38:56 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/10 14:43:34 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"
#include "AAnimal.hpp"

AAnimal::AAnimal()
	: type("AAnimal")
{
	Logger::construct("AAnimal is abstract class.");
}

AAnimal::AAnimal(const AAnimal& src)
	:type(src.type)
{
	Logger::construct("AAnimal is abstract class.");
}

AAnimal::~AAnimal()
{
	Logger::destruct("AAnimal is destrcuted.");
}

AAnimal&		AAnimal::operator=(const AAnimal& src)
{
	if (this != &src)
		this->type = src.getType();
	return (*this);
}

std::string	AAnimal::getType() const
{
	return (this->type);
}
