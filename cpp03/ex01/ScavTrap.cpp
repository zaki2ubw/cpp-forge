/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 19:24:38 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/06 20:09:25 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
	:ClapTrap("DefaltScav", 100, 50, 20)
{
	Logger::construct("Default ScavTrap " + this->name_ + " is sponed.");
	Logger::action(std::string("GREET : ") + "Now I stand as ScavTrap, " +
			       "inherited all parts of ClapTrap!!");
}

ScavTrap::ScavTrap(const std::string& name)
	:ClapTrap(name, 100, 50, 20)
{
	Logger::construct("Named ScavTrap " + this->name_ + " is sponed.");
	Logger::action(std::string("GREET : ") + "Now I stand as ScavTrap, " +
			       "inherited all parts of ClapTrap!!");
}

ScavTrap::ScavTrap(const std::string& name,
				   unsigned int hp,
				   unsigned int ep,
				   unsigned int dmg)
	:ClapTrap(name, hp, ep, dmg)
{
	Logger::construct("Copied ScavTrap " + this->name_ + " is sponed.");
	Logger::action(std::string("GREET : ") + "Now I stand as ScavTrap, " +
			       "inherited all parts of ClapTrap!!");
}

ScavTrap::ScavTrap(const ScavTrap& src)
	:ClapTrap(src)
{
	Logger::construct("Named ScavTrap " + this->name_ + " is sponed.");
	Logger::action(std::string("GREET : ") + "Now I stand as ScavTrap, " +
				   "inherited all parts of ClapTrap!!");
}

ScavTrap::~ScavTrap()
{
	Logger::destruct("ScavTrap is desponed.");
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& src)
{
	if (this != &src)
		ClapTrap::operator=(src);
	return *this;
}

void		ScavTrap::attack(const std::string& target)
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
	Logger::action("ATTACK: " + this->name_ + " tackled to " + target +
				   " causing " + ss.str() + " points of damage!");
	this->showStatus();
	return ;
}

void	ScavTrap::guardGate()
{
	if (this->hitPoint_ == 0)
	{
		Logger::warning(this->name_ + " is already dead. Nothing has happend.");
		return ;
	}
	Logger::action("ACTIVE: " + this->name_ + " is activated Gatekeeper mode!!");
	return ;
}
