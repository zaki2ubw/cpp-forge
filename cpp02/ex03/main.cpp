/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 09:08:44 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/04 11:54:18 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <string>
#include <limits>
#include <stdexcept>
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

static std::string	g_failed[256];
static int			g_failedCount = 0;

static void	addFailed(const std::string& name)
{
	if (g_failedCount < 256)
		g_failed[g_failedCount++] = name;
}

static void	section(const char* title)
{
	std::cout << "\n========== " << title << " ==========" << std::endl;
}

static void	fixedCase(const char* name, const Fixed& actual, const char* expected)
{
	std::ostringstream	oss;
	bool				ok;

	oss << actual;
	ok = (oss.str() == expected);

	std::cout << "[FIXED] " << name << std::endl;
	std::cout << "  actual   : " << oss.str() << std::endl;
	std::cout << "  expected : " << expected << std::endl;
	std::cout << "  result   : " << (ok ? "OK" : "KO") << std::endl;
	std::cout << std::endl;

	if (!ok)
		addFailed(name);
}

static void	throwCase(const char* name, void (*fn)(void), bool expectedThrow)
{
	bool	thrown = false;
	bool	ok;

	std::cout << "[THROW] " << name << std::endl;
	try
	{
		fn();
	}
	catch (const std::exception& e)
	{
		thrown = true;
		std::cout << "  caught   : " << e.what() << std::endl;
	}
	ok = (thrown == expectedThrow);
	std::cout << "  actual   : " << (thrown ? "throw" : "no throw") << std::endl;
	std::cout << "  expected : " << (expectedThrow ? "throw" : "no throw") << std::endl;
	std::cout << "  result   : " << (ok ? "OK" : "KO") << std::endl;
	std::cout << std::endl;

	if (!ok)
		addFailed(name);
}

static void	testIntCtorMax(void)
{
	Fixed x(std::numeric_limits<int>::max());
	(void)x;
}

static void	testIntCtorMin(void)
{
	Fixed x(std::numeric_limits<int>::min());
	(void)x;
}

static void	testFloatNaN(void)
{
	Fixed x(std::numeric_limits<float>::quiet_NaN());
	(void)x;
}

static void	testFloatInf(void)
{
	Fixed x(std::numeric_limits<float>::infinity());
	(void)x;
}

static void	testAddOverflow(void)
{
	Fixed a;
	Fixed b;

	a.setRawBits(std::numeric_limits<int>::max());
	b.setRawBits(1);
	(void)(a + b);
}

static void	testSubOverflow(void)
{
	Fixed a;
	Fixed b;

	a.setRawBits(0);
	b.setRawBits(std::numeric_limits<int>::min());
	(void)(a - b);
}

static void	testMulOverflow(void)
{
	Fixed a;
	Fixed b;

	a.setRawBits(std::numeric_limits<int>::max());
	b.setRawBits(512);
	(void)(a * b);
}

static void	testDivByZero(void)
{
	Fixed a(1);
	Fixed b(0);

	(void)(a / b);
}

static void	testDivOverflow(void)
{
	Fixed a;
	Fixed b;

	a.setRawBits(std::numeric_limits<int>::max());
	b.setRawBits(256);
	(void)(a / b);
}

static void	testIncOverflow(void)
{
	Fixed a;

	a.setRawBits(std::numeric_limits<int>::max());
	++a;
}

static void	testDecOverflow(void)
{
	Fixed a;

	a.setRawBits(std::numeric_limits<int>::min());
	--a;
}

static void	printPoint(const char* name, Point const& p)
{
	std::cout << name << "(" << p.getX() << ", " << p.getY() << ")";
}

static void	bspCase(const char* name,
					Point const& a,
					Point const& b,
					Point const& c,
					Point const& p,
					bool expected)
{
	bool result = bsp(a, b, c, p);
	bool ok = (result == expected);

	std::cout << "[BSP] " << name << std::endl;
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
	std::cout << "  result   : " << (ok ? "OK" : "KO") << std::endl;
	std::cout << std::endl;

	if (!ok)
		addFailed(name);
}

