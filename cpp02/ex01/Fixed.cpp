/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 08:02:43 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/04/25 21:21:54 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

const int	Fixed::fractBit = 8;
const int	Fixed::bitShift = 1 << fractBit;

std::ostream&	operator<<(std::ostream& os, const Fixed& src)
{
	os << src.toFloat();
	return os;
}

Fixed::Fixed()
	: fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intVal)
	: fixedPointValue(0)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedPointValue = intVal * bitShift;
}

Fixed::Fixed(const float floatVal)
	: fixedPointValue(0)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedPointValue = static_cast<int>(roundf(floatVal * bitShift));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixedPointValue = src.getRawBits();
}

Fixed&	Fixed::operator=(const Fixed& src)
{
	if (this != &src)
		this->fixedPointValue = src.fixedPointValue;
	return *this;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPointValue);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixedPointValue = raw;
	return ;
}

float	Fixed::toFloat(void) const
{
	float	val;

	val = static_cast<float>(this->fixedPointValue) / bitShift;
	return val;
}

int		Fixed::toInt(void) const
{
	int		val;

	val = this->fixedPointValue / bitShift;
	return val;
}
