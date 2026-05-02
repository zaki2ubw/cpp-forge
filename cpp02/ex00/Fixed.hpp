/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 07:49:20 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/02 16:00:09 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Fixed
{
	public :
		Fixed();
		~Fixed();
		Fixed(const Fixed& src);
		Fixed&				operator=(const Fixed& src);
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
	private :
		int					_rawBit;
		static const int	fractBit;
};
