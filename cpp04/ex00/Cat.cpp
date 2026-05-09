/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 17:37:55 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/09 19:25:39 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"
#include "Cat.hpp"

Cat::Cat()
	: Animal()
{
	this->type = "Cat";
	Logger::construct("Cat is sponed.");
}

Cat::Cat(const Cat& src)
	:Animal(src)
{
	Logger::construct("Cat is sponed.");
}

Cat::~Cat()
{
	Logger::destruct("Cat is desponed.");
}

Cat&		Cat::operator=(const Cat& src)
{
	if (this != &src)
		Animal::operator=(src);
	return (*this);
}

void		Cat::makeSound() const
{
	std::cout << "Meow!!" << std::endl;
	return ;
}
