#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &target) const {
  if (target.empty())
    return;
}

namespace {

int typeDetector(const std::string &target) const {
  if (target.empty())
    return CASE_INVALID;
  if (!std::isdigit(target[0]) && isPrintableChar(target))
    return CASE_CHAR;
  if (target == "nan" || target == "nanf")
    return CASE_NAN;
  if (target == "-inf" || target == "+inf" || target == "-inff" ||
      target == "+inff")
    return CASE_INF;
  size_t i = 0;
  if (target[i] == '+' || target[i] == '-') {
    ++i;
  }
  size_t len = target.length();
  for (; i < len; ++i) {
    if (target[i] == '.') {
      if (hasDot == true || i + 1 >= len)
        return CASE_INVALID;
      hasDot = true;
    } else if (target[i] == 'f') {
      if (i != len - 1 || hasDot == false)
        return CASE_INVALID;
      return CASE_FLOAT;
    } else if (!std::isdigit(target[i]))
      return CASE_INVALID;
  }
  if (hasDot == true)
    return CASE_DOUBLE;
  else
    return CASE_INT;
}

bool isPrintableChar(const std::string &target) {
  if (target.empty())
    return false;
  size_t len = target.length();
  if (len != 1)
    return false;
  unsigned char c = static_cast<unsigned char>(target[0]);
  if (std::isprint(c) == 0)
    return false;
  else
    return true;
}
} // namespace
