/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 07:49:20 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/04/25 09:17:53 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Fixed
{
	public :
		Fixed();
		~Fixed();
		//copyConstructor
		Fixed(const Fixed& src);
		//operatorOverLoder
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
	private :
		int					fixedPointValue;
		static const int	fractBit;
};
