/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 19:05:37 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/10 13:45:52 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"
#include "WrongCat.hpp"

WrongCat::WrongCat()
	: WrongAnimal(), brain_(new Brain())
{
	this->type = "Cat";
	Logger::construct("WrongCat is sponed.");
}

WrongCat::WrongCat(const WrongCat& src)
	:WrongAnimal(src)
{
	this->brain_ = src.brain_;
	Logger::construct("WrongCat is sponed by copy.");
}

WrongCat::~WrongCat()
{
	Logger::destruct("WrongCat is desponed.");
	delete this->brain_;
}

WrongCat&	WrongCat::operator=(const WrongCat& src)
{
	if (this != &src)
	{
		WrongAnimal::operator=(src);
		this->brain_ = src.brain_;
	}
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "Wrong meow!!" << std::endl;
	return ;
}

std::string	WrongCat::getIdea(size_t i) const
{
	return this->brain_->getAnIdea(i);
}

void		WrongCat::setIdea(size_t i, const std::string& idea)
{
	this->brain_->setAnIdea(i, idea);
	return ;
}
