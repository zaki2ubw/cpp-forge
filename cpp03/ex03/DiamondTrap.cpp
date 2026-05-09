/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 10:18:54 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/09 12:37:58 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"
#include "DiamondTrap.hpp"

const std::string	DiamondTrap::kDefaultName = "defaultDiamond";

DiamondTrap::DiamondTrap()
	:ClapTrap(std::string(kDefaultName) + "_clap_name",
			  FragTrap::kDefaultHp,
			  ScavTrap::kDefaultEp,
			  FragTrap::kDefaultDmg),
			  ScavTrap(),
			  FragTrap(),
			  name_("Diamond")
{
	Logger::construct("Default DiamondTrap " + this->name_ + " is sponed.");
	Logger::action(std::string("GREET : ") + "Now I stand as DiamondTrap, " +
			       "inherited all parts of ClapTrap Family!!");
}

DiamondTrap::DiamondTrap(const std::string& name)
	:ClapTrap(std::string(name) + "_clap_name",
			  FragTrap::kDefaultHp,
			  ScavTrap::kDefaultEp,
			  FragTrap::kDefaultDmg),
			  ScavTrap(),
			  FragTrap(),
			  name_(name)
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
	Logger::action(std::string("WHOAMI: ") + "My Name is " + this->name_);
	Logger::action(std::string("WHOAMI: ") + "My ClapName is " + ClapTrap::getName());
	return ;
}
