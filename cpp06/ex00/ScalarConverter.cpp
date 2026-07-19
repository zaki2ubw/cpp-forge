#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &target) const {
  if (target.empty())
    return;
}

namespace {

bool isPrintableChar(const std::string &target) {
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

int typeDetector(const std::string &target) {
  if (target.empty())
    return CASE_INVALID;
  if (isPrintableChar(target))
    return CASE_CHAR;
  if (target == "nan" || target == "nanf")
    return CASE_NAN;
  if (target == "-inf" || target == "+inf" || target == "-inff" ||
      target == "+inff")
    return CASE_INF;
  size_t i = 0;
  size_t len = target.length();
  if (target[i] == '+' || target[i] == '-') {
    if (i + 1 >= len ||
        !std::isdigit(static_cast<unsigned char>(target[i + 1])))
      return CASE_INVALID;
    ++i;
  }
  if (!std::isdigit(static_cast<unsigned char>(target[i])))
    return CASE_INVALID;
  bool hasDot = false;
  unsigned char c = 0;
  for (; i < len; ++i) {
    c = static_cast<unsigned char>(target[i]);
    if (c == '.') {
      if (hasDot == true || i + 1 >= len ||
          !std::isdigit(static_cast<unsigned char>(target[i + 1])))
        return CASE_INVALID;
      hasDot = true;
    } else if (c == 'f') {
      if (i != len - 1 || hasDot == false)
        return CASE_INVALID;
      return CASE_FLOAT;
    } else if (!std::isdigit(c))
      return CASE_INVALID;
  }
  if (hasDot == true)
    return CASE_DOUBLE;
  else
    return CASE_INT;
}
} // namespace
