/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:29:51 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/04/29 16:32:55 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point()
	:x(0), y(0)
{
}

Point::Point(const float xVal, const float yVal)
	:x(xVal), y(yVal)
{
}

Point::Point(const Point& src)
	:x(src.getX()), y(src.getY())
{
}

Point&	Point::operator=(const Point& src)
{
	(void)src;
	return *this;
}

Point::~Point()
{
}

Fixed	Point::getX() const
{
	return this->x;
}

Fixed	Point::getY() const
{
	return this->y;
}
