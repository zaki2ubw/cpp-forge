#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &target) const {
  if (target.empty())
    return;
}

namespace {

int typeDetector(const std::string &target) const {
  if (target.empty())
    return CASE_INVALID;
  size_t i = 0;
  if (!std::isdigit(target[i]) && isPrintableChar(target))
    return CASE_CHAR;
  if (target == "nan" || target == "nanf")
    return CASE_NAN;
  if (target == "-inf" || target == "+inf" || target == "-inff" ||
      target == "+inff")
    return CASE_INF;
  if (target[i] == "+" || target[i] == "-")
    ++i;
  size_t len = target.length();
  size_t num = 0;
  size_t point = 0;
  size_t prefixF = 0;
  for (; i < len; ++i) {
    if (std::isdigit(target[i]))
      ++num;
    else if (target[i] == '.')
      ++point;
    else if (i == len - 1 && target[i] == 'f')
      ++prefixF;
    else
      break;
  }
  if (num == 0)
    return CASE_INVALID;
  if (point != 1)
    return CASE_INVALID;
  if (point != 1 && prefixF != 0)
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
