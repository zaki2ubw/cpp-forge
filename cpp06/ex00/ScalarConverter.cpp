#include <cctype>
#include <cerrno>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <string>

#include "ScalarConverter.hpp"

namespace {

enum e_types {
  CASE_INVALID = -1,
  CASE_EMPTY,
  CASE_CHAR,
  CASE_NAN,
  CASE_NEGATIVE_INF,
  CASE_POSITIVE_INF,
  CASE_NUMBER
};

bool isPrintableNonDigit(const std::string &target) {
  if (target.empty())
    return false;
  size_t len = target.length();
  if (len != 1)
    return false;
  unsigned char c = static_cast<unsigned char>(target[0]);
  if (std::isdigit(c))
    return false;
  if (!std::isprint(c))
    return false;
  else
    return true;
}

bool isNumber(const std::string &target) {
  if (target.empty())
    return false;
  size_t i = 0;
  size_t len = target.length();
  if (target[i] == '+' || target[i] == '-') {
    if (i + 1 >= len ||
        !std::isdigit(static_cast<unsigned char>(target[i + 1])))
      return false;
    ++i;
  }
  if (!std::isdigit(static_cast<unsigned char>(target[i])))
    return false;
  bool hasDot = false;
  unsigned char c = 0;
  for (; i < len; ++i) {
    c = static_cast<unsigned char>(target[i]);
    if (c == '.') {
      if (hasDot == true || i + 1 >= len ||
          !std::isdigit(static_cast<unsigned char>(target[i + 1])))
        return false;
      hasDot = true;
    } else if (c == 'f') {
      if (i != len - 1 || hasDot == false)
        return false;
      return true;
    } else if (!std::isdigit(c))
      return false;
  }
  return true;
}

e_types classifyInput(const std::string &target) {
  if (target.empty())
    return CASE_EMPTY;
  if (isPrintableNonDigit(target))
    return CASE_CHAR;
  if (target == "nan" || target == "nanf")
    return CASE_NAN;
  if (target == "-inf" || target == "-inff")
    return CASE_NEGATIVE_INF;
  if (target == "inf" || target == "+inf" || target == "inff" ||
      target == "+inff")
    return CASE_POSITIVE_INF;
  if (isNumber(target))
    return CASE_NUMBER;
  return CASE_INVALID;
}

double normalizeNumber(const std::string &target) {
  errno = 0;
  char *end;
  const char *str = target.c_str();
  double n = std::strtod(str, &end);
  if (errno == ERANGE)
    throw std::out_of_range("Too big or too small for double");
  else if (end == str)
    throw std::invalid_argument("Input must be Number or Char");
  else if (*end != '\0') {
    // except float suffix
    if (!(*end == 'f' && end[1] == '\0'))
      throw std::invalid_argument("Input must be Number or Char");
    return n;
  } else
    return n;
}

void addDecimalPoint(std::string &target) {
  if (target.find('.') != std::string::npos)
    return;

  std::string::size_type exponent = target.find_first_of("eE");

  if (exponent == std::string::npos)
    target += ".0";
  else
    target.insert(exponent, ".0");
  return;
}

void printFloat(double n) {
  std::ostringstream oss;
  float f = static_cast<float>(n);
  oss << std::setprecision(std::numeric_limits<float>::digits10 + 1) << f;
  std::string result = oss.str();
  addDecimalPoint(result);
  std::cout << "float: " << result << "f" << std::endl;
  return;
}

void printDouble(double n) {
  std::ostringstream oss;
  double d = static_cast<double>(n);
  oss << std::setprecision(std::numeric_limits<double>::digits10) << d;
  std::string result = oss.str();
  addDecimalPoint(result);
  std::cout << "double: " << result << std::endl;
  return;
}

void printNan(void) {
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  std::cout << "float: nanf" << std::endl;
  std::cout << "double: nan" << std::endl;
  return;
}

void printPositiveInf() {
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  std::cout << "float: +inff" << std::endl;
  std::cout << "double: +inf" << std::endl;
  return;
}

void printNegativeInf() {
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  std::cout << "float: -inff" << std::endl;
  std::cout << "double: -inf" << std::endl;
  return;
}

void printError(void) {
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  std::cout << "float: impossible" << std::endl;
  std::cout << "double: impossible" << std::endl;
  return;
}

void printConvertResult(double n) {
  double truncated = 0;
  if (n < 0)
    truncated = std::ceil(n);
  else
    truncated = std::floor(n);
  // Print char
  if (truncated < std::numeric_limits<char>::min() ||
      truncated > std::numeric_limits<char>::max())
    std::cout << "char: impossible" << std::endl;
  else if (!std::isprint(static_cast<unsigned char>(truncated)))
    std::cout << "char: Non displayable" << std::endl;
  else
    std::cout << "char: '" << static_cast<char>(truncated) << "'" << std::endl;
  // Print int
  if (truncated < std::numeric_limits<int>::min() ||
      truncated > std::numeric_limits<int>::max())
    std::cout << "int: impossible" << std::endl;
  else
    std::cout << "int: " << static_cast<int>(truncated) << std::endl;
  // Print float
  if (n < -std::numeric_limits<float>::max() ||
      n > std::numeric_limits<float>::max())
    std::cout << "float: impossible" << std::endl;
  else
    printFloat(n);
  // Print double
  printDouble(n);
}

} // namespace

void ScalarConverter::convert(const std::string &target) {
  double n = 0;
  e_types type = classifyInput(target);
  switch (type) {
  case CASE_INVALID:
    printError();
    return;
  case CASE_EMPTY:
    std::cout << "Please give me input" << std::endl;
    return;
  case CASE_CHAR:
    n = static_cast<unsigned char>(target[0]);
    break;
  case CASE_NAN:
    printNan();
    return;
  case CASE_NEGATIVE_INF:
    printNegativeInf();
    return;
  case CASE_POSITIVE_INF:
    printPositiveInf();
    return;
  case CASE_NUMBER:
    try {
      n = normalizeNumber(target);
    } catch (const std::exception &e) {
      (void)e;
      printError();
      return;
    }
    break;
  default:
    std::cout << "Please give me input" << std::endl;
    return;
  }
  printConvertResult(n);
  return;
}
