/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:30:03 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/04/29 16:33:38 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point
{
	public :
		//Constructor&Destructor
		Point();
		Point(const float xVal, const float yVal);
		Point(const Point& src);
		~Point();

		//Operator Overlode
		Point&		operator=(const Point& src);

		//Functions
		Fixed		getX() const;
		Fixed		getY() const;

	private :
		const Fixed	x;
		const Fixed	y;
} ;
