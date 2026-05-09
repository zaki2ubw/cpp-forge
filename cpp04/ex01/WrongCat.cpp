/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 19:05:37 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/09 19:28:05 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"
#include "WrongCat.hpp"

WrongCat::WrongCat()
	: WrongAnimal()
{
	this->type = "Cat";
	Logger::construct("WrongCat is sponed.");
}

WrongCat::WrongCat(const WrongCat& src)
	:WrongAnimal(src)
{
	Logger::construct("WrongCat is sponed.");
}

WrongCat::~WrongCat()
{
	Logger::destruct("WrongCat is desponed.");
}

WrongCat&	WrongCat::operator=(const WrongCat& src)
{
	if (this != &src)
		WrongAnimal::operator=(src);
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "Wrong meow!!" << std::endl;
	return ;
}
