/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 07:49:20 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/02 17:52:12 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{
	public :
		//Constructor&Destructor
		Fixed();
		explicit Fixed(const int intVal);
		explicit Fixed(const float floatVal);
		Fixed(const Fixed& src);
		~Fixed();

		//overlodedOperator
		Fixed&				operator=(const Fixed& src);
		bool				operator==(const Fixed& target) const;
		bool				operator!=(const Fixed& target) const;
		bool				operator>(const Fixed& target) const;
		bool				operator<(const Fixed& target) const;
		bool				operator>=(const Fixed& target) const;
		bool				operator<=(const Fixed& target) const;
		Fixed				operator+(const Fixed& add) const;
		Fixed				operator-(const Fixed& subtract) const;
		Fixed				operator*(const Fixed& multiplicate) const ;
		Fixed				operator/(const Fixed& divide) const;
		Fixed&				operator++(void);
		Fixed				operator++(int);
		Fixed&				operator--(void);
		Fixed				operator--(int);

		//function
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;

		//static function
		static Fixed&		min(Fixed& first, Fixed& second);
		static const Fixed&	min(const Fixed& first, const Fixed& second);
		static Fixed&		max(Fixed& first, Fixed& second);
		static const Fixed&	max(const Fixed& first, const Fixed& second);

	private :
		int					_rawBit;
		static const int	fractBit = 8;
		static const int	bitShift;
		static const int	maxIntInput;
		static const int	minIntInput;
		static const float	maxFloatInput;
		static const float	minFloatInput;
};

std::ostream&	operator<<(std::ostream& os, const Fixed& src);
