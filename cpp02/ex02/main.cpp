/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 09:08:44 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/04/27 22:54:58 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

//subject main
int		main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}
//---testcases---
//#include <string>
//
//static void	section(const std::string& title)
//{
//	std::cout << "\n==================================================" << std::endl;
//	std::cout << title << std::endl;
//	std::cout << "==================================================" << std::endl;
//}
//
//static void	caseLine(const std::string& expr,
//					const Fixed& actual,
//					const std::string& expected)
//{
//	std::cout << "[CASE] " << expr << std::endl;
//	std::cout << "  actual   : " << actual << std::endl;
//	std::cout << "  expected : " << expected << std::endl;
//	std::cout << std::endl;
//}
//
//static void	boolLine(const std::string& expr, bool actual, bool expected)
//{
//	std::cout << "[CASE] " << expr << std::endl;
//	std::cout << "  actual   : " << (actual ? "true" : "false") << std::endl;
//	std::cout << "  expected : " << (expected ? "true" : "false") << std::endl;
//	std::cout << std::endl;
//}
//
//int	main(void)
//{
//	section("01. SUBJECT SAMPLE");
//
//	Fixed a;
//	Fixed const b(Fixed(5.05f) * Fixed(2));
//
//	caseLine("a", a, "0");
//	caseLine("++a", ++a, "0.00390625");
//	caseLine("a", a, "0.00390625");
//	caseLine("a++", a++, "0.00390625");
//	caseLine("a", a, "0.0078125");
//	caseLine("b = Fixed(5.05f) * Fixed(2)", b, "10.1016");
//	caseLine("Fixed::max(a, b)", Fixed::max(a, b), "10.1016");
//
//	section("02. COMPARISON");
//
//	Fixed x(10);
//	Fixed y(10);
//	Fixed z(20);
//
//	std::cout << "input: x=10, y=10, z=20\n" << std::endl;
//
//	boolLine("x == y", x == y, true);
//	boolLine("x != y", x != y, false);
//	boolLine("x < z", x < z, true);
//	boolLine("z > x", z > x, true);
//	boolLine("x <= y", x <= y, true);
//	boolLine("x >= y", x >= y, true);
//	boolLine("z <= x", z <= x, false);
//	boolLine("x >= z", x >= z, false);
//
//	section("03. ARITHMETIC");
//
//	Fixed p(5.5f);
//	Fixed q(2);
//
//	std::cout << "input: p=5.5, q=2\n" << std::endl;
//
//	caseLine("p + q", p + q, "7.5");
//	caseLine("p - q", p - q, "3.5");
//	caseLine("p * q", p * q, "11");
//	caseLine("p / q", p / q, "2.75");
//
//	section("04. NEGATIVE VALUES");
//
//	Fixed n1(-3.5f);
//	Fixed n2(2);
//
//	std::cout << "input: n1=-3.5, n2=2\n" << std::endl;
//
//	caseLine("n1 + n2", n1 + n2, "-1.5");
//	caseLine("n1 - n2", n1 - n2, "-5.5");
//	caseLine("n1 * n2", n1 * n2, "-7");
//	caseLine("n1 / n2", n1 / n2, "-1.75");
//
//	section("05. PREFIX / POSTFIX ++");
//
//	Fixed inc;
//
//	std::cout << "input: inc starts from 0\n" << std::endl;
//
//	caseLine("inc", inc, "0");
//	caseLine("++inc", ++inc, "0.00390625");
//	caseLine("inc after ++inc", inc, "0.00390625");
//	caseLine("inc++", inc++, "0.00390625");
//	caseLine("inc after inc++", inc, "0.0078125");
//
//	section("06. PREFIX / POSTFIX --");
//
//	Fixed dec(1);
//
//	std::cout << "input: dec starts from 1\n" << std::endl;
//
//	caseLine("dec", dec, "1");
//	caseLine("--dec", --dec, "0.996094");
//	caseLine("dec after --dec", dec, "0.996094");
//	caseLine("dec--", dec--, "0.996094");
//	caseLine("dec after dec--", dec, "0.992188");
//
//	section("07. MIN / MAX");
//
//	Fixed m1(1);
//	Fixed m2(2);
//	Fixed m3(2);
//
//	std::cout << "input: m1=1, m2=2, m3=2\n" << std::endl;
//
//	caseLine("Fixed::min(m1, m2)", Fixed::min(m1, m2), "1");
//	caseLine("Fixed::max(m1, m2)", Fixed::max(m1, m2), "2");
//	caseLine("Fixed::min(m2, m3)", Fixed::min(m2, m3), "2");
//	caseLine("Fixed::max(m2, m3)", Fixed::max(m2, m3), "2");
//
//	section("08. MIN RETURNS REFERENCE");
//
//	Fixed r1(1);
//	Fixed r2(2);
//
//	std::cout << "before: r1=" << r1 << ", r2=" << r2 << std::endl;
//	std::cout << "operation: Fixed::min(r1, r2) = Fixed(42)" << std::endl;
//
//	Fixed::min(r1, r2) = Fixed(42);
//
//	std::cout << "after : r1=" << r1 << "  expected: 42" << std::endl;
//	std::cout << "after : r2=" << r2 << "  expected: 2" << std::endl;
//
//	section("09. CONST MIN / MAX");
//
//	const Fixed c1(100);
//	const Fixed c2(200);
//
//	std::cout << "input: const c1=100, const c2=200\n" << std::endl;
//
//	caseLine("Fixed::min(c1, c2)", Fixed::min(c1, c2), "100");
//	caseLine("Fixed::max(c1, c2)", Fixed::max(c1, c2), "200");
//
//	std::cout << "// Fixed::min(c1, c2) = Fixed(999);" << std::endl;
//	std::cout << "// This should NOT compile because const overload returns const Fixed&." << std::endl;
//
//	section("10. RAW / CONVERSION");
//
//	Fixed rawTest(42.42f);
//
//	caseLine("rawTest", rawTest, "42.4219");
//	std::cout << "[CASE] rawTest.toInt()" << std::endl;
//	std::cout << "  actual   : " << rawTest.toInt() << std::endl;
//	std::cout << "  expected : 42" << std::endl;
//	std::cout << std::endl;
//
//	std::cout << "[CASE] rawTest.getRawBits()" << std::endl;
//	std::cout << "  actual   : " << rawTest.getRawBits() << std::endl;
//	std::cout << "  expected : 10860" << std::endl;
//	std::cout << std::endl;
//
//	section("11. DIVISION BY ZERO");
//
//	std::cout << "This case is intentionally commented out." << std::endl;
//	std::cout << "The subject says crashing on division by zero is acceptable." << std::endl;
//
//	//Fixed zero(0);
//	//std::cout << p / zero << std::endl;
//
//	return 0;
//}
