/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 13:18:09 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/04 18:19:55 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	:name_("DefalTrap"), hitPoint_(10), energyPoint_(10), damage_(0)
{
	std::cout << "[Construct] Hi, I am..., Ops I have no UniqueName." << std::endl;
	this->showStatus();
}

ClapTrap::ClapTrap(const std::string& name)
	:name_(name), hitPoint_(10), energyPoint_(10), damage_(0)
{
	std::cout << "[Construct] Hi, I am " << name;
	std::cout << ". The Gratest Robot in this world!!" << std::endl;
	this->showStatus();
}

ClapTrap::ClapTrap(const ClapTrap& src)
	:name_(src.name_),
	 hitPoint_(src.energyPoint_),
	 energyPoint_(src.energyPoint_),
	 damage_(src.damage_)
{
	std::cout << "[Construct] Hi, I am " << this->name_;
	std::cout << ". One of the copy of the Gratest Robot in this world!!" << std::endl;
	this->showStatus();
}

ClapTrap::~ClapTrap()
{
	std::cout << "[Destruct] Bye-bye friends!!" << std::endl;
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
	if (this->energyPoint_ == 0)
	{
		std::cout << "[ATTACK]: ";
		std::cout << this->name_ << " ";
		std::cout << "has no energy. Can not do anything." << std::endl;
		return ;
	}
	this->energyPoint_ -= 1;
	std::cout << "[ATTACK]: ";
	std::cout << this->name_ << " ";
	std::cout << "attacks " << target << ", ";
	std::cout << "causing " << this->damage_ << " ";
	std::cout << "points of damage!" << std::endl;
	this->showStatus();
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoint_ == 0)
	{
		this->showDeadLog();
		return ;
	}
	if (amount >= this->hitPoint_)
		this->hitPoint_ = 0;
	else
		this->hitPoint_ -= amount;
	std::cout << "[DAMAGE]: ";
	std::cout << this->name_ << " ";
	std::cout << "loose " << amount << " ";
	std::cout << "points of HP" << std::endl;
	if (this->hitPoint_ == 0)
	{
		std::cout << this->name_ << " is dead." << std::endl;
		return ;
	}
	this->showStatus();
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoint_ == 0)
	{
		this->showDeadLog();
		return ;
	}
	if (this->energyPoint_ == 0)
	{
		std::cout << "[REPAIR]: ";
		std::cout << this->name_ << " ";
		std::cout << "has no energy. Can not do anything." << std::endl;
		return ;
	}
	this->energyPoint_ -= 1;
	this->hitPoint_ += amount;
	std::cout << "[REPAIR]: ";
	std::cout << this->name_ << " ";
	std::cout << "repaired " << amount << " ";
	std::cout << "points of HP" << std::endl;
	this->showStatus();
	return ;
}

void	ClapTrap::showStatus() const
{
	std::cout << "[INFO] Name: " << this->name_ << std::endl;
	std::cout << "[INFO] HP  : " << this->hitPoint_ << std::endl;
	std::cout << "[INFO] EP  : " << this->energyPoint_ << std::endl;
	std::cout << "[INFO] DMG : " << this->damage_ << std::endl;
	return ;
}

void	ClapTrap::showDeadLog() const
{
	std::cout << "[ATTENTION] ";
	std::cout << this->name_ << " ";
	std::cout << "is already dead. Nothing has happend" << std::endl;
}