static void	printSummary(void)
{
	int i;

	section("FAILED TESTS");
	if (g_failedCount == 0)
	{
		std::cout << "All tests passed!" << std::endl;
		return ;
	}
	i = 0;
	while (i < g_failedCount)
	{
		std::cout << "[KO] " << g_failed[i] << std::endl;
		i++;
	}
}

int	main(void)
{
	//// ===== explicit TEST (uncomment to test) =====
	//// ===== if uncomment, must compile error! =====
	// Fixed test1 = 1;
	// Fixed test2 = 1.5f;
	// void foo(Fixed x);
	// foo(1);
	//// =============================================
	section("FIXED BASIC");

	fixedCase("Fixed(2) + Fixed(3)", Fixed(2) + Fixed(3), "5");
	fixedCase("Fixed(5) - Fixed(2)", Fixed(5) - Fixed(2), "3");
	fixedCase("Fixed(2) * Fixed(3)", Fixed(2) * Fixed(3), "6");
	fixedCase("Fixed(6) / Fixed(3)", Fixed(6) / Fixed(3), "2");
	fixedCase("Fixed(1.5f) * Fixed(1.5f)", Fixed(1.5f) * Fixed(1.5f), "2.25");
	fixedCase("Fixed(-3.5f) * Fixed(2)", Fixed(-3.5f) * Fixed(2), "-7");
	fixedCase("Fixed(-3.5f) * Fixed(-2)", Fixed(-3.5f) * Fixed(-2), "7");

	section("FIXED THROW");

	throwCase("Fixed(INT_MAX)", testIntCtorMax, true);
	throwCase("Fixed(INT_MIN)", testIntCtorMin, true);
	throwCase("Fixed(NaN)", testFloatNaN, true);
	throwCase("Fixed(inf)", testFloatInf, true);
	throwCase("raw INT_MAX + 1", testAddOverflow, true);
	throwCase("0 - raw INT_MIN", testSubOverflow, true);
	throwCase("large multiplication", testMulOverflow, true);
	throwCase("division by zero", testDivByZero, true);
	throwCase("division numerator overflow", testDivOverflow, true);
	throwCase("++ raw INT_MAX", testIncOverflow, true);
	throwCase("-- raw INT_MIN", testDecOverflow, true);

	section("BSP REVIEW TEST");

	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(0.0f, 10.0f);

	bspCase("inside center", a, b, c, Point(1.0f, 1.0f), true);
	bspCase("inside near edge", a, b, c, Point(0.1f, 0.1f), true);
	bspCase("outside far", a, b, c, Point(10.0f, 10.0f), false);
	bspCase("outside negative", a, b, c, Point(-1.0f, 1.0f), false);

	bspCase("on vertex A", a, b, c, Point(0.0f, 0.0f), false);
	bspCase("on vertex B", a, b, c, Point(10.0f, 0.0f), false);
	bspCase("on vertex C", a, b, c, Point(0.0f, 10.0f), false);
	bspCase("on edge AB", a, b, c, Point(5.0f, 0.0f), false);
	bspCase("on edge AC", a, b, c, Point(0.0f, 5.0f), false);
	bspCase("on edge BC", a, b, c, Point(5.0f, 5.0f), false);

	bspCase("inside reversed", a, c, b, Point(1.0f, 1.0f), true);
	bspCase("outside reversed", a, c, b, Point(10.0f, 10.0f), false);
	bspCase("edge reversed", a, c, b, Point(5.0f, 5.0f), false);

	Point fa(4.0f, -2.0f);
	Point fb(-4.0f, 2.0f);
	Point fc(4.5f, 1.0f);

	bspCase("float triangle inside", fa, fb, fc, Point(1.0f, 0.0f), true);
	bspCase("float triangle outside", fa, fb, fc, Point(5.0f, 5.0f), false);
	bspCase("float triangle near A outside", fa, fb, fc, Point(4.1f, -2.1f), false);

	Point da(0.0f, 0.0f);
	Point db(5.0f, 5.0f);
	Point dc(10.0f, 10.0f);

	bspCase("collapsed triangle point on line", da, db, dc, Point(3.0f, 3.0f), false);
	bspCase("collapsed triangle point off line", da, db, dc, Point(3.0f, 4.0f), false);

	printSummary();
	return 0;
}
