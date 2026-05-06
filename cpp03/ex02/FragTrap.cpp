/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 22:21:48 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/06 22:40:13 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap()
	:ClapTrap("DefaltFrag", 100, 100, 30)
{
	Logger::construct("Default FragTrap " + this->name_ + " is sponed.");
	Logger::action(std::string("GREET : ") + "Now I stand as FragTrap, " +
			       "inherited all parts of ClapTrap!!");
}

FragTrap::FragTrap(const std::string& name)
	:ClapTrap(name, 100, 100, 30)
{
	Logger::construct("Named FragTrap " + this->name_ + " is sponed.");
	Logger::action(std::string("GREET : ") + "Now I stand as FragTrap, " +
			       "inherited all parts of ClapTrap!!");
}

FragTrap::FragTrap(const std::string& name,
				   unsigned int hp,
				   unsigned int ep,
				   unsigned int dmg)
	:ClapTrap(name, hp, ep, dmg)
{
	Logger::construct("Copied FragTrap " + this->name_ + " is sponed.");
	Logger::action(std::string("GREET : ") + "Now I stand as FragTrap, " +
			       "inherited all parts of ClapTrap!!");
}

FragTrap::FragTrap(const FragTrap& src)
	:ClapTrap(src)
{
	Logger::construct("Named FragTrap " + this->name_ + " is sponed.");
	Logger::action(std::string("GREET : ") + "Now I stand as FragTrap, " +
				   "inherited all parts of ClapTrap!!");
}

FragTrap::~FragTrap()
{
	Logger::destruct("FragTrap is desponed.");
}

FragTrap&	FragTrap::operator=(const FragTrap& src)
{
	if (this != &src)
		ClapTrap::operator=(src);
	return *this;
}

void		FragTrap::attack(const std::string& target)
{
	if (this->hitPoint_ == 0)
	{
		Logger::warning(this->name_ + " is already dead. Nothing has happend.");
		return ;
	}
	if (this->energyPoint_ == 0)
	{
		Logger::warning(this->name_ + " has no energy. Can't do anything.");
		return ;
	}
	this->energyPoint_ -= 1;
	std::stringstream ss;
	ss << this->damage_;
	Logger::action("ATTACK: " + this->name_ + " High-five to " + target +
				   " causing " + ss.str() + " points of damage!");
	this->showStatus();
	return ;
}

void	FragTrap::highFiveGuys()
{
	if (this->hitPoint_ == 0)
	{
		Logger::warning(this->name_ + " is already dead. Nothing has happend.");
		return ;
	}
	Logger::action(std::string("FRIEND: ") + "Hi friends, I am " + this->name_
				 + "!! Let's high-five!!");
	return ;
}

