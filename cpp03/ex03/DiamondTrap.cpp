/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 10:18:54 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/09 11:18:00 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	:name_("Diamond"), ClapTrap(name_ + "clap_name", FragTrap::hitPoint_, ScavTrap::energyPoint_, FragTrap::damage_)
{
	Logger::construct("Default DiamondTrap " + this->name_ + " is sponed.");
	Logger::action(std::string("GREET : ") + "Now I stand as DiamondTrap, " +
			       "inherited all parts of ClapTrap Family!!");
}

DiamondTrap::DiamondTrap(const std::string& name)
	:name_(name), ClapTrap(name_ + "clap_name", FragTrap::hitPoint_, ScavTrap::energyPoint_, FragTrap::damage_)
{
	Logger::construct("Named DiamondTrap " + this->name_ + " is sponed.");
	Logger::action(std::string("GREET : ") + "Now I stand as DiamondTrap, " +
			       "inherited all parts of ClapTrap Family!!");
}

DiamondTrap::DiamondTrap(const DiamondTrap& src)
	:ClapTrap(src)
{
	Logger::construct("Named DiamondTrap " + this->name_ + " is sponed.");
	Logger::action(std::string("GREET : ") + "Now I stand as DiamondTrap, " +
				   "inherited all parts of ClapTrap!!");
}

DiamondTrap::~DiamondTrap()
{
	Logger::destruct("DiamondTrap is desponed.");
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& src)
{
	if (this != &src)
	{
		ClapTrap::operator=(src);
		this->name_ = src.name_;
	}
	return *this;
}

void		DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
	return ;
}

void		DiamondTrap::whoAmI()
{
	Logger::action(std::string("WHOAMI: ") + "My Name is " + this->Name);
	Logger::action(std::string("WHOAMI: ") + "My ClapName is " + ClapName::getName());
	return ;
}
