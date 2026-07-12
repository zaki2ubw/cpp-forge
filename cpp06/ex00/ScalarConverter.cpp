#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &target) const {}

int ScalarConverter::typeDetector(const std::string &target) const {
  if (target == "nan" || target == "nanf")
    return CASE_NAN;
  if (target == "-inf" || target == "+inf" || target == "-inff" ||
      target == "+inff")
    return CASE_INF;
  size_t length = target.length();
  if (length == 1 && std::isalpha(target[0]) != 0)
    return CASE_CHAR;
  if (!std::isdigit(target[i]) && target[i] != "+" && target[i] != "-")
    return CASE_INVALID;
  if (!std::isdigit(target[length - 1]) && target[i] != "f")
    return CASE_INVALID;
  for (int i = 1; i < length; ++i) {
    if (!std)
      return CASE_INVALID;
  }
  return CASE_INT;
}
}

namespace {
bool isNan(const std::string &target) {
  if (target == "nan" || target == "nanf")
    return true;
  else
    return false;
}

bool isInf(const std::string &target) {
  if (target == "-inf" || target == "+inf")
    return true;
  if (target == "-inff" || target == "+inff")
    return true;
  else
    return false;
}

bool isChar(const std::string &target) {
  if (target.length() == 1 && std::isalpha(target[0]) != 0)
    return true;
  else
    return false;
}

bool isNumber(const std::string &target) {
  if (!isdigit(target[0]) && target[0] != "+" && target[0] != "-")
    return false;
  for (size_t i = 1; i < target.length(); ++i) {
    if (!std::isdigit(target[i])) {
      if (i < len - 1) {
        if (target[i] != ".")
          return false;
        else if (std::isdigit(target[i + 1]))
          return false;
      }
      if (i == len - 1) {
        if (target[i] != "f")
          return false;
      }
    }
  }
  return true;
}

bool isInteger(const std::string &target) {
  if (!isdigit(target[0]) && target[0] != "+" && target[0] != "-")
    return false;
  for (size_t i = 1; i < target.length(); ++i) {
    if (!isdigit(target[i]))
      return false;
  }
  return true;
}

bool isSingleFloat(const std::string &target) {
        for
