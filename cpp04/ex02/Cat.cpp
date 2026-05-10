/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 17:37:55 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/10 14:41:02 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"
#include "Cat.hpp"

Cat::Cat()
	: AAnimal(), brain_(new Brain())
{
	this->type = "Cat";
	Logger::construct("Cat is sponed.");
}

Cat::Cat(const Cat& src)
	:AAnimal(src), brain_(new Brain(*src.brain_))
{
	Logger::construct("Cat is sponed by copy.");
}

Cat::~Cat()
{
	Logger::destruct("Cat is desponed.");
	delete brain_;
}

Cat&		Cat::operator=(const Cat& src)
{
	if (this != &src)
	{
		AAnimal::operator=(src);
		*(this->brain_) = *(src.brain_);
	}
	return *this;
}

void		Cat::makeSound() const
{
	std::cout << "Meow!!" << std::endl;
	return ;
}

std::string	Cat::getIdea(size_t i) const
{
	return this->brain_->getAnIdea(i);
}

void		Cat::setIdea(size_t i, const std::string& idea)
{
	this->brain_->setAnIdea(i, idea);
	return ;
}
