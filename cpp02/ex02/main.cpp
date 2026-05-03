/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 09:08:44 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/03 17:01:18 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

//subject main
int		main(void)
{
	try
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
	}
	catch (std::exception const& e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}
////Testcases
//#include <iostream>
//#include <limits>
//#include <stdexcept>
//#include "Fixed.hpp"
//
//static void section(const std::string& title)
//{
//	std::cout << "\n==================================================\n";
//	std::cout << title << "\n";
//	std::cout << "==================================================\n";
//}
//
//static Fixed raw(int n)
//{
//	Fixed f;
//	f.setRawBits(n);
//	return f;
//}
//
//static void expectRawExplain(const std::string& name, const std::string& formula,
//							 const Fixed& actual, int expectedRaw)
//{
//	if (actual.getRawBits() == expectedRaw)
//		std::cout << "[OK] " << name << "\n";
//	else
//		std::cout << "[NG] " << name << "\n";
//	std::cout << "  formula  : " << formula << "\n";
//	std::cout << "  actual   : raw=" << actual.getRawBits()
//			  << ", value=" << actual << "\n";
//	std::cout << "  expected : raw=" << expectedRaw << "\n\n";
//}
//
//static void expectThrowExplain(const std::string& name, const std::string& formula,
//							   void (*f)(void))
//{
//	try {
//		f();
//		std::cout << "[NG] " << name << "\n";
//		std::cout << "  formula  : " << formula << "\n";
//		std::cout << "  actual   : no throw\n";
//		std::cout << "  expected : throw\n\n";
//	}
//	catch (const std::exception& e) {
//		std::cout << "[OK] " << name << "\n";
//		std::cout << "  formula  : " << formula << "\n";
//		std::cout << "  actual   : threw: " << e.what() << "\n";
//		std::cout << "  expected : throw\n\n";
//	}
//}
//
//static void expectNoThrowExplain(const std::string& name, const std::string& formula,
//								 void (*f)(void))
//{
//	try {
//		f();
//		std::cout << "[OK] " << name << "\n";
//		std::cout << "  formula  : " << formula << "\n";
//		std::cout << "  actual   : no throw\n";
//		std::cout << "  expected : no throw\n\n";
//	}
//	catch (const std::exception& e) {
//		std::cout << "[NG] " << name << "\n";
//		std::cout << "  formula  : " << formula << "\n";
//		std::cout << "  actual   : threw: " << e.what() << "\n";
//		std::cout << "  expected : no throw\n\n";
//	}
//}
//
///* constructor */
//static void ctorIntMaxThrow(void) { Fixed x(std::numeric_limits<int>::max()); (void)x; }
//static void ctorIntMinThrow(void) { Fixed x(std::numeric_limits<int>::min()); (void)x; }
//static void ctorIntMaxSafe(void) { Fixed x(std::numeric_limits<int>::max() / 256); (void)x; }
//static void ctorIntMinSafe(void) { Fixed x(std::numeric_limits<int>::min() / 256); (void)x; }
//static void ctorFloatInf(void) { Fixed x(std::numeric_limits<float>::infinity()); (void)x; }
//static void ctorFloatNInf(void) { Fixed x(-std::numeric_limits<float>::infinity()); (void)x; }
//static void ctorFloatNaN(void) { Fixed x(std::numeric_limits<float>::quiet_NaN()); (void)x; }
//
///* add/sub */
//static void addMaxOverflow(void) { Fixed x = raw(std::numeric_limits<int>::max()); Fixed y = raw(1); (void)(x + y); }
//static void addMinOverflow(void) { Fixed x = raw(std::numeric_limits<int>::min()); Fixed y = raw(-1); (void)(x + y); }
//static void subMinNegationOverflow(void) { Fixed x = raw(0); Fixed y = raw(std::numeric_limits<int>::min()); (void)(x - y); }
//static void subMaxOverflow(void) { Fixed x = raw(std::numeric_limits<int>::max()); Fixed y = raw(-1); (void)(x - y); }
//
///* mul */
//static void mulHugePositiveOverflow(void) { Fixed x = raw(std::numeric_limits<int>::max()); Fixed y = raw(512); (void)(x * y); }
//static void mulHugeNegativeOverflow(void) { Fixed x = raw(std::numeric_limits<int>::min()); Fixed y = raw(-256); (void)(x * y); }
//
///* div */
//static void divByZero(void) { Fixed x(1); Fixed y; (void)(x / y); }
//static void divNumeratorOverflow(void) { Fixed x = raw(std::numeric_limits<int>::max()); Fixed y = raw(256); (void)(x / y); }
//static void divIntMinByMinusOne(void) { Fixed x = raw(std::numeric_limits<int>::min() / 256); Fixed y = raw(-1); (void)(x / y); }
//
///* inc/dec */
//static void incOverflow(void) { Fixed x = raw(std::numeric_limits<int>::max()); ++x; }
//static void decOverflow(void) { Fixed x = raw(std::numeric_limits<int>::min()); --x; }
//
//int main(void)
//{
//	section("01. CONSTRUCTOR BORDER");
//
//	expectNoThrowExplain("int max safe",
//		"Fixed(INT_MAX / 256) -> raw=(INT_MAX / 256) * 256, safe",
//		ctorIntMaxSafe);
//	expectNoThrowExplain("int min safe",
//		"Fixed(INT_MIN / 256) -> raw=(INT_MIN / 256) * 256, safe",
//		ctorIntMinSafe);
//	expectThrowExplain("int max overflow",
//		"Fixed(INT_MAX) -> INT_MAX * 256 overflows",
//		ctorIntMaxThrow);
//	expectThrowExplain("int min overflow",
//		"Fixed(INT_MIN) -> INT_MIN * 256 overflows",
//		ctorIntMinThrow);
//	expectThrowExplain("float +inf",
//		"infinity cannot be converted to finite raw",
//		ctorFloatInf);
//	expectThrowExplain("float -inf",
//		"-infinity cannot be converted to finite raw",
//		ctorFloatNInf);
//	expectThrowExplain("float NaN",
//		"NaN is not a valid numeric value",
//		ctorFloatNaN);
//
//	section("02. NORMAL RAW RESULTS");
//
//	expectRawExplain("Fixed(1) raw",
//		"1 * 256 = 256",
//		Fixed(1), 256);
//	expectRawExplain("Fixed(-1) raw",
//		"-1 * 256 = -256",
//		Fixed(-1), -256);
//	expectRawExplain("1.5 * 1.5",
//		"(384 * 384) / 256 = 576",
//		Fixed(1.5f) * Fixed(1.5f), 576);
//	expectRawExplain("6 / 3",
//		"(1536 * 256) / 768 = 512",
//		Fixed(6) / Fixed(3), 512);
//	expectRawExplain("-6 / 3",
//		"(-1536 * 256) / 768 = -512",
//		Fixed(-6) / Fixed(3), -512);
//	expectRawExplain("-6 / -3",
//		"(-1536 * 256) / -768 = 512",
//		Fixed(-6) / Fixed(-3), 512);
//	expectRawExplain("5 + -2",
//		"1280 + -512 = 768",
//		Fixed(5) + Fixed(-2), 768);
//	expectRawExplain("5 - 2",
//		"1280 - 512 = 768",
//		Fixed(5) - Fixed(2), 768);
//
//	section("03. ADD / SUB OVERFLOW");
//
//	expectThrowExplain("INT_MAX raw + 1",
//		"INT_MAX + 1 overflows int",
//		addMaxOverflow);
//	expectThrowExplain("INT_MIN raw + -1",
//		"INT_MIN - 1 overflows int",
//		addMinOverflow);
//	expectThrowExplain("0 - INT_MIN raw",
//		"0 - INT_MIN requires -INT_MIN, which overflows",
//		subMinNegationOverflow);
//	expectThrowExplain("INT_MAX raw - -1",
//		"INT_MAX - (-1) = INT_MAX + 1, overflow",
//		subMaxOverflow);
//
//	section("04. MUL OVERFLOW / EDGE");
//
//	expectThrowExplain("INT_MAX raw * 2.0",
//		"(INT_MAX * 512) / 256 exceeds int",
//		mulHugePositiveOverflow);
//	expectThrowExplain("INT_MIN raw * -1.0",
//		"(INT_MIN * -256) / 256 = -INT_MIN, overflow",
//		mulHugeNegativeOverflow);
//	expectRawExplain("INT_MIN raw * tiny -1 raw",
//		"(INT_MIN * -1) / 256 = 8388608, fits int",
//		raw(std::numeric_limits<int>::min()) * raw(-1),
//		8388608);
//
//	section("05. DIV OVERFLOW / ZERO");
//
//	expectThrowExplain("division by zero",
//		"right raw is 0",
//		divByZero);
//	expectThrowExplain("division numerator overflow",
//		"INT_MAX * 256 overflows before division",
//		divNumeratorOverflow);
//	expectThrowExplain("division INT_MIN / -1 guard",
//		"numerator == INT_MIN and divisor == -1 overflows",
//		divIntMinByMinusOne);
//
//	section("06. INC / DEC OVERFLOW");
//
//	expectThrowExplain("++INT_MAX raw",
//		"INT_MAX + 1 overflows",
//		incOverflow);
//	expectThrowExplain("--INT_MIN raw",
//		"INT_MIN - 1 overflows",
//		decOverflow);
//
//	section("07. EXPLICIT COMPILE TEST");
//
//	std::cout << "Uncomment these. They should NOT compile if constructors are explicit:\n";
//	std::cout << "// Fixed a = 1;\n";
//	std::cout << "// Fixed b = 1.5f;\n";
//	std::cout << "// void f(Fixed x); f(1);\n";
//
//	return 0;
//}
