/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 17:37:55 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/10 02:58:48 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"
#include "Cat.hpp"

Cat::Cat()
	:Animal(), brain_(new Brain())
{
	this->type = "Cat";
	Logger::construct("Cat is sponed.");
}

Cat::Cat(const Cat& src)
	:Animal(src), brain_(new Brain())
{
	Logger::construct("Cat is sponed by copy.");
}

Cat::~Cat()
{
	delete brain_;
	Logger::destruct("Cat is desponed.");
}

Cat&		Cat::operator=(const Cat& src)
{
	if (this != &src)
	{
		Animal::operator=(src);
		*(this->brain_) = *(src.brain_);
	}
	return *this;
}

void		Cat::makeSound() const
{
	std::cout << "Meow!!" << std::endl;
	return ;
}
