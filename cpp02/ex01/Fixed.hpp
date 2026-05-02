/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 07:49:20 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/02 17:27:16 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <limits>

class Fixed
{
	public :
		//Constructor&Destructor
		Fixed();
		explicit Fixed(const int intVal);
		explicit Fixed(const float floatVal);
		Fixed(const Fixed& src);
		~Fixed();
		//Operator Overlode
		Fixed&				operator=(const Fixed& src);
		//Functions
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;
	private :
		int					_rawBits;
		static const int	fractBit = 8;
		static const int	bitShift;
		static const int	maxIntInput;
		static const int	minIntInput;
		static const float	maxFloatInput;
		static const float	minFloatInput;
};

std::ostream&	operator<<(std::ostream& os, const Fixed& src);
