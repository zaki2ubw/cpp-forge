/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 17:30:34 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/09 19:24:46 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"
#include "Dog.hpp"

Dog::Dog()
	: Animal()
{
	this->type = "Dog";
	Logger::construct("Dog is sponed.");
}

Dog::Dog(const Dog& src)
	:Animal(src)
{
	Logger::construct("Dog is sponed.");
}

Dog::~Dog()
{
	Logger::destruct("Dog is desponed.");
}

Dog&		Dog::operator=(const Dog& src)
{
	if (this != &src)
		Animal::operator=(src);
	return (*this);
}

void		Dog::makeSound() const
{
	std::cout << "Woof woof!!" << std::endl;
	return ;
}
