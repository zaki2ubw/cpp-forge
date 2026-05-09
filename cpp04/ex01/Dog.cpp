/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 17:30:34 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/10 02:57:50 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"
#include "Dog.hpp"

Dog::Dog()
	:Animal(), brain_(new Brain())
{
	this->type = "Dog";
	Logger::construct("Dog is sponed.");
}

Dog::Dog(const Dog& src)
	:Animal(src), brain_(new Brain())
{
	Logger::construct("Dog is sponed by copy.");
}

Dog::~Dog()
{
	delete brain_;
	Logger::destruct("Dog is desponed.");
}

Dog&		Dog::operator=(const Dog& src)
{
	if (this != &src)
	{
		Animal::operator=(src);
		*(this->brain_) = *(src.brain_);
	}
	return *this;
}

void		Dog::makeSound() const
{
	std::cout << "Woof woof!!" << std::endl;
	return ;
}
