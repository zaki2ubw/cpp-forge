/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 19:24:38 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/06 18:23:53 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
	:name_("DefaltScav"), hitPoint_(100), energyPoint_(10), damage_(0)
{
	Logger::construct("Default ScavTrap is sponed.");
	Logger::action("GREET : Hi, I am ... Ops, I have no Name...");
	this->showStatus();
}

ScavTrap::ScavTrap(const std::string& name)
	:name_(name), hitPoint_(10), energyPoint_(10), damage_(0)
{
	Logger::construct("Named ScavTrap " + this->name_ + " is sponed.");
	Logger::action("GREET : Hi, I am " + this->name_
			+ ". The Gratest Robot in this world!!");
	this->showStatus();
}

ScavTrap::ScavTrap(const ScavTrap& src)
	:name_(src.name_),
	 hitPoint_(src.energyPoint_),
	 energyPoint_(src.energyPoint_),
	 damage_(src.damage_)
{
	Logger::construct("Copyed ScavTrap " + this->name_ + " is sponed.");
	Logger::action("GREET : Hi, I am " + this->name_
			+ ". One of the copy of the Gratest Robot in this world!!");
	this->showStatus();
}
ScavTrap::~ScavTrap()
{
	Logger::action("GREET : Bye-bye friends!!");
	Logger::destruct("ScavTrap is desponed.");
}

ScavTrap&		operator=(const ScavTrap& src)
{
	this->name_ = src.getName();
	this->hitPoint_ = src.getCurrentHp();
	this->energyPoint_ = src.getCurrentEp();
	this->damage_ = src.getCurrentDmg();
	return *this;
}

void	ScavTrap::attack(const std::string& target)
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
	Logger::action("ATTACK: " + this->name_ + " attacks " + target
			+ " causing " + ss.str() + " points of damage!");
	this->showStatus();
	return ;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoint_ == 0)
	{
		Logger::warning(this->name_ + " is already dead. Nothing has happend.");
		return ;
	}
	if (amount >= this->hitPoint_)
		this->hitPoint_ = 0;
	else
		this->hitPoint_ -= amount;
	std::stringstream ss;
	ss << this->hitPoint_;
	std::stringstream sa;
	sa << amount;
	Logger::action("DAMAGE: " + this->name_ +
			" loose " + sa.str() + " points of HP.");
	if (this->hitPoint_ == 0)
	{
		Logger::warning(this->name_ + " is dead. Nothing will happen.");
		return ;
	}
	this->showStatus();
	return ;
}

void	ScavTrap::beRepaired(unsigned int amount)
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
	this->hitPoint_ += amount;
	std::stringstream ss;
	ss << amount;
	Logger::action("REPAIR: " + this->name_ + " repaired "
			+ ss.str() + " points of HP!");
	this->showStatus();
	return ;
}

void	ScavTrap::guardGate()
