/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:36:35 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/04/29 17:58:47 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	calcSignedArea(Point const& lineStart,
							   Point const& lineEnd,
							   Point const& point);

bool			bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	zero(0);
	Fixed	area1 = calcSignedArea(a, b, point);
	Fixed	area2 = calcSignedArea(b, c, point);
	Fixed	area3 = calcSignedArea(c, a, point);

	if (area1 == zero || area2 == zero || area3 == zero)
		return false;
	else if (area1 > zero && area2 > zero && area3 > zero)
		return true;
	else if (area1 < zero && area2 < zero && area3 < zero)
		return true;
	else
		return false;
}

static Fixed	calcSignedArea(Point const& lineStart,
							   Point const& lineEnd,
							   Point const& point)
{
	Fixed	Sx = lineStart.getX();
	Fixed	Sy = lineStart.getY();
	Fixed	Ex = lineEnd.getX();
	Fixed	Ey = lineEnd.getY();
	Fixed	Px = point.getX();
	Fixed	Py = point.getY();

	return (Ex - Sx) * (Py - Sy) - (Ey - Sy) * (Px - Sx);
}
