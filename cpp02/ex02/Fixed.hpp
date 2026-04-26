/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 07:49:20 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/04/26 18:22:45 by sohyamaz         ###   ########.fr       */
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
		Fixed				operator++(void);
		Fixed&				operator++(int);
		Fixed				operator--(void);
		Fixed&				operator--(int);

		//function
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
