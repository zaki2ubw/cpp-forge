/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 08:02:43 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/04/27 22:40:23 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include <cstdlib>
#include "Fixed.hpp"

const int	Fixed::fractBit = 8;
const int	Fixed::bitShift = 1 << fractBit;

Fixed::Fixed()
	: fixedPointValue(0)
{
}

Fixed::Fixed(const int intVal)
	: fixedPointValue(0)
{
	this->fixedPointValue = intVal * bitShift;
}

Fixed::Fixed(const float floatVal)
	: fixedPointValue(0)
{
	this->fixedPointValue = static_cast<int>(roundf(floatVal * bitShift));
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed& src)
{
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
{
	if (this->fixedPointValue > target.fixedPointValue)
		return true;
	else
		return false;
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

	result.fixedPointValue = this->fixedPointValue - subtract.fixedPointValue;
	return result;
}

Fixed	Fixed::operator*(const Fixed& multiplicate) const
{
	float	realThisValue = this->toFloat();
	float	realMultiValue = multiplicate.toFloat();
	Fixed	result(realThisValue * realMultiValue);

	return result;
}

Fixed	Fixed::operator/(const Fixed& divide) const
{
	if (divide.getRawBits()	== 0)
	{
		std::cerr << "Division by 0 is Taboo. It has no answer" << std::endl;
		exit(EXIT_FAILURE);
	}
	float	realThisValue = this->toFloat();
	float	realDivideValue = divide.toFloat();
	Fixed	result(realThisValue / realDivideValue);

	return result;
}

Fixed&	Fixed::operator++(void)
{
	this->fixedPointValue += 1;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	copy(*this);

	this->fixedPointValue += 1;
	return copy;
}

Fixed&	Fixed::operator--(void)
{
	this->fixedPointValue -= 1;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	copy(*this);

	this->fixedPointValue -= 1;
	return copy;
}

int		Fixed::getRawBits(void) const
{
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

Fixed&	Fixed::min(Fixed& first, Fixed& second)
{
	if (first <= second)
		return first;
	else
		return second;
}

const Fixed&	Fixed::min(const Fixed& first, const Fixed& second)
{
	if (first <= second)
		return first;
	else
		return second;
}

Fixed&	Fixed::max(Fixed& first, Fixed& second)
{
	if (first >= second)
		return first;
	else
		return second;
}

const Fixed&	Fixed::max(const Fixed& first, const Fixed& second)
{
	if (first >= second)
		return first;
	else
		return second;
}

std::ostream&	operator<<(std::ostream& os, const Fixed& src)
{
	os << src.toFloat();
	return os;
}
