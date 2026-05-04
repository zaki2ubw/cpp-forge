/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 08:02:43 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/04 11:37:18 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <limits>
#include "Fixed.hpp"

const int	Fixed::bitShift = 1 << Fixed::fractBit;
const float	Fixed::maxFloatInput =\
	static_cast<float>(std::numeric_limits<int>::max() / bitShift);
const float	Fixed::minFloatInput =\
	static_cast<float>(std::numeric_limits<int>::min() / bitShift);
const int	Fixed::maxIntInput = std::numeric_limits<int>::max() / bitShift;
const int	Fixed::minIntInput = std::numeric_limits<int>::min() / bitShift;
static bool	willMulOverFlow(int left, int right);
static bool	willAddOverFlow(int left, int right);

Fixed::Fixed()
	: _rawBit(0)
{
}

Fixed::Fixed(const int intVal)
	: _rawBit(0)
{
	if (maxIntInput < intVal || intVal < minIntInput)
		throw std::overflow_error("Fixed int constructor overflow");
	this->_rawBit = intVal * bitShift;
}

Fixed::Fixed(const float floatVal)
	: _rawBit(0)
{
	if (floatVal != floatVal)
		throw std::invalid_argument("NaN argument passed");
	if (floatVal == std::numeric_limits<float>::infinity() ||
		floatVal == -std::numeric_limits<float>::infinity())
		throw std::overflow_error("Fixed float constructor overflow");
	if (maxFloatInput < floatVal || floatVal < minFloatInput)
		throw std::overflow_error("Fixed float constructor overflow");
	this->_rawBit = static_cast<int>(roundf(floatVal * bitShift));
}

Fixed::Fixed(const Fixed& src)
{
	*this = src;
}

Fixed::~Fixed()
{
}

Fixed&	Fixed::operator=(const Fixed& src)
{
	if (this != &src)
		this->_rawBit = src.getRawBits();
	return (*this);
}

bool	Fixed::operator==(const Fixed& target) const
{
	if (this->_rawBit == target._rawBit)
		return true;
	else
		return false;
}

bool	Fixed::operator!=(const Fixed& target) const
{
	if (this->_rawBit != target._rawBit)
		return true;
	else
		return false;
}

bool	Fixed::operator>(const Fixed& target) const
{
	if (this->_rawBit > target._rawBit)
		return true;
	else
		return false;
}

bool	Fixed::operator<(const Fixed& target) const
{
	if (this->_rawBit < target._rawBit)
		return true;
	else
		return false;
}

bool	Fixed::operator>=(const Fixed& target) const
{
	if (this->_rawBit >= target._rawBit)
		return true;
	else
		return false;
}

bool	Fixed::operator<=(const Fixed& target) const
{
	if (this->_rawBit <= target._rawBit)
		return true;
	else
		return false;
}

Fixed	Fixed::operator+(const Fixed& add) const
{
	if (willAddOverFlow(this->_rawBit, add.getRawBits()))
		throw std::overflow_error("Fixed Addition overflow");
	Fixed	result;
	result.setRawBits(this->_rawBit + add.getRawBits());
	return result;
}

Fixed	Fixed::operator-(const Fixed& subtract) const
{
	if (subtract.getRawBits() == std::numeric_limits<int>::min())
		throw std::overflow_error("Fixed subtraction overflow");
	if (willAddOverFlow(this->_rawBit, -subtract.getRawBits()))
		throw std::overflow_error("Fixed subtraction overflow");
	Fixed	result;

	result._rawBit = this->_rawBit - subtract._rawBit;
	return result;
}

Fixed	Fixed::operator*(const Fixed& multiplicate) const
{
	int	left_raw = this->_rawBit;
	int right_raw = multiplicate.getRawBits();
	int	intPartOfLeft = left_raw / bitShift;
	int	fractPartOfLeft = left_raw % bitShift;

	if (willMulOverFlow(intPartOfLeft, right_raw))
		throw std::overflow_error("Fixed multiplication overflow");
	int	intPartOfResult = intPartOfLeft * right_raw;
	if (willMulOverFlow(fractPartOfLeft, right_raw))
		throw std::overflow_error("Fixed multiplication overflow");
	int fractPartOfResult = (fractPartOfLeft * right_raw) / bitShift;
	if (willAddOverFlow(intPartOfResult, fractPartOfResult))
		throw std::overflow_error("Fixed multiplication overflow");
	int resultRaw = intPartOfResult + fractPartOfResult;

	Fixed	result;
	result.setRawBits(resultRaw);
	return result;
}

Fixed	Fixed::operator/(const Fixed& divide) const
{
	if (divide.getRawBits()	== 0)
		throw std::invalid_argument("Fixed division by 0");
	if (this->_rawBit == 0)
		return Fixed(0);
	if (willMulOverFlow(this->_rawBit, bitShift))
		throw std::overflow_error("Fixed division overflow");
	int numerator = this->_rawBit * bitShift;
	if (numerator == std::numeric_limits<int>::min() && divide.getRawBits() == -1)
		throw std::overflow_error("Fixed division overflow");
	int resultRaw = numerator / divide.getRawBits();
	Fixed	result;
	result.setRawBits(resultRaw);
	return result;
}

Fixed&	Fixed::operator++(void)
{
	if (willAddOverFlow(this->_rawBit, 1))
		throw std::overflow_error("Fixed increment overflow");
	this->_rawBit += 1;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	if (willAddOverFlow(this->_rawBit, 1))
		throw std::overflow_error("Fixed increment overflow");
	Fixed	copy(*this);

	this->_rawBit += 1;
	return copy;
}

Fixed&	Fixed::operator--(void)
{
	if (willAddOverFlow(this->_rawBit, -1))
		throw std::overflow_error("Fixed decrement overflow");
	this->_rawBit -= 1;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	if (willAddOverFlow(this->_rawBit, -1))
		throw std::overflow_error("Fixed decrement overflow");
	Fixed	copy(*this);

	this->_rawBit -= 1;
	return copy;
}

int		Fixed::getRawBits(void) const
{
	return (this->_rawBit);
}

void	Fixed::setRawBits(int const raw)
{
	this->_rawBit = raw;
	return ;
}

float	Fixed::toFloat(void) const
{
	float	val;

	val = static_cast<float>(this->_rawBit) / bitShift;
	return val;
}

int		Fixed::toInt(void) const
{
	int		val;

	val = this->_rawBit / bitShift;
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

static bool		willMulOverFlow(int left, int right)
{
	const int	intMax = std::numeric_limits<int>::max();
	const int	intMin = std::numeric_limits<int>::min();

	if (left == 0 || right == 0)
		return false;
	if (left == -1)
		return right == intMin;
	if (left == intMin)
		return right == -1;
	if (left > 0)
	{
		if (right > 0)
			return right > intMax / left;
		else
			return right < intMin / left;
	}
	else
	{
		if (right > 0)
			return right > intMin / left;
		else
			return right < intMax / left;
	}
}

static bool	willAddOverFlow(int left, int right)
{
	const int	intMax = std::numeric_limits<int>::max();
	const int	intMin = std::numeric_limits<int>::min();

	if (right > 0)
		return left > intMax - right;
	if (right < 0)
		return left < intMin - right;
	return false;
}
