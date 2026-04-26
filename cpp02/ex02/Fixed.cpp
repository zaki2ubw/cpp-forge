/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 08:02:43 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/04/26 18:36:42 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

const int	Fixed::fractBit = 8;
const int	Fixed::bitShift = 1 << fractBit;

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

bool	Fixed::operator==(const Fixed& target) const
{
	if (this->fixedPointValue == target.fixedPointValue)
		return true;
	else
		return false;
}

bool	Fixed::operator!=(const Fixed& target) const
{
	if (this->fixedPointValue != target.fixedPointValue)
		return true;
	else
		return false;
}

bool	Fixed::operator>(const Fixed& target) const
	if (this->fixedPointValue > target.fixedPointValue)
		return true;
	else
		return false;
{
}

bool	Fixed::operator<(const Fixed& target) const
{
	if (this->fixedPointValue < target.fixedPointValue)
		return true;
	else
		return false;
}

bool	Fixed::operator>=(const Fixed& target) const
{
	if (this->fixedPointValue >= target.fixedPointValue)
		return true;
	else
		return false;
}

bool	Fixed::operator<=(const Fixed& target) const
{
	if (this->fixedPointValue <= target.fixedPointValue)
		return true;
	else
		return false;
}

Fixed	Fixed::operator+(const Fixed& add) const
{
	Fixed	result;

	result.fixedPointValue = this->fixedPointValue + add.fixedPointValue;
	return result;
}

Fixed	Fixed::operator-(const Fixed& subtract) const
{
	Fixed	result;

	result.fixedPointValue = this->fixedPointValue - add.fixedPointValue;
	return result;
}

Fixed	Fixed::operator*(const Fixed& multiplicate) const
{
	Fixed	result;

	result.fixedPointValue = this->fixedPointValue * add.fixedPointValue;
	return result;
}

Fixed	Fixed::operator/(const Fixed& divide) const
{
	Fixed	result;

	result.fixedPointValue = this->fixedPointValue / add.fixedPointValue;
	return result;
}

Fixed	Fixed::operator++(void)
{
	this->fixedPointValue + 1;
	return *this;
}

Fixed&	Fixed::operator++(int)
{
	Fixed&	result = this;

	result.fixedPointValue + 1;
	return result;
}

Fixed	Fixed::operator--(void)
{
	this->fixedPointValue + 1;
	return *this;
}

Fixed&	Fixed::operator--(int)
{
	Fixed&	result = this;

	result.fixedPointValue - 1;
	return result;
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

std::ostream&	operator<<(std::ostream& os, const Fixed& src)
{
	os << src.toFloat();
	return os;
}
