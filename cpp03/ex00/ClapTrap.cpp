/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 13:18:09 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/06 18:26:20 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"
#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	:name_("DefalTrap"), hitPoint_(10), energyPoint_(10), damage_(0)
{
	Logger::construct("Default ClapTrap is sponed.");
	Logger::action("GREET : Hi, I am ... Ops, I have no Name...");
	this->showStatus();
}

ClapTrap::ClapTrap(const std::string& name,
				   unsigned int hp,
				   unsigned int ep,
				   unsigned int dmg)
	:name_(name), hitPoint_(hp), energyPoint_(ep), damage_(dmg)
{
	Logger::construct("Named ClapTrap " + this->name_ + " is sponed.");
	Logger::action("GREET : Hi, I am " + this->name_
			+ ". The Gratest Robot in this world!!");
	this->showStatus();
}

ClapTrap::ClapTrap(const ClapTrap& src)
	:name_(src.name_),
	 hitPoint_(src.energyPoint_),
	 energyPoint_(src.energyPoint_),
	 damage_(src.damage_)
{
	Logger::construct("Copyed ClapTrap " + this->name_ + " is sponed.");
	Logger::action("GREET : Hi, I am " + this->name_
			+ ". One of the copy of the Gratest Robot in this world!!");
	this->showStatus();
}

ClapTrap::~ClapTrap()
{
	Logger::action("GREET : Bye-bye friends!!");
	Logger::destruct("ClapTrap is desponed.");
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& src)
{
	this->name_ = src.getName();
	this->hitPoint_ = src.getCurrentHp();
	this->energyPoint_ = src.getCurrentEp();
	this->damage_ = src.getCurrentDmg();
	return *this;
}

std::string		ClapTrap::getName() const
{
	return this->name_;
}

unsigned int	ClapTrap::getCurrentHp() const
{
	return this->hitPoint_;
}

unsigned int	ClapTrap::getCurrentEp() const
{
	return this->energyPoint_;
}

unsigned int	ClapTrap::getCurrentDmg() const
{
	return this->damage_;
}

void	ClapTrap::attack(const std::string& target)
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

void	ClapTrap::takeDamage(unsigned int amount)
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

void	ClapTrap::beRepaired(unsigned int amount)
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

void	ClapTrap::showStatus() const
{
	Logger::Info("NAME", this->name_);
	Logger::Info("HP", this->hitPoint_);
	Logger::Info("EP", this->energyPoint_);
	Logger::Info("DMG", this->damage_);
	return ;
}
