/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 07:49:20 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/04/27 22:16:01 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{
	public :
		//constructor/destructor
		Fixed();
		Fixed(const int	intVal);
		Fixed(const float floatVal);
		~Fixed();
		Fixed(const Fixed& src);

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
		int					fixedPointValue;
		static const int	fractBit;
		static const int	bitShift;
};

std::ostream&	operator<<(std::ostream& os, const Fixed& src);
