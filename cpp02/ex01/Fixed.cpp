/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 08:02:43 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/02 17:32:46 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
#include <cmath>
#include "Fixed.hpp"

const int	Fixed::bitShift = 1 << Fixed::fractBit;
const int	Fixed::maxIntInput = std::numeric_limits<int>::max() >> Fixed::fractBit;
const int	Fixed::minIntInput = std::numeric_limits<int>::min() >> Fixed::fractBit;
const float	Fixed::maxFloatInput = std::numeric_limits<float>::max() >> Fixed::fractBit;
const float	Fixed::minFloatInput = std::numeric_limits<float>::min() >> Fixed::fractBit;

std::ostream&	operator<<(std::ostream& os, const Fixed& src)
{
	os << src.toFloat();
	return os;
}

Fixed::Fixed()
	: _rawBit(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intVal)
	: _rawBit(0)
{
	std::cout << "Int constructor called" << std::endl;
	if (maxIntInput < intVal || intVal < minIntInput)
		throw std::overflow_error("Fixed int constructor overflow");
	this->_rawBit = intVal * bitShift;
}

Fixed::Fixed(const float floatVal)
	: _rawBit(0)
{
	std::cout << "Float constructor called" << std::endl;
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
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_rawBit = src.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
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
