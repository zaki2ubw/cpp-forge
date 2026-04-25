/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 07:49:20 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/04/25 21:26:07 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{
	public :
		Fixed();
		Fixed(const int	intVal);
		Fixed(const float floatVal);
		~Fixed();
		Fixed(const Fixed& src);
		Fixed&				operator=(const Fixed& src);
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;
	private :
		int					fixedPointValue;
		static const int	fractBit;
		static const int	bitShift;
};

std::ostream&	operator<<(std::ostream& os, const Fixed& src);
