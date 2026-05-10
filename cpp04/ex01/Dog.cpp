/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 17:30:34 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/10 13:51:20 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"
#include "Dog.hpp"

Dog::Dog()
	: Animal(), brain_(new Brain())
{
	this->type = "Dog";
	Logger::construct("Dog is sponed.");
}

Dog::Dog(const Dog& src)
	:Animal(src), brain_(new Brain(*src.brain_))
{
	Logger::construct("Dog is sponed by copy.");
}

Dog::~Dog()
{
	Logger::destruct("Dog is desponed.");
	delete brain_;
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

std::string	Dog::getIdea(size_t i) const
{
	return this->brain_->getAnIdea(i);
}

void		Dog::setIdea(size_t i, const std::string& idea)
{
	this->brain_->setAnIdea(i, idea);
	return ;
}
