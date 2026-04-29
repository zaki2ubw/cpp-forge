/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 09:08:44 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/04/29 18:54:11 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

static void	printPoint(const char* name, Point const& p)
{
	std::cout << name << "(" << p.getX() << ", " << p.getY() << ")";
}

static void	runTest(const char* name,
					Point const& a,
					Point const& b,
					Point const& c,
					Point const& p,
					bool expected)
{
	bool result = bsp(a, b, c, p);

	std::cout << "[TEST] " << name << std::endl;
	std::cout << "  triangle : ";
	printPoint("A", a);
	std::cout << " ";
	printPoint("B", b);
	std::cout << " ";
	printPoint("C", c);
	std::cout << std::endl;

	std::cout << "  point    : ";
	printPoint("P", p);
	std::cout << std::endl;

	std::cout << "  expected : " << (expected ? "inside" : "outside") << std::endl;
	std::cout << "  actual   : " << (result ? "inside" : "outside") << std::endl;
	std::cout << "  result   : " << (result == expected ? "OK" : "KO") << std::endl;
	std::cout << "----------------------------------------" << std::endl;
}

int	main(void)
{
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(0.0f, 10.0f);

	std::cout << "========== BSP REVIEW TEST ==========" << std::endl;

	std::cout << "\n===== BASIC RIGHT TRIANGLE =====" << std::endl;
	runTest("inside center", a, b, c, Point(1.0f, 1.0f), true);
	runTest("inside near edge", a, b, c, Point(0.1f, 0.1f), true);
	runTest("outside far", a, b, c, Point(10.0f, 10.0f), false);
	runTest("outside negative", a, b, c, Point(-1.0f, 1.0f), false);

	std::cout << "\n===== EDGE AND VERTEX MUST BE OUTSIDE =====" << std::endl;
	runTest("on vertex A", a, b, c, Point(0.0f, 0.0f), false);
	runTest("on vertex B", a, b, c, Point(10.0f, 0.0f), false);
	runTest("on vertex C", a, b, c, Point(0.0f, 10.0f), false);
	runTest("on edge AB", a, b, c, Point(5.0f, 0.0f), false);
	runTest("on edge AC", a, b, c, Point(0.0f, 5.0f), false);
	runTest("on edge BC", a, b, c, Point(5.0f, 5.0f), false);

	std::cout << "\n===== REVERSED TRIANGLE ORDER =====" << std::endl;
	runTest("inside reversed", a, c, b, Point(1.0f, 1.0f), true);
	runTest("outside reversed", a, c, b, Point(10.0f, 10.0f), false);
	runTest("edge reversed", a, c, b, Point(5.0f, 5.0f), false);

	std::cout << "\n===== FLOAT TRIANGLE =====" << std::endl;
	Point fa(4.0f, -2.0f);
	Point fb(-4.0f, 2.0f);
	Point fc(4.424242f, -0.00424242f);

	Point centroid(
		(4.0f + -4.0f + 4.424242f) / 3.0f,
		(-2.0f + 2.0f + -0.00424242f) / 3.0f
	);

	runTest("sample outside", fa, fb, fc, Point(4.2f, 3.141592f), false);
	runTest("far outside", fa, fb, fc, Point(5.0f, 5.0f), false);
	runTest("centroid inside", fa, fb, fc, centroid, true);
	runTest("near A outside", fa, fb, fc, Point(4.1f, -2.1f), false);

	std::cout << "\n===== DEGENERATE TRIANGLE =====" << std::endl;
	Point da(0.0f, 0.0f);
	Point db(5.0f, 5.0f);
	Point dc(10.0f, 10.0f);

	runTest("collapsed triangle point on line", da, db, dc, Point(3.0f, 3.0f), false);
	runTest("collapsed triangle point off line", da, db, dc, Point(3.0f, 4.0f), false);

	std::cout << "\n========== TEST FINISHED ==========" << std::endl;
	return 0;
}
